struct Classtable *chead = NULL;//class table head
int fieldIndex = -1;
int flabel = -1;
int Funcpos = -1;

//////////////////////////////
struct Paramstruct* createClassParamNode(char *typename,char *name)
{
    struct Paramstruct *temp;
    temp = (struct Paramstruct*)malloc(sizeof(struct Paramstruct));
    temp->name = name;
    temp->type = TLookup(name);
    temp->next = NULL;
    return temp;
}

void Param_Install(struct Paramstruct *paramlist,char *typename,char *name)
{
    struct Paramstruct *node = createClassParamNode(typename,name);

    if(paramlist == NULL)
    {
        paramlist = node;
        return;
    }

    struct Paramstruct *temp = paramlist;

    while(temp->next!=NULL)
    {
        temp = temp->next;
    }

    temp->next = node;
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
    temp->next = NULL;
    return temp;
}

struct Classtable* CInstall(char *name, char *parent_class_name)
{
    struct Classtable *node = createClassNode(name);
    fieldindex = -1;
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

void printClasstable()
{
    struct Classtable *temp = chead;

    while(temp!=NULL)
    {
        printf("////////////////////\n");
        printf("Name:%s, Fcount:%d, Mcount:%d\n",temp->name,temp->Fieldcount,temp->Methodcount);
        printFieldlist(temp->Memberfield);
        prinf("---------------------\n");
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
    temp->Ctype = cptr;
    temp->next = NULL;
    return temp;

}

void createFieldEntry(struct Fieldlist *field, struct Fieldlist *node)
{
    if(field == NULL)
    {
        field = node;
        return;
    }

    while(field->next!=NULL)
    {
        field=field->next;
    }

    field->next = node;
}

void Class_Finstall(struct Classtable *cptr, char *typename, char *name)
{
    struct Fieldlist *field = cptr->Memberfield;
    struct Fieldlist *node = createFieldNode(cptr,char *typename, char *name);
    createFieldEntry(field,node);
    cptr->Fieldcount = fieldIndex + 1;
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

void createMemberFuncEntry(struct Memberfunclist *funclist, struct Memberfunclist *node )
{
    if(funclist == NULL)
    {
        funclist = node;
        return;
    }

    while(funclist->next!=NULL)
    {
        funclist=funclist->next;
    }

    funclist->next = node;
}

void Class_Minstall(struct Classtable *cptr,char *name, struct Typetable *type, struct Paramstruct *paramlist)
{
    struct Memberfunclist *funclist = cptr->Vfuncptr;

    struct Memberfunclist *node = createMemberFuncNode(name,type,paramlist);

    createMemberFuncEntry(funclist,node);

    cptr->Methodcount = Funcpos + 1;
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
