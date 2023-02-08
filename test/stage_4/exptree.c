///////////////////////////////////////////////////////////////
///////////////////Gsymbol Table Functions///////////////////////
////////////////////////////////////////////////////////////////

struct Gsymbol* shead = NULL;
int bind = 4095;

int getBind(int mem)
{
    int temp = bind + 1;
    bind += mem;
    return temp;
}

void Install(char *name, int type, int dim,int shape[2])
{
    struct Gsymbol* node;
    node = (struct Gsymbol*)malloc(sizeof(struct Gsymbol));
    node->name = name;
    node->type = type;
    node->dim = dim;
    node->shape = shape;
    
    int mem;
    if(shape[0]<=0)
    {
        mem = 1;
    }
    else if(shape[1]<=0)
    {
        mem = shape[0];
    }
    else
    {
        mem = shape[0]*shape[1];
    }

    node->binding = getBind(mem);

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

void GsymbolEntry(int type, struct dnode *root)
{
    if(root->nodetype==0 && root->left==NULL && root->right==NULL)
    {
         Install(root->varname,type,root->dim,root->shape);       
    }

    if(root->left!=NULL)
        GsymbolEntry(type,root->left);

    if(root->right!=NULL)
       GsymbolEntry(type,root->right);
}

void printGsymbolTable()
{
    struct Gsymbol* temp = shead;
    while(temp!=NULL)
    {
        printf("%s %d %d %d\n",temp->name,temp->type,temp->dim,temp->binding);
        temp=temp->next;
    }
}

void LinkIdTable(struct tnode *root)
{
    if(root->nodetype==1 && root->left==NULL && root->right==NULL)
    {
        root->Gentry = Lookup(root->varname);
    }

    if(root->left!=NULL)
        LinkIdTable(root->left);

    if(root->right!=NULL)
       LinkIdTable(root->right);
}

////////////////////////////////////////////////////////
///////////////////////////////////////////////////////

///////////////////////////////////////////////////
//////////////DECLARATION FUNCTIONS/////////////
////////////////////////////////////////////////

struct dnode* createDeclTree(char *c,int dim,int shape[2],int nodetype,struct dnode *left,struct dnode *right)
{
    struct dnode* temp;
    temp = (struct dnode*)malloc(sizeof(struct dnode));

    if(c!=NULL)
       temp->varname = c;
    else
       temp->varname = NULL;

    temp->dim = dim;
    temp->shape = shape;
    temp->nodetype = nodetype;
    temp->left = left;
    temp->right = right;
    return temp;
}

struct dnode* makeDataTypeNode(int type,struct dnode *left)
{
    int arr[2];
    return createDeclTree(NULL,0,arr,type,left,NULL);
}

struct dnode* makeIdNodeDecl(char *str,int dim,int shape[2])
{
    return createDeclTree(str,dim,shape,0,NULL,NULL);
}

struct dnode* makeDeclNode(struct dnode *l, struct dnode *r)
{
    int arr[2];
    return createDeclTree(".",0,arr,3,l,r);
}

void printDecl(struct dnode *t)
{  
    //printf("%d\n",t->nodetype);

    if(t->left==NULL && t->right==NULL)
    {
        if(t->nodetype==0)
            printf("%s\n",t->varname);    
    }
    
    if(t->nodetype==1)
        printf("int\n");
    else if(t->nodetype==2)
        printf("string\n");
    else if(t->nodetype==3)
        printf("%s\n",t->varname);

    if(t->left!=NULL)
        printDecl(t->left);
    
    if(t->right!=NULL)
        printDecl(t->right);
        
}
////////////////////////////////////////////
////////////////////////////////////////////


struct tnode* makeNumberNode(int n)
{
    struct tnode *temp;
    temp = (struct tnode*)malloc(sizeof(struct tnode));
    temp->val = n;
    temp->nodetype=0;//constant
    temp->varname = NULL;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

struct tnode* makeIdNode(char *str)
{
    struct tnode *temp;
    temp = (struct tnode*)malloc(sizeof(struct tnode));
    temp->nodetype=1;//variable
    temp->varname = str;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

struct tnode* makeStringsNode(char *str)
{
    struct tnode *temp;
    temp = (struct tnode*)malloc(sizeof(struct tnode));
    temp->nodetype=15;//strings
    //temp->varname = malloc(sizeof(char));
    //*(temp->varname)=c;
    temp->varname = str;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

struct tnode* makereadNode(struct tnode *t)
{
    struct tnode *temp;
    temp = (struct tnode*)malloc(sizeof(struct tnode));
    temp->varname = malloc(sizeof(char));
    strcpy(temp->varname,"read");
    temp->nodetype=2;//read
    temp->left = t;
    temp->right = NULL;
    return temp;
}

struct tnode* makewriteNode(struct tnode *t)
{
    struct tnode *temp;
    temp = (struct tnode*)malloc(sizeof(struct tnode));
    temp->varname = malloc(sizeof(char));
    strcpy(temp->varname,"write");
    temp->nodetype=3;//write
    temp->left = t;
    temp->right = NULL;
    return temp;
}

struct tnode* makeConnectorNode(char c,struct tnode *l, struct tnode *r)
{
    struct tnode *temp;
    temp = (struct tnode*)malloc(sizeof(struct tnode));
    temp->varname = malloc(sizeof(char));
    *(temp->varname)=c;
    temp->nodetype=4;//connector
    temp->left = l;
    temp->right = r;
    return temp;
}

struct tnode* makeOperatorNode(char *c,struct tnode *l, struct tnode *r)
{
    struct tnode *temp;
    temp = (struct tnode*)malloc(sizeof(struct tnode));
    temp->varname=c;
    if(c=="<=" || c==">=" || c=="!=" || c=="==")
    {
        temp->nodetype=8;
    }
    else
    {
        temp->nodetype = 5;
    }
    temp->left = l;
    temp->right = r;
    return temp;
}

struct tnode* makeNode(char *var,struct tnode *left, struct tnode *right)
{
    struct tnode *temp;
    temp = (struct tnode*)malloc(sizeof(struct tnode));
    temp->varname = malloc(sizeof(char));
    temp->varname = var;
    temp->nodetype=9;
    if(var=="then")
    {
        temp->left = left;
        temp->right = makeNode("else",right,makeNode("endif",NULL,NULL));
    }
    else if(var=="else")
    {
        temp->left = left;
        temp->right = right;
    }
    
    return temp;

}

struct tnode* makeElseNode(char *var,struct tnode *left, struct tnode *right)
{
    struct tnode *temp;
    temp = (struct tnode*)malloc(sizeof(struct tnode));
    temp->varname = malloc(sizeof(char));
    temp->varname = var;
    temp->nodetype=9;
    temp->left=left;
    temp->right=right;
    
    return temp;

}

struct tnode* makeIfNode(struct tnode *E, struct tnode *Slist1, struct tnode *Slist2)
{
    struct tnode *temp;
    temp = (struct tnode*)malloc(sizeof(struct tnode));
    temp->varname = malloc(sizeof(char));
    strcpy(temp->varname,"if");
    temp->nodetype = 6;
    temp->left = E;
    temp->right = makeNode("then",Slist1,Slist2);
    return temp;
}

struct tnode* makeNoElseNode(struct tnode *left, struct tnode *right)
{
    struct tnode *temp;
    temp = (struct tnode*)malloc(sizeof(struct tnode));
    temp->varname = malloc(sizeof(char));
    strcpy(temp->varname,"if");
    temp->nodetype = 6;
    temp->left = left;
    temp->right = makeElseNode("then",right,makeElseNode("endif",NULL,NULL));
    return temp;
}

struct tnode* whileNode(char *var,struct tnode *left,struct tnode *right)
{
    struct tnode *temp;
    temp = (struct tnode*)malloc(sizeof(struct tnode));
    temp->varname = var;
    temp->nodetype = 10;
    temp->left = left;
    temp->right = right;
    return temp;
}

struct tnode* makeWhileNode(struct tnode *left, struct tnode *right)
{
    struct tnode *temp;
    temp = (struct tnode*)malloc(sizeof(struct tnode));
    temp->varname = malloc(sizeof(char));
    strcpy(temp->varname,"while");
    temp->nodetype =  7;
    temp->left = left;
    temp->right = whileNode("do",right,whileNode("endwhile",NULL,NULL));
    return temp;
}

struct tnode* makebreakNode()
{
    struct tnode *temp;
    temp = (struct tnode*)malloc(sizeof(struct tnode));
    temp->varname = malloc(sizeof(char));
    strcpy(temp->varname,"break");
    temp->nodetype = 11;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

struct tnode* makecontNode()
{
    struct tnode *temp;
    temp = (struct tnode*)malloc(sizeof(struct tnode));
    temp->varname = malloc(sizeof(char));
    strcpy(temp->varname,"continue");
    temp->nodetype = 14;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

struct tnode* dowhileNode(struct tnode *left)
{
    struct tnode *temp;
    temp = (struct tnode*)malloc(sizeof(struct tnode));
    temp->varname = malloc(sizeof(char));
    strcpy(temp->varname,"while");
    temp->left = left;
    temp->right = NULL;
    return temp;
}

struct tnode* makedowhileNode(struct tnode *left, struct tnode *right)
{
    struct tnode *temp;
    temp = (struct tnode*)malloc(sizeof(struct tnode));
    temp->varname = malloc(sizeof(char));
    strcpy(temp->varname,"do");
    temp->nodetype = 13;
    temp->left = left;
    temp->right = dowhileNode(right);
    return temp;
}

struct tnode* repuntilNode(struct tnode *left)
{
    struct tnode *temp;
    temp = (struct tnode*)malloc(sizeof(struct tnode));
    temp->varname = malloc(sizeof(char));
    strcpy(temp->varname,"until");
    temp->left = left;
    temp->right = NULL;
    return temp;
}

struct tnode* makerepuntilNode(struct tnode *left, struct tnode *right)
{
    struct tnode *temp;
    temp = (struct tnode*)malloc(sizeof(struct tnode));
    temp->varname = malloc(sizeof(char));
    strcpy(temp->varname,"repeat");
    temp->nodetype = 12;
    temp->left = left;
    temp->right = repuntilNode(right);
    return temp;
}

void inorder(struct tnode  *t)
{
    if(t->left==NULL && t->right==NULL)
    {
        if(t->nodetype==0)
            printf("%d\n",t->val);
        
        else if(t->nodetype==1)
            printf("%s\n",t->varname);
    }

    if(t->left!=NULL)
        inorder(t->left);

    
    
    if(t->right!=NULL)
    inorder(t->right);

    if(t->nodetype==2 || t->nodetype==3 || t->nodetype==6 || t->nodetype==7 || t->nodetype==8 || t->nodetype==9 || t->nodetype==10 || t->nodetype==11 ||t->nodetype==13 || t->nodetype==15 || t->nodetype==16)
        printf("%s\n",t->varname);
    
    if(t->nodetype==4 || t->nodetype==5)
        printf("%s\n",t->varname);
    
}

void postfix(struct tnode *root)
{
    if(root==NULL)
    {
        return;
    }
    postfix(root->left);
    postfix(root->right);
    if(root->val != 0)
    {
        printf("%d ",root->val);
    }
    else
    {
        printf("%s ",root->varname);
    }    
}