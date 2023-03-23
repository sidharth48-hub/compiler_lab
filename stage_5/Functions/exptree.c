struct tnode* makeNumberNode(int nodetype,int n)
{
    struct tnode *temp;
    temp = (struct tnode*)malloc(sizeof(struct tnode));
    temp->val = n;
    temp->nodetype=nodetype;
    temp->varname = NULL;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

struct tnode* makeIdNode(int nodetype,char *str,struct tnode *left,struct tnode *right)
{
    struct tnode *temp;
    temp = (struct tnode*)malloc(sizeof(struct tnode));
    temp->nodetype=nodetype;
    temp->varname = str;
    temp->left = left;
    temp->right = right;
    return temp;
}

struct tnode* makeStringsNode(int nodetype,char *str)
{
    struct tnode *temp;
    temp = (struct tnode*)malloc(sizeof(struct tnode));
    temp->nodetype=nodetype;
    //temp->varname = malloc(sizeof(char));
    //*(temp->varname)=c;
    temp->varname = str;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

struct tnode* makereadNode(int nodetype,struct tnode *t)
{
    struct tnode *temp;
    temp = (struct tnode*)malloc(sizeof(struct tnode));
    temp->varname = malloc(sizeof(char));
    strcpy(temp->varname,"read");
    temp->nodetype=nodetype;
    temp->left = t;
    temp->right = NULL;
    return temp;
}

struct tnode* makewriteNode(int nodetype,struct tnode *t)
{
    struct tnode *temp;
    temp = (struct tnode*)malloc(sizeof(struct tnode));
    temp->varname = malloc(sizeof(char));
    strcpy(temp->varname,"write");
    temp->nodetype=nodetype;
    temp->left = t;
    temp->right = NULL;
    return temp;
}

struct tnode* makeConnectorNode(int nodetype,char *c,struct tnode *l, struct tnode *r)
{
    struct tnode *temp;
    temp = (struct tnode*)malloc(sizeof(struct tnode));
    temp->varname=c;
    temp->nodetype=nodetype;
    temp->left = l;
    temp->right = r;
    return temp;
}

struct tnode* makeOperatorNode(int nodetype,char *c,struct tnode *l, struct tnode *r)
{
    struct tnode *temp;
    temp = (struct tnode*)malloc(sizeof(struct tnode));
    temp->varname=c;
    temp->nodetype = nodetype;
    temp->left = l;
    temp->right = r;
    return temp;
}

struct tnode* makeMainTypeNode(int type)
{
    struct tnode *temp;
    temp = (struct tnode*)malloc(sizeof(struct tnode));
    temp->varname=NULL;
    temp->type = type;
    int nodetype;
    if(type==intType)
    {
        nodetype = NODE_INT;
    }
    else if(type==stringType)
    {
        nodetype = NODE_STRING;
    }

    temp->nodetype = nodetype;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

/// IF_BLOCK ////////
struct tnode* makeNode(char *var,struct tnode *left, struct tnode *right)
{
    struct tnode *temp;
    temp = (struct tnode*)malloc(sizeof(struct tnode));
    temp->varname = malloc(sizeof(char));
    temp->varname = var;
    temp->nodetype=NODE_IF_BLOCK;
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
    temp->nodetype=NODE_IF_BLOCK;
    temp->left=left;
    temp->right=right;
    
    return temp;

}

struct tnode* makeIfNode(int nodetype,struct tnode *E, struct tnode *Slist1, struct tnode *Slist2)
{
    struct tnode *temp;
    temp = (struct tnode*)malloc(sizeof(struct tnode));
    temp->varname = malloc(sizeof(char));
    strcpy(temp->varname,"if");
    temp->nodetype = nodetype;
    temp->left = E;
    temp->right = makeNode("then",Slist1,Slist2);
    return temp;
}

struct tnode* makeNoElseNode(int nodetype,struct tnode *left, struct tnode *right)
{
    struct tnode *temp;
    temp = (struct tnode*)malloc(sizeof(struct tnode));
    temp->varname = malloc(sizeof(char));
    strcpy(temp->varname,"if");
    temp->nodetype = nodetype;
    temp->left = left;
    temp->right = makeElseNode("then",right,makeElseNode("endif",NULL,NULL));
    return temp;
}

//////////////////////

/// WHILE_BLOCK ///////////
struct tnode* whileNode(char *var,struct tnode *left,struct tnode *right)
{
    struct tnode *temp;
    temp = (struct tnode*)malloc(sizeof(struct tnode));
    temp->varname = var;
    temp->nodetype = NODE_WHILE_BLOCK;
    temp->left = left;
    temp->right = right;
    return temp;
}

struct tnode* makeWhileNode(int nodetype,struct tnode *left, struct tnode *right)
{
    struct tnode *temp;
    temp = (struct tnode*)malloc(sizeof(struct tnode));
    temp->varname = malloc(sizeof(char));
    strcpy(temp->varname,"while");
    temp->nodetype =  nodetype;
    temp->left = left;
    temp->right = whileNode("do",right,whileNode("endwhile",NULL,NULL));
    return temp;
}

///////////////////////////
struct tnode* makebreakNode(int nodetype)
{
    struct tnode *temp;
    temp = (struct tnode*)malloc(sizeof(struct tnode));
    temp->varname = malloc(sizeof(char));
    strcpy(temp->varname,"break");
    temp->nodetype = nodetype;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

struct tnode* makecontNode(int nodetype)
{
    struct tnode *temp;
    temp = (struct tnode*)malloc(sizeof(struct tnode));
    temp->varname = malloc(sizeof(char));
    strcpy(temp->varname,"continue");
    temp->nodetype = nodetype;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}


/// DO_WHILE_BLOCK ////////////////////
struct tnode* dowhileNode(struct tnode *left)
{
    struct tnode *temp;
    temp = (struct tnode*)malloc(sizeof(struct tnode));
    temp->varname = malloc(sizeof(char));
    strcpy(temp->varname,"while");
    temp->nodetype = NODE_DOWHILE_BLOCK;
    temp->left = left;
    temp->right = NULL;
    return temp;
}

struct tnode* makedowhileNode(int nodetype,struct tnode *left, struct tnode *right)
{
    struct tnode *temp;
    temp = (struct tnode*)malloc(sizeof(struct tnode));
    temp->varname = malloc(sizeof(char));
    strcpy(temp->varname,"do");
    temp->nodetype = nodetype;
    temp->left = left;
    temp->right = dowhileNode(right);
    return temp;
}

///////////////////////////////////////

/// REP_UNTIL_BLOCK ///////////////////////////
struct tnode* repuntilNode(struct tnode *left)
{
    struct tnode *temp;
    temp = (struct tnode*)malloc(sizeof(struct tnode));
    temp->varname = malloc(sizeof(char));
    strcpy(temp->varname,"until");
    temp->nodetype = NODE_REPEAT_BLOCK;
    temp->left = left;
    temp->right = NULL;
    return temp;
}

struct tnode* makerepuntilNode(int nodetype,struct tnode *left, struct tnode *right)
{
    struct tnode *temp;
    temp = (struct tnode*)malloc(sizeof(struct tnode));
    temp->varname = malloc(sizeof(char));
    strcpy(temp->varname,"repeat");
    temp->nodetype = nodetype;
    temp->left = left;
    temp->right = repuntilNode(right);
    return temp;
}

////////////////////////////////////////////////
