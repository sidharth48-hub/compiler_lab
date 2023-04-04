void varcode(struct tnode *root,int r,FILE *fptr)
{
    if(root->nodetype==NODE_VARIABLE)
    {
        
        if(root->lentry!=NULL)
        {
            int binding = root->lentry->binding;
            fprintf(fptr,"MOV R%d,BP\n",r);
            fprintf(fptr,"ADD R%d,%d\n",r,binding);
            return;
        }

        struct Gsymbol *temp = Lookup(root->varname);
    
        if(temp==NULL && root->lentry==NULL)
        {
            printf("ERROR!!! Variable %s not found in declaration\n",root->varname);
            exit(1);
        }

        int binding = temp->binding;
        fprintf(fptr,"MOV R%d,%d\n",r,binding);
        return;
    }
    else if(root->nodetype==NODE_VAR_ARRAY)
    {
        struct Gsymbol *temp = Lookup(root->varname);

        if(temp==NULL)
        {
            printf("ERROR!!! Array %s not found in declaration\n",root->varname);
            exit(1);
        }

        int binding = temp->binding;

        int new_reg = codegen(root->left,fptr);//To get the index of array

        if(root->left->nodetype==NODE_VARIABLE)
        {
            fprintf(fptr,"MOV R%d,[R%d]\n",new_reg,new_reg);
        }

        fprintf(fptr,"MOV R%d,%d\n",r,binding);
        fprintf(fptr,"ADD R%d,R%d\n",r,new_reg);
        freeReg();
    }
}

int setupvariable(struct tnode *root,FILE *fptr)
{
    int new_reg = getReg();

    switch(root->nodetype)
    {
        case NODE_CONSTANT: fprintf(fptr, "MOV R%d, %d\n",new_reg,root->val);
                            break;

        case NODE_STRINGS: fprintf(fptr,"MOV R%d, %s\n",new_reg,root->varname);
                           break;
        
        case NODE_VARIABLE: varcode(root,new_reg,fptr);
                            break;

        case NODE_VAR_ARRAY: varcode(root,new_reg,fptr);
                             break;
        case NODE_FIELD_VAR: setupFieldVar(fptr,root,new_reg);
                             break;                                           
    }

    return new_reg;
}

void TypeCheckOperator(struct tnode *root)
{
    struct tnode *left = root->left;//variable 1
    struct tnode *right = root->right;//variable 2
    
    struct Typetable *left_type,*right_type;
    
    struct Gsymbol *temp1,*temp2;
    switch(left->nodetype)
    {
        case NODE_STRINGS:left_type = stringType;
                          break;
        case NODE_CONSTANT:left_type = intType;
                           break;
        case NODE_VARIABLE:if(left->lentry!=NULL)
                           {
                              left_type = left->lentry->type;
                           }
                           else
                           {
                              struct Gsymbol *temp = Lookup(left->varname);
                              left_type = temp->type;
                           }
                           break;
        case NODE_VAR_ARRAY:temp1 = Lookup(left->varname);
                            left_type = temp1->type;
                            break;
        case NODE_VAR_FUNC_CALL:temp2 = Lookup(left->varname);
                               left_type = temp2->type;
                               break;
        case NODE_FIELD: findTypeField(root);
                         left_type = Field_head;
                         break;
        case NODE_VAR_NULL: printf("Error!! NULL not allowed on the left side of the conditions\n");
                            exit(1);
        case NODE_ALLOC: printf("Error!!! alloc not available as a conditional operator\n");
                         exit(1);
        case NODE_FREE: printf("Error!!! Free not available as a conditional operator\n");
                        exit(1);
        case NODE_INITIALIZE: printf("Error!!! Initialize not available as a conditional operator\n");
                              exit(1);                                      
        default: left_type = root->type;
                             break;                                                                                                   
    }

    switch(right->nodetype)
    {
        case NODE_STRINGS:right_type = stringType;
                          break;
        case NODE_CONSTANT:right_type = intType;
                           break;
        case NODE_VARIABLE:if(right->lentry!=NULL)
                           {
                              right_type = right->lentry->type;
                           }
                           else
                           {
                              struct Gsymbol *temp = Lookup(right->varname);
                              right_type = temp->type;
                           }
                           break;
        case NODE_VAR_ARRAY:temp1 = Lookup(right->varname);
                            right_type = temp1->type;
                            break;
        case NODE_VAR_FUNC_CALL:temp2 = Lookup(right->varname);
                               right_type = temp2->type;
                               break;
        case NODE_FIELD: findTypeField(root);
                         right_type = Field_head;
                         break;
        case NODE_VAR_NULL: if(root->nodetype!=NODE_EQ && root->nodetype!=NODE_NE)
                            {
                                printf("%s %s %s\n",left->varname,root->varname,right->varname);
                                printf("Error!!! NULL not allowed on the condition\n");
                                exit(1);
                            }
                            right_type = left_type;
                            break;

        case NODE_ALLOC: printf("Error!!! alloc not available as a conditional operator\n");
                         exit(1);
        case NODE_FREE: printf("Error!!! Free not available as a conditional operator\n");
                        exit(1);
        case NODE_INITIALIZE: printf("Error!!! Initialize not available as a conditional operator\n");
                              exit(1);                                        
        default: right_type = root->type;
                             break;                                                                                                   
    }

    if(root->nodetype==NODE_EQ || root->nodetype==NODE_NE)
    {
        if(left_type!=right_type)
        {
            printf("Error!!! type of operands is different at operator %s\n",root->varname);
            exit(1);
        }
    }
    else if(root->nodetype==NODE_AND || root->nodetype==NODE_OR)
    {
        if(left_type!=boolType || right_type!=boolType)
        {
           printf("Error!!! type of operands is different at operator %s\n",root->varname);
           exit(1); 
        }
    }
    else
    {
        if(left_type!=intType || right_type!=intType)
        {
           printf("Error!!! type of operands is different at operator %s\n",root->varname);
           exit(1); 
        }
    }
}

void callop_or(int l,int r,FILE *fptr)
{
    int new_reg = getReg();
    fprintf(fptr,"ADD R%d,R%d\n",l,r); //adding two boolean values
    fprintf(fptr,"MOV R%d,R%d\n",new_reg,l); //moving the added value to a new_reg
    
    int new_reg2 = getReg();
    fprintf(fptr,"MOV R%d,%d\n",new_reg2,2);

    fprintf(fptr,"EQ R%d,R%d\n",l,new_reg2); //checking equality of added value to 2

    int op_label1 = getLabel();
    int op_label2 = getLabel();

    fprintf(fptr,"JZ R%d,L%d\n",l,op_label1); //if value!=2 then jump to op_label1
    
    fprintf(fptr,"MOV R%d,%d\n",l,1); //storing 1 as result
    fprintf(fptr,"JMP L%d\n",op_label2);//jump to op_label2
    
    fprintf(fptr,"L%d:\n",op_label1);
    fprintf(fptr,"MOV R%d,R%d\n",l,new_reg);//storing added value to result
    
    fprintf(fptr,"L%d:\n",op_label2);

    freeReg();
    freeReg();
}

int call_not(struct tnode *root,int r,FILE *fptr)
{

    if(root->right->type!=boolType)
    {
        printf("Error!!!! Not a boolean value for operator in NOT\n");
        exit(1);
    }

    fprintf(fptr,"EQ R%d,%d\n",r,1); //checking equality of value to 1

    int op_label1 = getLabel();
    int op_label2 = getLabel();

    fprintf(fptr,"JZ R%d,L%d\n",r,op_label1); //if value!=1 then jump to op_label1
    
    fprintf(fptr,"MOV R%d,%d\n",r,0); //storing 1 as result
    fprintf(fptr,"JMP L%d\n",op_label2);//jump to op_label2
    
    fprintf(fptr,"L%d:\n",op_label1);
    fprintf(fptr,"MOV R%d,%d\n",r,1);//storing added value to result
    
    fprintf(fptr,"L%d:\n",op_label2);

    return r;
}

int setupoperator(struct tnode *root,int l,int r,FILE *fptr)
{
    
    TypeCheckOperator(root);

    switch(root->left->nodetype)
    {
        case NODE_VARIABLE:
        case NODE_VAR_ARRAY:
        case NODE_FIELD: fprintf(fptr,"MOV R%d, [R%d]\n",l,l);
                          break;
    }

    switch(root->right->nodetype)
    {
        case NODE_VARIABLE:
        case NODE_VAR_ARRAY:
        case NODE_FIELD: fprintf(fptr,"MOV R%d, [R%d]\n",r,r);
                          break;
    }

    switch(root->nodetype)
    {
        case NODE_ADD: fprintf(fptr,"ADD R%d,R%d\n",l,r); 
                       break;

        case NODE_SUB: fprintf(fptr,"SUB R%d,R%d\n",l,r);
                       break;

        case NODE_MUL: fprintf(fptr,"MUL R%d,R%d\n",l,r);
                       break;
                        
        case NODE_DIV: fprintf(fptr,"DIV R%d,R%d\n",l,r);
                       break;
                        
        case NODE_MOD: fprintf(fptr,"MOD R%d,R%d\n",l,r);
                       break;
                        
        case NODE_LT: fprintf(fptr,"LT R%d,R%d\n",l,r);
                      break;
                        
        case NODE_GT: fprintf(fptr,"GT R%d,R%d\n",l,r);
                      break;
                        
        case NODE_NE: fprintf(fptr,"NE R%d,R%d\n",l,r);
                      break;
                        
        case NODE_LTE: fprintf(fptr,"LE R%d,R%d\n",l,r);
                       break;
                        
        case NODE_GTE: fprintf(fptr,"GE R%d,R%d\n",l,r);
                       break;
                        
        case NODE_EQ: fprintf(fptr,"EQ R%d,R%d\n",l,r);
                      break;

        case NODE_AND: fprintf(fptr,"MUL R%d,R%d\n",l,r);
                       break;

        case NODE_OR: callop_or(l,r,fptr);
                      break;                             
                        
    }

    freeReg();

    return l;
}