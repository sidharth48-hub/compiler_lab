void TypeCheckCond(struct tnode *root)
{
    struct tnode *left = root->left;//variable 1
    struct tnode *right = root->right;//variable 2
    
    int left_type,right_type;

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
        default: right_type = root->type;
                             break;                                                                                                   
    }

    if(left_type!=right_type)
    {
        printf("Error!!! Wrong Types used in If condition Block\n");
        exit(1);
    }

}

int ValidateCond(struct tnode *root,int nodetype,int label_no,FILE *fptr)
{
    if(root->type!=booltype)
    {
        printf("Error!!! Not a bool type in If condition block\n");
        exit(1);
    }
    
    int l = codegen(root,fptr);
    
    if(nodetype==NODE_DO)
    {
        fprintf(fptr,"JNZ R%d, L%d\n",l,label_no);
        return -1;
    }
    else if(nodetype==NODE_REPEAT)
    {
        fprintf(fptr,"JZ R%d, L%d\n",l,label_no);
    }
    int lno = getLabel();

    fprintf(fptr,"JZ R%d,L%d\n",l,lno);

    return lno;


}

int ifCondBlock(struct tnode* root,FILE *fptr)
{

    TypeCheckCond(root);

    int lno = ValidateCond(root,NODE_IF,0,fptr);

    return lno;
}

void ifBlock(struct tnode *root,FILE *fptr)  
{   
    struct tnode *temp = root->right;
    struct tnode *Slist1 = temp->left;

    struct tnode *Slist2 = temp->right->left;
    
    int l1 = ifCondBlock(root->left,fptr); //return label no
    
    codegen(Slist1,fptr);

    int l2 = getLabel();
    fprintf(fptr,"JMP L%d\n",l2);

    fprintf(fptr,"L%d:\n",l1);
    
    if(Slist2!=NULL)
        codegen(Slist2,fptr);

    fprintf(fptr,"L%d:\n",l2);


    ////////////////
    //Slist1
    //JMP l2
    //l1:
    //Slist2
    //l2:
    ///////////////
}

int whileCondBlock(struct tnode *root,FILE *fptr)
{
    TypeCheckCond(root);
    int lno = ValidateCond(root,NODE_WHILE,0,fptr);
    return lno;
}

void whileBlock(struct tnode *root,FILE *fptr)
{

    int looplno = getLabel();
    fprintf(fptr,"L%d:\n",looplno);
    int lno = whileCondBlock(root->left,fptr); //condition checking
    
    break_arr[break_index++] = lno;
    continue_arr[continue_index] = looplno;

    
    codegen(root->right->left,fptr);//do statement
    fprintf(fptr,"JMP L%d\n",looplno);
    fprintf(fptr,"L%d:\n",lno);
}

void doWhileCondBlock(struct tnode *root, int lno,FILE *fptr)
{
    TypeCheckCond(root);
    
    ValidateCond(root,NODE_DO,lno,fptr);
}

void doWhileBlock(struct tnode *root,FILE *fptr)
{
    int lno = getLabel();
    
    fprintf(fptr,"L%d:\n",lno);

    int break_label = getLabel();

    break_arr[break_index++] = break_label;
    continue_arr[continue_index] = lno;
    
    codegen(root->left,fptr);//do Block
    
    doWhileCondBlock(root->right->left,lno,fptr);

    fprintf(fptr,"L%d:\n",break_label);
}

void repuntilCondBlock(struct tnode *root, int lno,FILE *fptr)
{
    TypeCheckCond(root);

    ValidateCond(root,NODE_REPEAT,lno,fptr);
}

void repuntilBlock(struct tnode *root,FILE *fptr)
{
    int lno = getLabel();
    
    fprintf(fptr,"L%d:\n",lno);

    int break_label = getLabel();

    break_arr[break_index++] = break_label;
    continue_arr[continue_index] = lno;
    
    codegen(root->left,fptr);//do Block
    
    repuntilCondBlock(root->right->left,lno,fptr);
}
