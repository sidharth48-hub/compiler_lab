struct tnode* makeLeafNode(int n)
{
    struct tnode *temp;
    temp = (struct tnode*)malloc(sizeof(struct tnode));
    temp->op = NULL;
    temp->val=n;
    temp->left=NULL;
    temp->right=NULL;
    return temp;
}

struct tnode* makeOperatorNode(char c, struct tnode *l,struct tnode *r)
{
    struct tnode *temp;
    temp = (struct tnode*)malloc(sizeof(struct tnode));
    temp->op = malloc(sizeof(char));
    *(temp->op)=c;
    temp->left=l;
    temp->right=r;
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
        printf("%s ",root->op);
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
        printf("%s ",root->op);
    } 
    prefix(root->left);
    prefix(root->right);
       
}

int evaluate(struct tnode *t){
    if(t->op == NULL)
    {
        return t->val;
    }
    else{
        switch(*(t->op)){
            case '+' : return evaluate(t->left) + evaluate(t->right);
                       break;
            case '-' : return evaluate(t->left) - evaluate(t->right);
                       break;
            case '*' : return evaluate(t->left) * evaluate(t->right);
                       break;
            case '/' : return evaluate(t->left) / evaluate(t->right);
                       break;
        }
    }
}