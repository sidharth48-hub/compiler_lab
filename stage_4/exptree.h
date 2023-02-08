#define booltype 0
typedef struct tnode{
    int val;        // value (for constants)
    int type;       // type of the variable
    char* varname;  // variable name (for variable nodes)
    int nodetype;   // node type - // information about non-leaf nodes at the bottom
    struct Gsymbol *Gentry; // pointer to GST entry for global variables and functions
    struct tnode *left,*right;  //left and right branches
}tnode;

typedef struct Stack {
    int break_label;
    int cont_label;
    unsigned capacity;
    int* array;
}Stack;

typedef struct dnode {
    char* varname;       // name of the variable
    int* shape;         // size of the type of the variable
    int dim;
    int nodetype;         // variable = 0, int=1 , string=2 connector = 3
    struct dnode *left,*right;
}dnode;


typedef struct Gsymbol {
    char* name;       // name of the variable
    int type;         // type of the variable int-1 , string-2
    int dim;         // size of the type of the variable
    int* shape; 
    int binding;      // stores the static memory address allocated to the variable
    struct Gsymbol *next;
}Gsymbol;


/////Decl functions////
struct dnode* createDeclTree(char *c,int dim,int shape[2],int nodetype,struct dnode *left,struct dnode *right);

struct dnode* makeDataTypeNode(int type,struct dnode *left);

struct dnode* makeIdNodeDecl(char *str,int dim,int shape[2]);

struct dnode* makeDeclNode(struct dnode *l, struct dnode *r);

////////////////////////

struct tnode* makeNumberNode(int n);

struct tnode* makeIdNode(char *str);

struct tnode* makeStringsNode(char *str);

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

struct Gsymbol *Lookup(char *name);            // Returns a pointer to the symbol table entry for the variable, returns NULL otherwise.

void Install(char *name, int type, int dim,int shape[2]);   // Creates a symbol table entry.

void GsymbolEntry(int type,struct dnode *root);

void printGsymbolTable();

void LinkIdTable(struct tnode *root);

int getReg();

void freeReg();

void callwrite(int reg,FILE *fptr);

void callread(int reg,FILE *fptr);

int varaddress(char c);

int codeGen(struct tnode *root, FILE *fptr);

void codegenerator(struct tnode *root);

int retindex(char c);

int evaluate(struct tnode *root);


//constant-0
//variable-1
//read-2
//write-3
//connector-4
//(+,*,-,/,<,>)-5
//if-6
//while-7
//<=,>=,!=-8
//then,else,endif-9
//do,endwhile -10 
//break-11
//repeatuntilloop-12
//dowhileloop-13
//continue - 14
//strings - 15
//datatype - 16