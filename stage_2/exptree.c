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

struct tnode* makeOperatorNode(char c,struct tnode *l, struct tnode *r)
{
    struct tnode *temp;
    temp = (struct tnode*)malloc(sizeof(struct tnode));
    temp->varname = malloc(sizeof(char));
    *(temp->varname)=c;
    temp->nodetype=5;//operator
    temp->left = l;
    temp->right = r;
    return temp;
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

void prefix(struct tnode *root)
{
    if(root==NULL)
    {
        return;
    }
    if(root->val != 0)
    {
        printf("%d ",root->val);
    }
    else
    {
        printf("%s ",root->varname);
    } 
    prefix(root->left);
    prefix(root->right);
       
}

void inorder(struct tnode  *t)
{
    if(t->left==NULL && t->right==NULL)
    {
        if(t->nodetype==0)
            printf("%d ",t->val);
        
        else
            printf("%c ",*(t->varname));
    }

    if(t->left!=NULL)
        inorder(t->left);

    
    
    if(t->right!=NULL)
    inorder(t->right);

    if(t->nodetype==2 || t->nodetype==3)
        printf("%s ",t->varname);
    
    if(t->nodetype==4 || t->nodetype==5)
        printf("%c ",*(t->varname));
    
}