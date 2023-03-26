////////////////Gsymbol Table Functions///////////////////////
struct Gsymbol *shead = NULL; //GLOBAL SYMBOL TABLE HEAD
struct Paramstruct *phead = NULL; //PARAMLIST HEAD
int bind = 4095;
int flabel = 0;

int getBind(int mem)
{
    int temp = bind + 1;
    bind += mem;
    return temp;
}

int getfLabel()
{
    flabel++;
}

struct Paramstruct *ParamLookup(char *name)
{
    struct Paramstruct *temp = phead;

    while(temp!=NULL)
    {
        if(strcmp(temp->name,name)==0)
        {
            return temp;
        }
        temp=temp->next;
    }
    return NULL;
}

void createParamNode(char *name,int type)
{
    struct Paramstruct* node;
    node = (struct Paramstruct*)malloc(sizeof(struct Paramstruct));
    node->name = name;
    node->type = type;

    if(phead==NULL)
    {
        phead = node;
        node->next = NULL;
        return;
    }
    struct Paramstruct* temp = phead;

    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next = node;
    node->next = NULL;
}

void createParamList(struct tnode *root)
{
    if(root->nodetype==NODE_PARAM)
    {
        if(root->left->varname!=NULL)
        {
            if(ParamLookup(root->left->varname)!=NULL)
            {
                printf("Error!!! parameters with same name in function declaration\n");
                exit(1);
            }
            createParamNode(root->left->varname,root->type);
        }        
    }
    if(root->left!=NULL)
        createParamList(root->left);

    if(root->right!=NULL)
       createParamList(root->right);
}

void Install(char *name, int type, int size,int nodetype,struct Paramstruct *paramlist)
{
    struct Gsymbol* node;
    node = (struct Gsymbol*)malloc(sizeof(struct Gsymbol));
    node->name = name;
    node->type = type;
    node->size = size;
    node->paramlist = paramlist;
    
    if(nodetype==NODE_VAR_PARAMLIST)
    {
        node->flabel = getfLabel();
    }
    
    int mem;
    if(size<=0)
    {
        mem = 1;
    }
    else if(size>0)
    {
        mem = size;
    }
    
    if(nodetype!=NODE_VAR_PARAMLIST)
    {
        node->binding = getBind(mem);
    }

    if(shead==NULL)
    {
        shead = node;
        node->next = NULL;
        return;
    }

    struct Gsymbol* temp = shead;

    while(temp->next!=NULL)
    {
        temp=temp->next;
    }

    temp->next = node;
    node->next = NULL;
}

void GsymbolEntry(int type, struct tnode *root)
{
    if(root->varname!=NULL && Lookup(root->varname)!=NULL)
    {
        printf("Error variables with same name\n");
        exit(1);
    }

    switch (root->nodetype)
    {
    case NODE_VARIABLE:Install(root->varname,type,root->size,NODE_VARIABLE,NULL); 
                       return;
    case NODE_VAR_ARRAY:Install(root->varname,type,root->size,NODE_VAR_ARRAY,NULL);
                        return;
    case NODE_VAR_PARAMLIST:phead=NULL;
                            createParamList(root->left);
                            Install(root->varname,type,root->size,NODE_VAR_PARAMLIST,phead);
                            return;
    }      

    if(root->left!=NULL)
        GsymbolEntry(type,root->left);

    if(root->right!=NULL)
       GsymbolEntry(type,root->right);
}

struct Gsymbol *Lookup(char *name)
{
    struct Gsymbol* temp = shead;

    while(temp!=NULL)
    {
        if(strcmp(temp->name,name)==0)
        {
            return temp;
        }
        temp=temp->next;
    }

    return NULL;
}

void printGsymbolTable()
{
    struct Gsymbol* temp = shead;
    while(temp!=NULL)
    {
        printf("%s %d %d\n",temp->name,temp->type,temp->binding);
        struct Paramstruct *t = temp->paramlist;
        if(t!=NULL)
        {
            while(t!=NULL)
            {
                printf("%s %d\n",t->name,t->type);
                t=t->next;
            }
        }
        temp=temp->next;
    }
}


//////////////GLOBAL DECLARATION NODE FUNCTIONS/////////////

struct tnode* createDeclTree(char *c,int size,int nodetype,struct tnode *left,struct tnode *right)
{
    struct tnode *temp;
    temp = (struct tnode*)malloc(sizeof(struct tnode));

    if(c!=NULL)
       temp->varname = c;
    else
       temp->varname = NULL;

    temp->nodetype = nodetype;
    temp->size = size;
    temp->left = left;
    temp->right = right;
    return temp;
}

struct tnode* makeDataTypeNode(int type,struct tnode *left)
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
    return createDeclTree(NULL,0,nodetype,left,NULL);
}

struct tnode* makeIdNodeDecl(int nodetype,char *str,int size,struct tnode *left)
{
    return createDeclTree(str,size,nodetype,left,NULL);
}

struct tnode* makeDeclNode(int nodetype,struct tnode *l, struct tnode *r)
{
    return createDeclTree(".",0,nodetype,l,r);
}

struct tnode* makeParamNode(int nodetype,int type, struct tnode *left)
{
    struct tnode *temp;
    temp = (struct tnode*)malloc(sizeof(struct tnode));
    temp->varname = NULL;
    temp->type=type;
    temp->nodetype = nodetype;
    temp->size = 0;
    temp->left = left;
    temp->right = NULL;
    return temp;
}

void printDecl(struct tnode *t)
{  
    switch (t->nodetype)
    {
    case NODE_VARIABLE : printf("%s\n",t->varname);
                         break;
    case NODE_CONNECTOR : printf(".\n");
                          break;
    case NODE_INT : printf("int\n");
                    break;
    case NODE_STRING : printf("string\n");
                       break;

    case NODE_VAR_ARRAY : printf("%s\n",t->varname);
                          break;
    case NODE_VAR_PARAMLIST : printf("%s\n",t->varname);
                              break; 

    case NODE_RETURN : printf("%s\n",t->varname);
                       break;                                                                                                                             
    
    default:
        break;
    }

    if(t->left!=NULL)
        printDecl(t->left);
    
    if(t->right!=NULL)
        printDecl(t->right);
        
}
////////////////////////////////////////////