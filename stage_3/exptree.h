#define inttype 1
#define booltype 0
typedef struct tnode{
    int val;        // value (for constants)
    int type;       // type of the variable
    char* varname;  // variable name (for variable nodes)
    int nodetype;   // node type - // information about non-leaf nodes - constant-0/variable-1/read-2/write-3/connector-4/(+,*,-,/,<,>)-5/if-6/while-7/<=,>=,!=-8/then,else,endif-9/ do,endwhile -10 /break-11/repeatuntilloop-12 /dowhileloop-13/continue - 14 etc.
    struct tnode *left,*right;  //left and right branches
}tnode;

typedef struct Stack {
    int break_label;
    int cont_label;
    unsigned capacity;
    int* array;
}Stack;

struct tnode* makeNumberNode(int n);

struct tnode* makeIdNode(char c);

struct tnode* makereadNode(struct tnode *t);

struct tnode* makewriteNode(struct tnode *t);

struct tnode* makeConnectorNode(char c, struct tnode *l, struct tnode *r);

struct tnode* makeOperatorNode(char *c, struct tnode *l, struct tnode *r);

struct tnode* makeIfNode(struct tnode *E, struct tnode *Slist1, struct tnode *Slist2);

struct tnode* makeNoElseNode(struct tnode *left, struct tnode *right);

struct tnode* makeElseNode(char *var,struct tnode *left, struct tnode *right);

struct tnode* makeNode(char *var,struct tnode *left, struct tnode *right);

struct tnode* makeWhileNode(struct tnode *left, struct tnode *right);

struct tnode* whileNode(char *var,struct tnode *left,struct tnode *right);

struct tnode* makebreakNode();

struct tnode* makecontNode();

struct tnode* makedowhileNode(struct tnode *left,struct tnode *right);

struct tnode* makerepuntilNode(struct tnode *left,struct tnode *right);

int getReg();

void freeReg();

void callwrite(int reg,FILE *fptr);

void callread(int reg,FILE *fptr);

int varaddress(char c);

int codeGen(struct tnode *root, FILE *fptr);

void codegenerator(struct tnode *root);

int retindex(char c);

int evaluate(struct tnode *root);