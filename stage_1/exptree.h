typedef struct tnode
{
    int val;
    char *op;
    struct tnode *left, *right;
}tnode;

struct tnode* makeLeafNode(int n);

struct tnode* makeOperatorNode(char c, struct tnode *l,struct tnode *r);

void postfix(struct tnode *t);

void prefix(struct tnode *t);

int codeGen(struct tnode *root, FILE *fptr); 

int evaluate(struct tnode *t);