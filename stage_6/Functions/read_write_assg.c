void callwrite(struct tnode *root,int new_reg,FILE *fptr)
{
    int r = getReg();
    fprintf(fptr,"MOV R%d ,\"Write\"\n",r);
    fprintf(fptr,"PUSH R%d\n",r);
    fprintf(fptr,"MOV R%d ,-2\n",r);
    fprintf(fptr,"PUSH R%d\n",r);
    
    if(root->left->nodetype==NODE_VARIABLE || root->left->nodetype==NODE_VAR_ARRAY)
        fprintf(fptr,"MOV R%d,[R%d]\n",new_reg,new_reg);
    
    
    fprintf(fptr,"PUSH R%d\n",new_reg);
    fprintf(fptr,"PUSH R%d\n",r);
    fprintf(fptr,"PUSH R%d\n",r);
    
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

    int r = getReg();
    fprintf(fptr,"MOV R%d ,\"Read\"\n",r);
    fprintf(fptr,"PUSH R%d\n",r);
    fprintf(fptr,"MOV R%d ,-1\n",r);
    fprintf(fptr,"PUSH R%d\n",r);
    fprintf(fptr,"PUSH R%d\n",new_reg);
    fprintf(fptr,"PUSH R%d\n",r);
    fprintf(fptr,"PUSH R%d\n",r);
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
    
    int left_type,right_type;
    
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
        default: printf("Error!!! Only variable or array allowed in left side of = operator\n");
                 exit(1);                                                                                                   
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
        default: right_type = right->type;
                             break;                                                                                                   
    }

    if(left_type!=right_type)
    {
        printf("Error!!! Wrong Types used in %s = %s\n",left->varname,right->varname);
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
        case NODE_VAR_ARRAY:fprintf(fptr,"MOV [R%d],[R%d]\n",l,r);
                            break;

        case NODE_CONSTANT:
        case NODE_STRINGS:
        case NODE_VAR_FUNC_CALL:
        default:fprintf(fptr,"MOV [R%d],R%d\n",l,r);
                break;                     
    }

    freeReg();
    freeReg();
}