void callwrite(struct tnode *root,int new_reg,FILE *fptr)
{

    fprintf(fptr,"MOV R0 ,\"Write\"\n");
    fprintf(fptr,"PUSH R0\n");
    fprintf(fptr,"MOV R0 ,-2\n");
    fprintf(fptr,"PUSH R0\n");
    
    switch(root->left->nodetype)
    {
        case NODE_VARIABLE:
        case NODE_VAR_ARRAY:
        case NODE_FIELD:fprintf(fptr,"MOV R%d,[R%d]\n",new_reg,new_reg);
                        break;
    }
    
    
    fprintf(fptr,"PUSH R%d\n",new_reg);
    fprintf(fptr,"PUSH R0\n");
    fprintf(fptr,"PUSH R0\n");
    
    freeReg();
    fprintf(fptr,"CALL 0\n");

    fprintf(fptr,"POP R0\n");
    fprintf(fptr,"POP R0\n");
    fprintf(fptr,"POP R0\n");
    fprintf(fptr,"POP R0\n");
    fprintf(fptr,"POP R0\n");

}

void callread(struct tnode *root,int new_reg,FILE *fptr)
{
    switch(root->left->nodetype)
    {
        case NODE_VARIABLE:
        case NODE_VAR_ARRAY:break;
        case NODE_CONSTANT:
        case NODE_STRINGS:
        case NODE_VAR_FUNC_CALL:
        default: printf("Error!!! parameter of read is not a variable\n");
                 exit(1);
    }

    
    fprintf(fptr,"MOV R0 ,\"Read\"\n");
    fprintf(fptr,"PUSH R0\n");
    fprintf(fptr,"MOV R0 ,-1\n");
    fprintf(fptr,"PUSH R0\n");
    fprintf(fptr,"PUSH R%d\n",new_reg);
    fprintf(fptr,"PUSH R0\n");
    fprintf(fptr,"PUSH R0\n");
    fprintf(fptr,"CALL 0\n");
    
    fprintf(fptr,"POP R0\n");//return value
    fprintf(fptr,"POP R0\n");
    fprintf(fptr,"POP R0\n");
    fprintf(fptr,"POP R0\n");
    fprintf(fptr,"POP R0\n");
    freeReg();
}

void TypeCheckAssg(struct tnode *root)
{
    struct tnode *left = root->left;//variable 1
    struct tnode *right = root->right;//variable 2
    
    struct Typetable *left_type,*right_type;
    
    struct Gsymbol *temp1,*temp2;
    switch(left->nodetype)
    {
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
        case NODE_FIELD: findTypeField(root);
                         left_type = Field_head;
                         break;                                                                           
        default: printf("Error!!! Only variable or array allowed in left side of = operator\n");
                 exit(1);                                                                                                   
    }

    switch(right->nodetype)
    {
        case NODE_STRINGS:right_type = stringType;
                          break;
        case NODE_CONSTANT:
        case NODE_INITIALIZE:right_type = intType;
                             break;
        case NODE_ALLOC: if(left_type == intType || left_type == stringType)
                         {
                            printf("Error!!! Types other other int and string is only allowed in alloc\n");
                            exit(1);
                         }
                         return;
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
        case NODE_VAR_NULL: if(left_type == intType || left_type==stringType)
                            {
                                printf("Error!! NULL passed to non user defined types\n");
                                exit(1);
                            }
                            left_type = right_type;
                            break;
        case NODE_FIELD: findTypeField(root);
                         right_type = Field_head;
                         break;                                          
        default: right_type = right->type;
                             break;                                                                                                   
    }

    if(left_type!=right_type)
    {
        printf("Error!!! Wrong Types used in %s(%s) = %s(%s)\n",left->varname,left_type->name,right->varname,right_type->name);
        exit(1);
    }
}

void callassg(struct tnode *root,int l,int r,FILE *fptr)
{
    TypeCheckAssg(root);

    struct tnode *right = root->right;

    switch(right->nodetype)
    {
        case NODE_VARIABLE:
        case NODE_FIELD: 
        case NODE_VAR_ARRAY:fprintf(fptr,"MOV [R%d],[R%d]\n",l,r);
                            break;

        case NODE_DYNAMIC:
        case NODE_CONSTANT:
        case NODE_STRINGS:
        case NODE_VAR_FUNC_CALL:
        case NODE_VAR_NULL:
        default:fprintf(fptr,"MOV [R%d],R%d\n",l,r);
                break;                     
    }

    freeReg();
    freeReg();
}