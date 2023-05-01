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



/// TYPE TABLE CREATION FUNCTIONS ///////////////////////////////////////////////////
struct Typetable *Thead = NULL;
struct Fieldlist *Fhead = NULL;
struct Typetable *intType;
struct Typetable *stringType;
struct Typetable *boolType;

int fIndex = -1;

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
    TInstall("null");
}

struct Fieldlist* Type_FieldInstall(char *typename,char *name)
{
    struct Fieldlist *node;
    node = (struct Fieldlist*)malloc(sizeof(struct Fieldlist));
    node->name = name;

    if(fIndex == 8)
    {
        printf("Error!!! More than 8 parameters in the type defintion\n");
    }
    node->fieldIndex = ++fIndex;
    node->type = TLookup(typename);
    node->next = NULL;

    
    if(Fhead==NULL)
    {
        Fhead = node;
        return Fhead;
    }

    struct Fieldlist *temp = Fhead;

    while(temp->next!=NULL)
    {
        //printf("%s, %s\n",node->type->name,node->name);
        temp = temp->next;
    }

    temp->next = node;
    return Fhead;
}

struct Typetable* TInstall(char *name)
{
    struct Typetable *temp;
    temp = (struct Typetable*)malloc(sizeof(struct Typetable));

    temp->name = name;
    temp->fields = NULL;
    temp->next = NULL;
    
    Fhead = NULL;
    fIndex = -1;
    
    struct Typetable *temp1 = Thead;

    if(temp1==NULL)
    {
        Thead = temp;
        return temp;
    }
    while(temp1->next!=NULL)
    {
        temp1 = temp1->next;
    }
    temp1->next = temp;
    return temp;
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
        printf("------------\n");
        printf("%s\n",temp->name);

        struct Fieldlist *Fhead = temp->fields;

            while(Fhead!=NULL)
            {
                printf("%s %s %d\n",Fhead->type->name,Fhead->name,Fhead->fieldIndex);
                Fhead = Fhead->next;
            }    

        temp=temp->next;
    }
}