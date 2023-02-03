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

struct tnode* makeIdNode(char c)
{
    struct tnode *temp;
    temp = (struct tnode*)malloc(sizeof(struct tnode));
    temp->val=0;
    temp->nodetype=1;//variable
    temp->varname = malloc(sizeof(char));
    *(temp->varname)=c;
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
    temp->nodetype = 11;
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
            printf("%c\n",*(t->varname));
    }

    if(t->left!=NULL)
        inorder(t->left);

    
    
    if(t->right!=NULL)
    inorder(t->right);

    if(t->nodetype==2 || t->nodetype==3 || t->nodetype==6 || t->nodetype==7 || t->nodetype==8 || t->nodetype==9 || t->nodetype==10 || t->nodetype==13)
        printf("%s\n",t->varname);
    
    if(t->nodetype==4 || t->nodetype==5)
        printf("%c\n",*(t->varname));
    
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