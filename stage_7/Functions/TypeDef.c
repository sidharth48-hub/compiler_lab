///////////TYPE TABLE NODE CREATION FUNCTIONS/////////////////////////

struct tnode *makeTypeNameNode(char *name,int nodetype)
{
    struct tnode *temp;
    temp = (struct tnode*)malloc(sizeof(struct tnode));
    temp->nodetype=nodetype;
    temp->varname = name;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

struct tnode *makeTypeConnector(int nodetype,struct tnode *left,struct tnode *right)
{
    struct tnode *temp;
    temp = (struct tnode*)malloc(sizeof(struct tnode));
    temp->nodetype=nodetype;
    temp->varname = NULL;
    temp->left = left;
    temp->right = right;
    return temp;
}


/// TYPE TABLE CREATION FUNCTIONS ///////////////////////////////////////////////////
struct Typetable *Thead = NULL;
struct Fieldlist *Fhead = NULL;
struct Typetable *intType;
struct Typetable *stringType;
struct Typetable *boolType;

int fieldIndex = -1;

void TypetableCreate()
{
    struct Typetable *temp1,*temp2;
    temp1 = (struct Typetable*)malloc(sizeof(struct Typetable));

    //INTEGER ENTRY
    TInstall("int");
    intType = TLookup("int");

    //STRING ENTRY
    TInstall("string");
    stringType = TLookup("string");

    //BOOLEAN ENTRY
    TInstall("boolean");
    boolType = TLookup("boolean");

    //VOID ENTRY
    TInstall("void");
}

void FInstall(char *typename,char *varname)
{
    struct Fieldlist *temp;
    temp = (struct Fieldlist*)malloc(sizeof(struct Fieldlist));
    temp->name = varname;

    if(fieldIndex == 8)
    {
        printf("Error!!! More than 8 parameters in the type defintion\n");
    }
    temp->fieldIndex = ++fieldIndex;
    temp->type = TLookup(typename);
    temp->next = NULL;

    struct Fieldlist *temp1 = Fhead;

    if(temp1==NULL)
    {
        Fhead = temp;
        return;
    }
    while(temp1->next!=NULL)
    {
        temp1 = temp1->next;
    }

    temp1->next = temp;
}

void createFieldlist(struct tnode *root)
{
    if(root->nodetype==NODE_TYPE_FIELD)
    {
        char *typename = root->left->varname;
        char *varname = root->right->varname;

        FInstall(typename,varname);
        return;
    }
    if(root->left!=NULL)
       createFieldlist(root->left);
    if(root->right!=NULL)
       createFieldlist(root->right);
}

void TInstall(char *name)
{
    struct Typetable *temp;
    temp = (struct Typetable*)malloc(sizeof(struct Typetable));

    temp->name = name;
    temp->fields = Fhead;
    temp->next = NULL;

    struct Typetable *temp1 = Thead;

    if(temp1==NULL)
    {
        Thead = temp;
        return;
    }
    while(temp1->next!=NULL)
    {
        temp1 = temp1->next;
    }
    temp1->next = temp;
}

void TypetableEntry(struct tnode *root)
{
    if(root->nodetype==NODE_TYPEDEF)
    {
        struct tnode *user_id = root->left;
        struct tnode *fieldlist = root->right;
        
        Fhead = NULL;
        fieldIndex = -1;

        TInstall(user_id->varname);

        createFieldlist(fieldlist);
        
        struct Typetable *temp = TLookup(user_id->varname);
        temp->fields = Fhead;
        
        return;
    }

    if(root->left!=NULL)
       TypetableEntry(root->left);
    if(root->right!=NULL)
       TypetableEntry(root->right);   
}

struct Typetable *TLookup(char *name)
{
    struct Typetable *temp = Thead;
    while(temp!=NULL)
    {
        if(strcmp(temp->name,name)==0)
        {
            return temp;
        }
        temp = temp->next;
    }

    return NULL;
}

struct Fieldlist *FLookup(struct Fieldlist *root,char *name)
{
    struct Fieldlist *temp = root;

    while(temp!=NULL)
    {
        if(strcmp(temp->name,name)==0)
        {
            return temp;
        }

        temp = temp->next;
    }

    return NULL;
}

void printTypetable()
{
    struct Typetable *temp = Thead;

    while(temp!=NULL)
    {
        printf("%s\n",temp->name);

        Fhead = temp->fields;

        if(Fhead!=NULL)
        {
            while(Fhead!=NULL)
            {
                printf("%s %s %d\n",Fhead->type->name,Fhead->name,Fhead->fieldIndex);
                Fhead = Fhead->next;
            }    
        }

        temp=temp->next;
    }
}