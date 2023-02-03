typedef struct tnode {
    int val;        // value of a number for NUM nodes.
    int type;       // type of variable
    char* varname;  // name of a variable for ID nodes
    int nodetype;   // information about non-leaf nodes - constant-0/variable-1/read-2/write-3/connector-4/(+/*)-5 etc.
    struct tnode *left,*right;  // left and right branches
}tnode;


struct tnode* makeNumberNode(int n);

struct tnode* makeIdNode(char c);

struct tnode* makereadNode(struct tnode *t);

struct tnode* makewriteNode(struct tnode *t);

struct tnode* makeConnectorNode(char c, struct tnode *l, struct tnode *r);

struct tnode* makeOperatorNode(char c, struct tnode *l, struct tnode *r);


void postfix(struct tnode *t);

void prefix(struct tnode *t);

void inorder(struct tnode *t);

int getReg();

void freeReg();

// void callwrite(int reg, FILE *fptr);

// void callread(int reg, FILE *fptr);

int varaddress(char c);

int codeGen(struct tnode *root, FILE *fptr); 

void codegenerator(struct tnode *root);

int evaluate(struct tnode *root);

int retindex(char c);
