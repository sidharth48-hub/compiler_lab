int reg=0;
int label = -1;
//int arr[26];
int getReg()
{
    return ++reg;
}

int getLabel()
{
    return ++label;
}

void freeReg()
{
    if(reg>=1)
        reg--;
}

void freeLabel()
{
    if(label>=0)
        label--;
}

int codegen(struct tnode *root,FILE *fptr)
{
    //printf("%d\n",root->nodetype);
    
    switch(root->nodetype)
    {
        case NODE_CONSTANT: return setupvariable(root,fptr);

        case NODE_VARIABLE: return setupvariable(root,fptr);

        case NODE_VAR_ARRAY: return setupvariable(root,fptr);

        case NODE_STRINGS: return setupvariable(root,fptr);

        case NODE_FIELD_VAR: return setupvariable(root,fptr);

        case NODE_VAR_FUNC_CALL: return function_call(root,fptr);                                              

        case NODE_IF: ifBlock(root,fptr);
                      return -1;

        case NODE_WHILE: whileBlock(root,fptr);
                         return -1;

        case NODE_DO: doWhileBlock(root,fptr);
                      return -1;

        case NODE_REPEAT: repuntilBlock(root,fptr);
                          return -1;

        case NODE_BREAK: callbreak(fptr);
                         return -1;

        case NODE_CONTINUE: callcontinue(fptr);
                            return -1;
        case NODE_BREAK_POINT: fprintf(fptr,"BRKP\n");
                               return -1;
        case NODE_ALLOC: 
        case NODE_INITIALIZE:
        case NODE_FREE: return calldynamic(fptr,root);

        case NODE_VAR_NULL: return callnull(fptr);

        case NODE_FIELD: return callfield(fptr,root);                                                                                                                                                                          
    }


    int l = codegen(root->left,fptr);

    
    switch(root->nodetype)
    {
        case NODE_READ: callread(root,l,fptr);
                        return -1;

        case NODE_WRITE: callwrite(root,l,fptr);
                         return -1;
    }

    int r = codegen(root->right,fptr);

    switch(root->nodetype)
    {
        case NODE_ASSG_EQ: callassg(root,l,r,fptr);
                           return -1;

        case NODE_NOT: return call_not(root,r,fptr);

        case NODE_ADD: 
        case NODE_SUB: 
        case NODE_MUL:
        case NODE_DIV:
        case NODE_MOD:
        case NODE_LT:
        case NODE_GT:
        case NODE_NE:
        case NODE_LTE:
        case NODE_GTE:
        case NODE_EQ: 
        case NODE_AND:
        case NODE_OR:return setupoperator(root,l,r,fptr);
                                                                                            
    }
}

void codegenerator(struct tnode *F_root,struct tnode *M_root)
{

    FILE *fptr = fopen("./exptree.o", "w");
    fprintf(fptr, "%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n",0,2056,0,0,0,0,0,0);
    fprintf(fptr,"MOV SP, %d\n",bind);
    fprintf(fptr,"MOV BP, %d\n",bind+1);

    bind++;

    //stack = createStack(100);
    
    fprintf(fptr,"CALL F0\n");
    fprintf(fptr,"INT 10\n");
    
    if(M_root==NULL)
    {
        printf("Error!!! Mainblock is not present\n");
        exit(1);
    }
    create_functions(M_root,fptr); //creates code for main function
    
    if(F_root!=NULL)
        create_functions(F_root,fptr);//creates code for functions
}