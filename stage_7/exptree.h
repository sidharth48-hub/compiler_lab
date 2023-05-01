extern int bind;
extern struct Typetable *Thead;
extern struct Fieldlist *Fhead;
extern struct Classtable *chead;
extern struct Gsymbol *shead;
extern struct Lsymbol *Lhead;
extern struct Paramstruct *phead;
extern struct Typetable *Field_head;
extern int yylineno;
extern char *yytext;
extern int reg;
extern int label;
extern int break_arr[100];
extern int continue_arr[100];
extern int break_index;
extern int continue_index;
extern int flabel;

extern struct Typetable *boolType;
extern struct Typetable *intType;
extern struct Typetable *stringType;

typedef struct Typetable{
    char *name;                 //type name
    int size;                   //size of the type
    struct Fieldlist *fields;   //pointer to the head of fields list
    struct Typetable *next;     // pointer to the next type table entry
}Typetable;

typedef struct Fieldlist{
  char *name;              //name of the field
  int fieldIndex;          //the position of the field in the field list
  struct Typetable *type;  //pointer to type table entry of the field's type
  struct Classtable *Ctype;
  struct Fieldlist *next;  //pointer to the next field
}Fieldlist;


typedef struct tnode{
    int val;        // value (for constants)
    struct Typetable *type;       // type of the variable
    struct Classtable *classtable;
    char* varname;  // variable name (for variable nodes)
    int size;
    int nodetype;   // node type - // information about non-leaf nodes at the bottom
    struct Gsymbol *Gentry; // pointer to GST entry for global variables and functions
    struct Lsymbol *lentry;
    struct tnode *left,*right;  //left and right branches
}tnode;


typedef struct Gsymbol {
    char* name;       // name of the variable
    struct Typetable *type;         // type of the variable int-1 , string-2
    struct Classtable *classtable;
    int size; 
    int binding;      // stores the static memory address allocated to the variable
    struct Paramstruct *paramlist;
    int flabel;
    struct Gsymbol *next;
}Gsymbol;

typedef struct Lsymbol{
    char *name;
    struct Typetable *type;
    struct Classtable *classtable;
    int binding;
    struct Lsymbol *next;
}Lsymbol;

typedef struct Paramstruct {
    char *name;
    struct Typetable *type;
    struct Paramstruct *next;
}Paramstruct;


typedef struct Classtable {
    char *name;
    struct Fieldlist *Memberfield;
    struct Memberfunclist *Vfuncptr;
    struct Classtable *Parentptr;
    int Class_index;
    int Fieldcount;
    int Methodcount;
    struct Classtable *next;
}Classtable;

typedef struct Memberfunclist {
    char *name;
    struct Typetable *type;
    struct Paramstruct *paramlist;
    int Funcposition;
    int Flabel;
    struct Memberfunclist *next;
}Memberfunclist;

//////////////////////////////////////
///////Type Table Node functions//////
struct tnode *makeTypeNameNode(char *name,int nodetype);

struct tnode *makeTypeConnector(int nodetype,struct tnode *left,struct tnode *right);

//////////////////////////////////////


////////////////////////////////////////
///////Type Table Creation Fuctions/////

void TypetableCreate();

struct Fieldlist* Type_FieldInstall(char *typename,char *name);

struct Typetable* TInstall(char *name);

struct Typetable *TLookup(char *name);

struct Fieldlist *FLookup(struct Fieldlist *root,char *name);

void printTypetable();

////////////////////////////////////////
///////////CLASS CREATION FUNCTIONS/////

struct Paramstruct* createClassParamNode(char *typename,char *name);

struct Paramstruct* Param_Install(struct Paramstruct *paramlist,char *typename,char *name);



struct Classtable* createClassNode(char *name);

struct Classtable* CInstall(char *name, char *parent_class_name);

void printClasstable();



struct Fieldlist* createFieldNode(struct Classtable *cptr,char *typename, char *name);

struct Fieldlist* createFieldEntry(struct Fieldlist *field, struct Fieldlist *node);

void Class_Finstall(struct Classtable *cptr, char *typename, char *name);

struct Fieldlist* Class_Flookup(struct Classtable *cptr, char *name);

void printFieldlist(struct Fieldlist *fields);



struct Memberfunclist* createMemberFuncNode(char *name,struct Typetable *type, struct Paramstruct *paramlist);

struct Memberfunclist* createMemberFuncEntry(struct Memberfunclist *funclist, struct Memberfunclist *node );

void Class_Minstall(struct Classtable *cptr,char *name, struct Typetable *type, struct Paramstruct *paramlist);

struct Memberfunclist* Class_Mlookup(struct Classtable *cptr, char *name);

void printMemberfunclist(struct Memberfunclist *funclist);



struct tnode *makeClassNewNode(int nodetype,char *name,struct tnode *left);

struct tnode *makeClassDeleteNode(int nodetype,char *name,struct tnode *left);

struct tnode *makeSelfNode(int nodetype,char *name);

struct tnode *makeClassFieldNode(int nodetype,char *name,struct tnode *left,struct tnode *right);

struct tnode *makeClassIdNode(int nodetype,char *name,struct tnode *left,struct tnode *right,struct Classtable *classtable);

/////////////////////////////////////
/////Global Decl functions////
struct tnode* createDeclTree(char *c,int size,int nodetype,struct tnode *left,struct tnode *right);

struct tnode* makeDataTypeNode(int nodetype,struct tnode *left,struct tnode *right);

struct tnode* makeIdNodeDecl(int nodetype,char *str,int size,struct tnode *left);

struct tnode* makeDeclNode(int nodetype,struct tnode *l, struct tnode *r);

struct tnode* makeParamNode(int nodetype,struct tnode *left,struct tnode *right);

void printDecl(struct tnode *t);

////////////////////////

////////Gsymbol Table functions///////////

int getBind(int mem);

int getfLabel();

void GInstall(char *name, struct Typetable *type, int size,struct Paramstruct *paramlist,int nodetype);

struct Gsymbol *Lookup(char *name);

void printGsymbolTable();

///////////////////////////////////////////
///////////////////////////////////////////


////////////////////////////////////////
/////////Local Decl Functions/////////

struct tnode* createLDeclTree(char *c,int nodetype,struct tnode *left,struct tnode *right);

struct tnode* makeLDeclConnectorNode(int nodetype,struct tnode *l,struct tnode *r);

struct tnode* makeLDeclTypeNode(int nodetype,struct tnode *l,struct tnode *r);

struct tnode* makeLDeclIdNode(int nodetype,char *str);

///////////////////////////////////

/// Lsymbol table functions //////////////////////

int getLocalBindParam();

int getLocalBindDecl();

void LInstall(char *name, struct Typetable *type,int nodetype);

void LsymbolEntryParam(struct tnode *root);

void LsymbolEntryDeclVar(struct Typetable *type,struct tnode *root);

void LsymbolEntryDecl(struct tnode *root);

void LsymbolEntrySelf();

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

struct tnode* makeReturnNode(int nodetype,struct tnode *l);

void TypeCheckFunction(struct tnode *root);

void CheckNumParams(struct tnode *paramtree);

void numParams(struct Paramstruct *list);

void numGivenParams(struct tnode *root);

void push_localVar(struct tnode *root,FILE *fptr);

void pop_localVar(struct tnode *root,FILE *fptr);

void TypeCheckRet(struct tnode *root,struct Typetable *functype);

void create_ret(struct tnode *root,struct Typetable *functype,FILE *fptr);

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

void CheckFuncVar(struct tnode *root);

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


/////////////DYNAMic ALLOC///////////////

int calldynamic(FILE *fptr,struct tnode *root);

int callnull(FILE *fptr);

void fieldVars(FILE *fptr,int r,struct tnode *root);

int findClassFieldorNot(struct tnode *root);

int callfield(FILE *fptr,struct tnode *root);

int setupFieldVar(FILE *fptr,struct tnode *root,int r);

void findTypeField(struct tnode *root);

void printField(struct tnode *root);