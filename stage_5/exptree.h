extern int bind;
extern struct Gsymbol *shead;
extern struct Lsymbol *Lhead;
extern struct Paramstruct *phead;
extern int yylineno;
extern char *yytext;
extern int reg;
extern int label;
extern int break_arr[100];
extern int continue_arr[100];
extern int break_index;
extern int continue_index;

typedef struct tnode{
    int val;        // value (for constants)
    int type;       // type of the variable
    char* varname;  // variable name (for variable nodes)
    int size;
    int nodetype;   // node type - // information about non-leaf nodes at the bottom
    struct Gsymbol *Gentry; // pointer to GST entry for global variables and functions
    struct Lsymbol *lentry;
    struct tnode *left,*right;  //left and right branches
}tnode;

typedef struct Stack {
    int break_label;
    int cont_label;
    unsigned capacity;
    int* array;
}Stack;

typedef struct Gsymbol {
    char* name;       // name of the variable
    int type;         // type of the variable int-1 , string-2
    int size; 
    int binding;      // stores the static memory address allocated to the variable
    struct Paramstruct *paramlist;
    int flabel;
    struct Gsymbol *next;
}Gsymbol;

typedef struct Lsymbol{
    char *name;
    int type;
    int binding;
    struct Lsymbol *next;
}Lsymbol;

typedef struct Paramstruct {
    char *name;
    int type;
    struct Paramstruct *next;
}Paramstruct;

/////////////////////////////////////
/////Global Decl functions////
struct tnode* createDeclTree(char *c,int size,int nodetype,struct tnode *left,struct tnode *right);

struct tnode* makeDataTypeNode(int type,struct tnode *left);

struct tnode* makeIdNodeDecl(int nodetype,char *str,int size,struct tnode *left);

struct tnode* makeDeclNode(int nodetype,struct tnode *l, struct tnode *r);

struct tnode* makeParamNode(int nodetype,int type, struct tnode *left);

void printDecl(struct tnode *t);

////////////////////////

////////Gsymbol Table functions///////////

int getBind(int mem);

int getfLabel();

struct Paramstruct *ParamLookup(char *name);

void createParamNode(char *name,int type);

void createParamList(struct tnode *root);

void Install(char *name, int type, int size,int nodetype,struct Paramstruct *paramlist);

void GsymbolEntry(int type, struct tnode *root);

struct Gsymbol *Lookup(char *name);

void printGsymbolTable();

///////////////////////////////////////////
///////////////////////////////////////////


////////////////////////////////////////
/////////Local Decl Functions/////////

struct tnode* createLDeclTree(char *c,int nodetype,struct tnode *left,struct tnode *right);

struct tnode* makeLDeclConnectorNode(int nodetype,struct tnode *l,struct tnode *r);

struct tnode* makeLDeclTypeNode(int type,struct tnode *l);

struct tnode* makeLDeclIdNode(int nodetype,char *str);

///////////////////////////////////

/// Lsymbol table functions //////////////////////

int getLocalBindParam();

int getLocalBindDecl();

void LInstall(char *name, int type,int nodetype);

void LsymbolEntryParam(struct tnode *root);

void LsymbolEntryDeclVar(int type,struct tnode *root);

void LsymbolEntryDecl(struct tnode *root);

struct Lsymbol* LsymbolEntry(struct tnode *paramlist,struct tnode *Ldeclblock);

struct Lsymbol* LLookup(char *name,struct Lsymbol *Lhead);

void LinkLocalTable(struct Lsymbol *Lhead,struct tnode *root);

void printLsymbolTable(struct Lsymbol *root);

void printLocalTable(struct tnode *root);

struct Lsymbol* MsymbolEntry(struct tnode *root);

///////////////////////////////////////////
///////////////////////////////////////////


////////////////////////////
//////Function block////////

struct tnode* createFuncTree(char *c,int nodetype,struct tnode *l,struct tnode *r);

struct tnode* makeFuncConnectorNode(int nodetype,struct tnode *l,struct tnode *r);

struct tnode* makeFuncIdNode(int nodetype,char *str,struct tnode *l,struct tnode *r);

struct tnode* makeFuncTypeNode(int type);

struct tnode* makeReturnNode(int nodetype,struct tnode *l);

void TypeCheckFunction(struct tnode *root);

void CheckNumParams(struct tnode *paramtree,struct Paramstruct *list);

void numParams(struct Paramstruct *list);

void numGivenParams(struct tnode *root);

void push_localVar(struct tnode *root,FILE *fptr);

void pop_localVar(struct tnode *root,FILE *fptr);

void TypeCheckRet(struct tnode *root,int functype);

void create_ret(struct tnode *root,int functype,FILE *fptr);

void create_functions(struct tnode *root,FILE *fptr);

/////////////////////////////
/////////////////////////////

struct tnode* makeNumberNode(int nodetype,int n);

struct tnode* makeIdNode(int nodetype,char *str,struct tnode *left, struct tnode *right);

struct tnode* makeStringsNode(int nodetype,char *str);

struct tnode* makereadNode(int nodetype,struct tnode *t);

struct tnode* makewriteNode(int nodetype,struct tnode *t);

struct tnode* makeConnectorNode(int nodetype,char *c, struct tnode *l, struct tnode *r);

struct tnode* makeOperatorNode(int nodetype,char *c, struct tnode *l, struct tnode *r);

////IF_BLOCK////////

struct tnode* makeNode(char *var,struct tnode *left, struct tnode *right);

struct tnode* makeElseNode(char *var,struct tnode *left, struct tnode *right);

struct tnode* makeIfNode(int nodetype,struct tnode *E, struct tnode *Slist1, struct tnode *Slist2);

struct tnode* makeNoElseNode(int nodetype,struct tnode *left, struct tnode *right);

//////////////////////

//////WHILE_BLOCK///////

struct tnode* whileNode(char *var,struct tnode *left,struct tnode *right);

struct tnode* makeWhileNode(int nodetype,struct tnode *left, struct tnode *right);

////////////////////////

struct tnode* makebreakNode(int nodetype);

struct tnode* makecontNode(int nodetype);

////////////////////////////

/// DO_WHILE_BLOCK ///////////////

struct tnode* dowhileNode(struct tnode *left);

struct tnode* makedowhileNode(int nodetype,struct tnode *left,struct tnode *right);

///////////////////////////////////

///////REP_UNTIL_BLOCK/////////////////

struct tnode* repuntilNode(struct tnode *left);

struct tnode* makerepuntilNode(int nodetype,struct tnode *left,struct tnode *right);

//////////////////////////////////////////


////////////CODEGEN//////////////////////

int getReg();

int getLabel();

void freeReg();

void freeLabel();

int codegen(struct tnode *root,FILE *fptr);

void codegenerator(struct tnode *F_root,struct tnode *M_root);

////////////////////////////////////////////


////////FUNC_CALL////////////////////////

void push_used_reg(FILE *fptr);

void pop_used_reg(int num_reg,FILE *fptr);

void push_arglist(struct tnode *root,FILE *fptr);

void pop_arglist(struct tnode *root,FILE *fptr);

void function_call_AtoB(struct tnode *root,FILE *fptr);

int function_call(struct tnode *root,FILE *fptr);

void CheckFuncVar(struct Paramstruct *list,struct tnode *root);

void TypeCheckFunc_call(struct tnode *root);

////////////////////////////////////////////


////////////READ_WRITE_ASSG///////////////////////

void callread(struct tnode *root,int reg,FILE *fptr);

void callwrite(struct tnode *root,int reg,FILE *fptr);

void TypeCheckAssg(struct tnode *root); 

void callassg(struct tnode *root,int l,int r,FILE *fptr);

///////////////////////////////////////////////

///////////LOOP_FUNC///////////////////

int ifCondBlock(struct tnode* root,FILE *fptr);

void ifBlock(struct tnode *root,FILE *fptr);

int whileCondBlock(struct tnode *root,FILE *fptr);

void whileBlock(struct tnode *root,FILE *fptr);

void doWhileCondBlock(struct tnode *root, int lno,FILE *fptr);

void doWhileBlock(struct tnode *root,FILE *fptr);

void repuntilCondBlock(struct tnode *root, int lno,FILE *fptr);

void repuntilBlock(struct tnode *root,FILE *fptr);

int ValidateCond(struct tnode *root,int nodetype,int label_no,FILE *fptr);

void TypeCheckCond(struct tnode *root);

void checkForInfiniteLoop(struct tnode *root);

///////////VARIABLE OPERATOR FUNCTIONS/////////////

void varcode(struct tnode *root,int r,FILE *fptr);

int setupvariable(struct tnode *root,FILE *fptr);

void TypeCheckOperator(struct tnode *root);

int setupoperator(struct tnode *root,int l,int r,FILE *fptr);

int call_not(struct tnode *root,int r,FILE *fptr);

void callop_or(int l,int r,FILE *fptr);

////////////////////////////////////////////////////

////////////BREAK CONTINUE////////////////

void callbreak(FILE *fptr);

void callcontinue(FILE *fptr);

///////////////////////////////////////////