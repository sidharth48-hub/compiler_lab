////////////////Gsymbol Table Functions///////////////////////
struct Gsymbol *shead = NULL; //GLOBAL SYMBOL TABLE HEAD
struct Paramstruct *phead = NULL; //PARAMLIST HEAD
int bind = 4095;
//int flabel;

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

void GInstall(char *name, char *type, int size,struct Paramstruct *paramlist,int nodetype)
{
    struct Gsymbol* node;
    node = (struct Gsymbol*)malloc(sizeof(struct Gsymbol));
    node->name = name;
    node->size = size;
    node->paramlist = paramlist;
    node->next = NULL;
    

    node->type = TLookup(type);
    node->classtable = Clookup(type);
    
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
        return;
    }

    struct Gsymbol* temp = shead;

    while(temp->next!=NULL)
    {
        temp=temp->next;
    }

    temp->next = node;
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
        printf("----------------\n");
        printf("%s %s %d\n",temp->name,temp->type->name,temp->binding);
        struct Paramstruct *t = temp->paramlist;
        if(t!=NULL)
        {
            while(t!=NULL)
            {
                printf("%s %s\n",t->name,t->type->name);
                t=t->next;
            }
        }
        temp=temp->next;
    }
}
