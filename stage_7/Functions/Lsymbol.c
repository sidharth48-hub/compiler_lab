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

void LInstall(char *name,char *type,int nodetype)
{
    struct Lsymbol* node;
    node = (struct Lsymbol*)malloc(sizeof(struct Lsymbol));
    node->name = name;
    node->type = TLookup(type);
    node->classtable = Clookup(type);
    
    if(nodetype==NODE_PARAM)
    {
        node->binding = getLocalBindParam();
    }
    else if(nodetype == NODE_VARIABLE)
    {
        node->binding = getLocalBindDecl();
    }
    else if(nodetype == NODE_SELF)
    {
        node->binding = getLocalBindParam();
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
        //struct Typetable *type = TLookup(root->left->varname);
        if(root->right->varname!=NULL && LLookup(root->right->varname,Lhead)!=NULL)
        {
            printf("Error!!! Local variables with same name\n");
            exit(1);
        }
        LInstall(root->right->varname,root->left->varname,root->nodetype);
    }

    if(root->left!=NULL)
        LsymbolEntryParam(root->left);
    if(root->right!=NULL)
        LsymbolEntryParam(root->right);    
}

void LsymbolEntryDeclVar(char *type,struct tnode *root)
{
    if(root->nodetype == NODE_VARIABLE)
    {
        if(root->varname!=NULL && LLookup(root->varname,Lhead)!=NULL)
        {
            printf("Error!!! Local variables with same name\n");
            exit(1);
        }
        LInstall(root->varname,type,root->nodetype);
    }

    if(root->left!=NULL)
        LsymbolEntryDeclVar(type,root->left);
    if(root->right!=NULL)
        LsymbolEntryDeclVar(type,root->right);    
} 

void LsymbolEntryDecl(struct tnode *root)
{
    if(root->nodetype==NODE_LTYPE)
    {
        //struct Typetable *type = TLookup(root->left->varname);
        LsymbolEntryDeclVar(root->left->varname,root->right);
        return;
    }

    if(root->left!=NULL)
        LsymbolEntryDecl(root->left);
    if(root->right!=NULL)
        LsymbolEntryDecl(root->right);
}

void LsymbolEntrySelf()
{
    LInstall("self",NULL,NODE_SELF);
}

struct Lsymbol* LsymbolEntry(struct tnode *paramlist,struct tnode *Ldeclblock)
{
    Lhead = NULL;
    
    LocalBind = -3;
    if(paramlist!=NULL)
        LsymbolEntryParam(paramlist)

    LsymbolEntrySelf();//entry for self        

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
    if(root->nodetype==NODE_CLASSFIELD || root->nodetype == NODE_CLASSFIELD_FUNCTION)
    {
        struct tnode *node = root;
        
        while(node->left!=NULL)
        {
            node = node->left;
        }
        
        char *name = node->varname;

        struct Lsymbol *temp = LLookup(name,Lhead);
        node->lentry = temp;
        return;
    }
    if(root->nodetype==NODE_VARIABLE)
    {
        struct Lsymbol *temp = LLookup(root->varname,Lhead);
        root->lentry = temp;
        return;
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
        printf("%s %s %d\n",temp->name,temp->type->name,temp->binding);
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

struct tnode* makeLDeclTypeNode(int nodetype,struct tnode *l,struct tnode *r)
{
    return createFuncTree(NULL,nodetype,l,r);
}

struct tnode* makeLDeclIdNode(int nodetype,char *str)
{
    return createFuncTree(str,nodetype,NULL,NULL);
}


//////////////////////////////////////////////