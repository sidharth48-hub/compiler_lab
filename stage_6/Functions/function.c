///////////FUNCTION BLOCK/////////////////
int num_of_params;
int num_of_given_params;


struct tnode* createFuncTree(char *c,int nodetype,struct tnode *left,struct tnode *right)
{
    struct tnode* temp;
    temp = (struct tnode*)malloc(sizeof(struct tnode));
    
    if(c!=NULL)
       temp->varname = c;
    else
       temp->varname = NULL;

    temp->nodetype = nodetype;
    temp->left = left;
    temp->right = right;
    return temp;
    
}

struct tnode* makeFuncConnectorNode(int nodetype,struct tnode *l,struct tnode *r)
{
    return createFuncTree(".",nodetype,l,r);
}

struct tnode* makeFuncIdNode(int nodetype,char *str,struct tnode *l,struct tnode *r)
{
    return createFuncTree(str,nodetype,l,r);
}

struct tnode* makeFuncTypeNode(int type)
{
    int nodetype;
    if(type==intType)
    {
        nodetype = NODE_INT;
    }
    else if(type==stringType)
    {
        nodetype = NODE_STRING;
    }
    return createFuncTree(NULL,nodetype,NULL,NULL);
}

struct tnode* makeReturnNode(int nodetype,struct tnode *l)
{
    struct tnode* temp;
    temp = (struct tnode*)malloc(sizeof(struct tnode));
    temp->varname = malloc(sizeof(char));
    strcpy(temp->varname,"return");
    temp->nodetype = nodetype;
    temp->left = l;
    temp->right = NULL;
    return temp;   
}

void no_of_Params(struct Paramstruct *list)
{
    while(list!=NULL)
    {
        num_of_params++;
        list=list->next;
    }
}

void no_of_given_Params(struct tnode *root)
{
    switch(root->nodetype)
    {
        case NODE_PARAM:if(root->nodetype!=NODE_CONNECTOR)
                        {
                            num_of_given_params++;
                            return;
                        }   
    }

    if(root->left!=NULL)
        no_of_given_Params(root->left);
    if(root->right!=NULL)    
        no_of_given_Params(root->right);
}

void CheckNumParams(struct tnode *paramtree,struct Paramstruct *list)
{
    if(paramtree->nodetype==NODE_PARAM)
    {
        int type=paramtree->type;
        char *name = paramtree->left->varname;
        
        if(list->type != type)
        {
            printf("Error!!! Type of paramters do not match global declaration\n");
            exit(1);
        }

        list=list->next;

    }
    
    if(paramtree->left!=NULL)
        CheckNumParams(paramtree->left,list);
    if(paramtree->right!=NULL)
        CheckNumParams(paramtree->right,list);        
}

void TypeCheckFunction(struct tnode *root)
{
    char *varname = root->varname;
    struct tnode *typenode = root->left;

    int type;

    if(typenode->nodetype==NODE_INT)
    {
        type=intType;
    }
    else if(typenode->nodetype==NODE_STRING)
    {
        type=stringType;
    }

    
    struct tnode *paramtree = root->right->left;//from function defintion
    //typechecking for main function
    if(strcmp(varname,"main")==0)
    {
        
        if(type!=intType)
        {
            printf("Error!!! Type of main function is not correct\n");
            exit(1);
        }

        if(paramtree!=NULL)
        {
            printf("Error!!! Main function has no parameters\n");
            exit(1);
        }

        return;
    }

    struct Gsymbol *func = Lookup(root->varname);
    
    ///NAME CHECKING
    if(func==NULL)
    {
        printf("Error!!! Wrong Function name declaration\n");
        exit(1);
    }
    
    ///Type checking
    if(func->type!=type)
    {
        printf("Error!!! Type of function is wrong from declaration\n");
        exit(1);
    }

    struct Paramstruct *list = func->paramlist;//from gsymbol table
    

    ///parameter checking
    if((list==NULL && paramtree!=NULL) || (list!=NULL && paramtree==NULL))
    {
        printf("Error!!! No of parameters in declared function is wrong\n");
        exit(1);
    }
    
    if(paramtree!=NULL && list!=NULL)
    {
        num_of_params = 0;
        no_of_Params(list);

        num_of_given_params = 0;
        no_of_given_Params(paramtree);

        // if(num_of_params!=num_of_given_params)
        // {
        //     printf("Error!!! No of paramters given in function %s is wrong\n",root->varname);
        //     exit(1);
        // }        
        CheckNumParams(paramtree,list);
    }
}

void TypeCheckRet(struct tnode *root,int functype)
{
    if(root->nodetype==NODE_CONSTANT)
    {
        if(intType!=functype)
        {
            printf("Error!!! return type is different\n");
            exit(1);
        }

        return;
    }

    struct Lsymbol *lentry = root->lentry;

    if(lentry!=NULL)
    {
        if(lentry->type!=functype)
        {
            printf("Error!!! return type is different\n");
            exit(1);
        }
        return;
    }


    struct Gsymbol *temp = Lookup(root->varname);

    if(temp!=NULL)
    {
        if(temp->type!=functype)
        {
            printf("Error!!! return type is different\n");
            exit(1);
        }
    }

    if(temp==NULL)
    {
        printf("Error!!! return variable %s does not exist\n",root->varname);
        exit(1);
    }
}

void push_localVar(struct tnode *root,FILE *fptr)
{
    //printf("%d\n",root->nodetype);
    if(root->nodetype==NODE_VARIABLE)
    {
        fprintf(fptr,"PUSH R0\n");
    }

    if(root->right!=NULL)
        push_localVar(root->right,fptr);
    if(root->left!=NULL)
        push_localVar(root->left,fptr);
}

void pop_localVar(struct tnode *root,FILE *fptr)
{
    if(root->nodetype==NODE_VARIABLE)
    {
        fprintf(fptr,"POP R0\n");
    }

    if(root->right!=NULL)
        pop_localVar(root->right,fptr);
    if(root->left!=NULL)
        pop_localVar(root->left,fptr);
}

void create_ret(struct tnode *root,int functype,FILE *fptr)
{
    TypeCheckRet(root,functype);
    int reg_no = codegen(root,fptr); //reg_no of variable;

    fprintf(fptr,"MOV R0,BP\n");
    fprintf(fptr,"SUB R0,%d\n",2);

    if(root->nodetype==NODE_CONSTANT)
    {
        fprintf(fptr,"MOV [R0],R%d\n",reg_no);
        return;
    }
    fprintf(fptr,"MOV [R0],[R%d]\n",reg_no);
}

void create_functions(struct tnode *root,FILE *fptr)
{
    if(root->nodetype==NODE_FUNCTION)
    {
        TypeCheckFunction(root);

        struct Gsymbol *temp = Lookup(root->varname);
        
        int f_label,functype;

        if(strcmp(root->varname,"main")==0)
        {
            f_label = 0;
            functype = intType;
        }
        else
        {
           f_label  = temp->flabel;
           functype = temp->type;
        }   
        
        struct tnode *ldecl_block = root->right->right->left;
        struct tnode *body = root->right->right->right;

        struct tnode *Slist = body->left;
        struct tnode *ret_stmt = body->right;

        fprintf(fptr,"F%d:\n",f_label);
        
        fprintf(fptr,"PUSH BP\n");
        fprintf(fptr,"MOV BP,SP\n");
        
        if(ldecl_block!=NULL)
            push_localVar(ldecl_block,fptr); //push local variables
    
        codegen(Slist,fptr); //execute body
        
        if(strcmp(root->varname,"main") != 0)
            create_ret(ret_stmt->left,functype,fptr); //store return value
        
        if(ldecl_block!=NULL)
            pop_localVar(ldecl_block,fptr);//pop local variables

        //fprintf(fptr,"POP R0\n");
        //fprintf(fptr,"MOV BP,R0\n");
        fprintf(fptr,"POP BP\n");
        fprintf(fptr,"RET\n");
    }

    if(root->left!=NULL && (root->left->nodetype==NODE_CONNECTOR || root->left->nodetype==NODE_FUNCTION))
        create_functions(root->left,fptr);
    if(root->right!=NULL && (root->right->nodetype==NODE_CONNECTOR || root->right->nodetype==NODE_FUNCTION))
        create_functions(root->right,fptr);    
}

/////////////////////////////////////////