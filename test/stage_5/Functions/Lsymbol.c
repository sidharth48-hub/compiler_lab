int LocalBind;
struct Lsymbol *Lhead; //LOCAL SYMBOL TABLE HEAD


int getLocalBindParam()
{
    return LocalBind--;
}

int getLocalBindDecl()
{
    return LocalBind++;
}

void LInstall(char *name, int type,int nodetype)
{
    struct Lsymbol* node;
    node = (struct Lsymbol*)malloc(sizeof(struct Lsymbol));
    node->name = name;
    node->type = type;
    
    if(nodetype==NODE_PARAM)
    {
        node->binding = getLocalBindParam();
    }
    else
    {
        node->binding = getLocalBindDecl();
    }

    if(Lhead==NULL)
    {
        Lhead = node;
        node->next = NULL;
        return;
    }

    struct Lsymbol* temp = Lhead;

    while(temp->next!=NULL)
    {
        temp=temp->next;
    }

    temp->next = node;
    node->next = NULL;
}

void LsymbolEntryParam(struct tnode *root)
{
    if(root->nodetype == NODE_PARAM)
    {
        LInstall(root->left->varname,root->type,root->nodetype);
    }

    if(root->left!=NULL)
        LsymbolEntryParam(root->left);
    if(root->right!=NULL)
        LsymbolEntryParam(root->right);    
}

void LsymbolEntryDeclVar(int type,struct tnode *root)
{
    if(root->nodetype == NODE_VARIABLE)
    {
        LInstall(root->varname,type,root->nodetype);
    }

    if(root->left!=NULL)
        LsymbolEntryDeclVar(type,root->left);
    if(root->right!=NULL)
        LsymbolEntryDeclVar(type,root->right);    
} 

void LsymbolEntryDecl(struct tnode *root)
{
    switch (root->nodetype)
    {
    case NODE_INT:LsymbolEntryDeclVar(intType,root->left);
                  break;
    case NODE_STRING:LsymbolEntryDeclVar(stringType,root->left);
                  break;              
    default:break;
    }

    if(root->left!=NULL)
        LsymbolEntryDecl(root->left);
    if(root->right!=NULL)
        LsymbolEntryDecl(root->right);
}

struct Lsymbol* LsymbolEntry(struct tnode *paramlist,struct tnode *Ldeclblock)
{
    Lhead = NULL;
    
    LocalBind = -3;
    if(paramlist!=NULL)
        LsymbolEntryParam(paramlist);

    LocalBind = 1;
    if(Ldeclblock!=NULL)
        LsymbolEntryDecl(Ldeclblock);

    return Lhead;
    
}

struct Lsymbol* LLookup(char *name,struct Lsymbol *Lhead)
{
    struct Lsymbol* temp = Lhead;

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

void LinkLocalTable(struct Lsymbol *Lhead,struct tnode *root)
{
    // if(root->varname!=NULL)
    //     printf("%s\n",root->varname);
    if(root->nodetype==NODE_VARIABLE)
    {
        struct Lsymbol *temp = LLookup(root->varname,Lhead);
        root->lentry = temp;
    }

    if(root->left!=NULL)
        LinkLocalTable(Lhead,root->left);
    if(root->right!=NULL)
        LinkLocalTable(Lhead,root->right);
}

void printLsymbolTable(struct Lsymbol *root)
{
    struct Lsymbol* temp = root;
    while(temp!=NULL)
    {
        printf("%s %d %d\n",temp->name,temp->type,temp->binding);
        temp=temp->next;
    }
}

void printLocalTable(struct tnode *root)
{
    if(root->nodetype==NODE_VARIABLE)
    {
        if(root->lentry!=NULL)
        {
            printf("name:%s, binding:%d\n",root->lentry->name,root->lentry->binding);
        }     
    }

    if(root->left!=NULL)
        printLocalTable(root->left);
    if(root->right!=NULL)
        printLocalTable(root->right);
}

struct Lsymbol* MsymbolEntry(struct tnode *root)
{
    Lhead = NULL;
    
    LocalBind = 1;
    LsymbolEntryDecl(root);

    return Lhead;
}


//////////LOCAL VARIABLE DECLARATION//////////

struct tnode* createLDeclTree(char *c,int nodetype,struct tnode *left,struct tnode *right)
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

struct tnode* makeLDeclConnectorNode(int nodetype,struct tnode *l,struct tnode *r)
{
    return createLDeclTree(".",nodetype,l,r);
}

struct tnode* makeLDeclTypeNode(int type,struct tnode *l)
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
    return createFuncTree(NULL,nodetype,l,NULL);
}

struct tnode* makeLDeclIdNode(int nodetype,char *str)
{
    return createFuncTree(str,nodetype,NULL,NULL);
}


//////////////////////////////////////////////