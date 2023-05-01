struct Classtable *chead = NULL;//class table head
int fieldIndex = -1;
int flabel = 0;
int Funcpos = -1;

//////////////////////////////
struct Paramstruct* createClassParamNode(char *typename,char *name)
{
    struct Paramstruct *temp;
    temp = (struct Paramstruct*)malloc(sizeof(struct Paramstruct));
    temp->name = name;
    temp->type = TLookup(typename);
    temp->next = NULL;
    return temp;
}

struct Paramstruct* Param_Install(struct Paramstruct *paramlist,char *typename,char *name)
{
    struct Paramstruct *node = createClassParamNode(typename,name);

    if(paramlist == NULL)
    {
        paramlist = node;
        return paramlist;
    }

    struct Paramstruct *temp = paramlist;

    while(temp->next!=NULL)
    {
        temp = temp->next;
    }

    temp->next = node;
    return paramlist;
}
///////////////////////////


//////////////////////////////
struct Classtable* createClassNode(char *name)
{
    struct Classtable *temp;
    temp = (struct Classtable*)malloc(sizeof(struct Classtable));
    temp->name = name;
    temp->Memberfield = NULL;
    temp->Vfuncptr = NULL;
    temp->Parentptr = NULL;
    temp->Fieldcount = 0;
    temp->Methodcount = 0;
    temp->next = NULL;
    return temp;
}

struct Classtable* CInstall(char *name, char *parent_class_name)
{
    struct Classtable *node = createClassNode(name);
    fieldIndex = -1;
    Funcpos = -1;

    if(chead == NULL)
    {
        chead = node;
        return node;
    }

    struct Classtable *temp = chead;

    while(temp->next!=NULL)
    {
        temp=temp->next;
    }

    temp->next = node;
    return node;
}

struct Classtable* Clookup(char *name)
{
    struct Classtable *temp = chead;

    while(temp!=NULL)
    {
        if(strcmp(temp->name,name) == 0)
        {
            return temp;
        }

        temp = temp->next;
    }

    return NULL;
}

void printClasstable()
{
    struct Classtable *temp = chead;

    while(temp!=NULL)
    {
        printf("////////////////////\n");
        printf("Name:%s, Fieldcount:%d, Methodcount:%d\n",temp->name,temp->Fieldcount,temp->Methodcount);
        printFieldlist(temp->Memberfield);
        printf("---------------------\n");
        printMemberfunclist(temp->Vfuncptr);
        temp=temp->next;
    }
}
////////////////////////////////


////////////////////////////////
struct Fieldlist* createFieldNode(struct Classtable *cptr,char *typename, char *name)
{
    struct Fieldlist *temp;
    temp = (struct Fieldlist*)malloc(sizeof(struct Fieldlist));
    temp->name = name;
    temp->fieldIndex = ++fieldIndex;
    temp->type = TLookup(typename);

    if(temp->type == NULL)
    {
        temp->Ctype = Clookup(typename);
    }
    else
    {
        temp->Ctype = cptr;
    }
    
    temp->next = NULL;
    return temp;

}

struct Fieldlist* createFieldEntry(struct Fieldlist *field, struct Fieldlist *node)
{
    if(field == NULL)
    {
        field = node;
        return field;
    }
    
    struct Fieldlist *temp = field;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }

    temp->next = node;
    return field;
}

void Class_Finstall(struct Classtable *cptr, char *typename, char *name)
{
    struct Fieldlist *field = cptr->Memberfield;
    struct Fieldlist *node = createFieldNode(cptr,typename, name);
    cptr->Memberfield = createFieldEntry(field,node);
    cptr->Fieldcount = fieldIndex + 1;
}

struct Fieldlist* Class_Flookup(struct Classtable *cptr, char *name)
{
    struct Fieldlist *temp = cptr->Memberfield;

    while(temp!=NULL)
    {
        if(strcmp(temp->name,name) == 0)
        {
            return temp;
        }

        temp = temp->next;
    }

    return NULL;
}

void printFieldlist(struct Fieldlist *fields)
{
    while(fields!=NULL)
    {
        printf("Field %d name: %s, type: %s, class: %s\n",fields->fieldIndex,fields->name,fields->type->name,fields->Ctype->name);
        fields = fields->next;
    }
}
////////////////////////////////


////////////////////////////////
struct Memberfunclist* createMemberFuncNode(char *name,struct Typetable *type, struct Paramstruct *paramlist) 
{
    struct Memberfunclist *temp;
    temp = (struct Memberfunclist*)malloc(sizeof(struct Memberfunclist));
    temp->name = name;
    temp->type = type;
    temp->paramlist = paramlist;
    temp->Funcposition = ++Funcpos;
    temp->Flabel = ++flabel;
    temp->next = NULL;
    return temp;
}

struct Memberfunclist* createMemberFuncEntry(struct Memberfunclist *funclist, struct Memberfunclist *node )
{
    if(funclist == NULL)
    {
        funclist = node;
        return funclist;
    }

    struct Memberfunclist *temp = funclist;

    while(temp->next!=NULL)
    {
        temp=temp->next;
    }

    temp->next = node;
    return funclist;
}

void Class_Minstall(struct Classtable *cptr,char *name, struct Typetable *type, struct Paramstruct *paramlist)
{
    struct Memberfunclist *funclist = cptr->Vfuncptr;

    struct Memberfunclist *node = createMemberFuncNode(name,type,paramlist);
    
    cptr->Vfuncptr = createMemberFuncEntry(funclist,node);

    cptr->Methodcount = Funcpos + 1;
}

struct Memberfunclist* Class_Mlookup(struct Classtable *cptr, char *name)
{
    struct Memberfunclist *temp = cptr->Vfuncptr;

    while(temp!=NULL)
    {
        if(strcmp(temp->name,name) == 0)
        {
            return temp;
        }

        temp = temp->next;
    }

    return NULL;
}

void printMemberfunclist(struct Memberfunclist *funclist)
{
    while(funclist!=NULL)
    {
        printf("Func %d name:%s, type:%s\n",funclist->Flabel,funclist->name,funclist->type->name);

        struct Paramstruct *temp = funclist->paramlist;

        while(temp!=NULL)
        {
            printf("Name:%s, type:%s\n",temp->name,temp->type->name);
            temp=temp->next;
        }

        funclist = funclist->next;
    }
}
////////////////////////////////



////////////////////////////////////
struct tnode *makeClassNewNode(int nodetype,char *name,struct tnode *left)
{
    struct tnode *temp;
    temp = (struct tnode*)malloc(sizeof(struct tnode));
    temp->nodetype=nodetype;
    temp->varname = name;
    temp->left = left;
    temp->right = NULL;
    return temp;
}

struct tnode *makeClassDeleteNode(int nodetype,char *name,struct tnode *left)
{
    struct tnode *temp;
    temp = (struct tnode*)malloc(sizeof(struct tnode));
    temp->nodetype=nodetype;
    temp->varname = name;
    temp->left = left;
    temp->right = NULL;
    return temp;
}

struct tnode *makeSelfNode(int nodetype,char *name,struct Classtable *cptr)
{
    struct tnode *temp;
    temp = (struct tnode*)malloc(sizeof(struct tnode));
    temp->nodetype=nodetype;
    temp->classtable = cptr;
    temp->varname=name;
    temp->left = left;
    temp->right = NULL;
    return temp;
}

struct tnode *makeClassFieldNode(int nodetype,char *name,struct tnode *left,struct tnode *right)
{
    struct tnode *temp;
    temp = (struct tnode*)malloc(sizeof(struct tnode));
    temp->nodetype=nodetype;
    temp->varname = name;
    temp->left = left;
    temp->right = right;
    return temp;
}

struct tnode *makeClassIdNode(int nodetype,char *name,struct tnode *left,struct tnode *right,struct Classtable *classtable)
{
    struct tnode *temp;
    temp = (struct tnode*)malloc(sizeof(struct tnode));
    temp->nodetype = nodetype;
    temp->varname = name;
    temp->left = left;
    temp->right = right;
    temp->classtable = classtable;
    return temp;
}