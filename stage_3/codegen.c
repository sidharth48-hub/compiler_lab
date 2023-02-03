int reg=-1;
int label = -1;
int arr[26];

struct Stack {
    int break_label;
    int cont_label;
    unsigned capacity;
    int* array;
};
 
struct Stack* createStack(unsigned capacity)
{
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->capacity = capacity;
    stack->break_label = -1;
    stack->continue_label = -1;
    stack->array = (int*)malloc(stack->capacity * sizeof(int));
    return stack;
}
 
int isFull(struct Stack* stack)
{
    return stack->top == stack->capacity - 1;
}
 
int isEmpty(struct Stack* stack)
{
    return stack->top == -1;
}
 
void push(struct Stack* stack, int item)
{
    if (isFull(stack))
        return;
    stack->array[++stack->top] = item;
}


int pop(struct Stack* stack)
{
    if (isEmpty(stack))
        return INT_MIN;
    return stack->array[stack->top--];
}
 
int peek(struct Stack* stack)
{
    if (isEmpty(stack))
        return INT_MIN;
    return stack->array[stack->top];
}

struct Stack* stack = createStack(100);

int getReg()
{
    return ++reg;
}

int getLabel()
{
    return ++label;
}

void freeReg()
{
    if(reg>=0)
        reg--;
}

void freeLabel()
{
    if(label>=0)
        label--;
}

void callwrite(int reg,FILE *fptr)
{
    int r = getReg();
    fprintf(fptr,"MOV R%d ,\"Write\"\n",r);
    fprintf(fptr,"PUSH R%d\n",r);
    fprintf(fptr,"MOV R%d ,-2\n",r);
    fprintf(fptr,"PUSH R%d\n",r);
    fprintf(fptr,"PUSH R%d\n",reg);
    fprintf(fptr,"PUSH R%d\n",r);
    fprintf(fptr,"PUSH R%d\n",r);
    
    freeReg();
    fprintf(fptr,"CALL 0\n");

    fprintf(fptr,"POP R0\n");
    fprintf(fptr,"POP R1\n");
    fprintf(fptr,"POP R1\n");
    fprintf(fptr,"POP R1\n");
    fprintf(fptr,"POP R1\n");
}

void callread(int reg,FILE *fptr)
{
    int r = getReg();
    fprintf(fptr,"MOV R%d ,\"Read\"\n",r);
    fprintf(fptr,"PUSH R%d\n",r);
    fprintf(fptr,"MOV R%d ,-1\n",r);
    fprintf(fptr,"PUSH R%d\n",r);
    fprintf(fptr,"PUSH R%d\n",reg);
    fprintf(fptr,"PUSH R%d\n",r);
    fprintf(fptr,"PUSH R%d\n",r);
    
    freeReg();
    fprintf(fptr,"CALL 0\n");

    fprintf(fptr,"POP R0\n");
    fprintf(fptr,"POP R1\n");
    fprintf(fptr,"POP R1\n");
    fprintf(fptr,"POP R1\n");
    fprintf(fptr,"POP R1\n");
}


int varaddress(char c)
{
    return 4096+(c-'a');
}

int ifCondBlock(FILE *fptr,struct tnode* root)
{
    int l = codeGen(root->left,fptr);
    int r = codeGen(root->right,fptr);

    if(root->left->nodetype==1)
    {
        fprintf(fptr,"MOV R%d, [R%d]\n",l,l);
    }
    if(root->right->nodetype==1)
    {
        fprintf(fptr,"MOV R%d, [R%d]\n",r,r);
    }
    
    
    int lno = getLabel();

     
    if((root->varname) == "<")
    {
        fprintf(fptr,"LT R%d, R%d\n",l,r);
    }
    else if(root->varname == "<=")
    {
        fprintf(fptr,"LE R%d, R%d\n",l,r);
    }
    else if(root->varname == ">")
    {
        fprintf(fptr,"GT R%d, R%d\n",l,r);
    }
    else if(root->varname == ">=")
    {
        fprintf(fptr,"GE R%d, R%d\n",l,r);
    }
    else if(root->varname == "!=")
    {
        fprintf(fptr,"NE R%d, R%d\n",l,r);
    }
    else if(root->varname == "==")
    {
        fprintf(fptr,"EQ R%d, R%d\n",l,r);                                                         
    }
    
    fprintf(fptr,"JNZ R%d,L%d\n",l,lno);
    return lno;
}

void ifBlock(FILE *fptr,struct tnode *root)  
{
    int lno = ifCondBlock(fptr,root->left); //return label no

    struct tnode *temp = root->right;
    
    int elselno=-1;
    if(temp->right->varname == "else")
    {
        codeGen(temp->right->left,fptr); //else block
        elselno = getLabel();
        fprintf(fptr,"JMP L%d\n",elselno);
    }
    fprintf(fptr,"L%d:\n",lno);
    codeGen(temp->left,fptr);//then block
    if(elselno!=-1)
    {
        fprintf(fptr,"L%d:\n",elselno);
    }    
}

int whileCondBlock(FILE *fptr, struct tnode *root)
{
    int l = codeGen(root->left,fptr);
    int r = codeGen(root->right,fptr);

    if(root->left->nodetype==1)
    {
        fprintf(fptr,"MOV R%d, [R%d]\n",l,l);
    }
    if(root->right->nodetype==1)
    {
        fprintf(fptr,"MOV R%d, [R%d]\n",r,r);
    }
    
    
    int lno = getLabel();

     
    if((root->varname) == "<")
    {
        fprintf(fptr,"LT R%d, R%d\n",l,r);
    }
    else if(root->varname == "<=")
    {
        fprintf(fptr,"LE R%d, R%d\n",l,r);
    }
    else if(root->varname == ">")
    {
        fprintf(fptr,"GT R%d, R%d\n",l,r);
    }
    else if(root->varname == ">=")
    {
        fprintf(fptr,"GE R%d, R%d\n",l,r);
    }
    else if(root->varname == "!=")
    {
        fprintf(fptr,"NE R%d, R%d\n",l,r);
    }
    else if(root->varname == "==")
    {
        fprintf(fptr,"EQ R%d, R%d\n",l,r);                                                         
    }
    
    fprintf(fptr,"JZ R%d, L%d\n",l,lno);
    return lno;
}

void whileBlock(FILE *fptr,struct tnode *root)
{

    int looplno = getLabel();
    fprintf(fptr,"L%d:\n",looplno);
    int lno = whileCondBlock(fptr,root->left); //condition checking
    codeGen(root->right->left,fptr);//do statement
    fprintf(fptr,"JMP L%d\n",looplno);
    fprintf(fptr,"L%d:\n",lno);
}

void doWhileCondBlock(FILE *fptr,struct tnode *root, int lno)
{
    int l = codeGen(root->left,fptr);
    int r = codeGen(root->right,fptr);

    if(root->left->nodetype==1)
    {
        fprintf(fptr,"MOV R%d, [R%d]\n",l,l);
    }
    if(root->right->nodetype==1)
    {
        fprintf(fptr,"MOV R%d, [R%d]\n",r,r);
    }
     
    if((root->varname) == "<")
    {
        fprintf(fptr,"LT R%d, R%d\n",l,r);
    }
    else if(root->varname == "<=")
    {
        fprintf(fptr,"LE R%d, R%d\n",l,r);
    }
    else if(root->varname == ">")
    {
        fprintf(fptr,"GT R%d, R%d\n",l,r);
    }
    else if(root->varname == ">=")
    {
        fprintf(fptr,"GE R%d, R%d\n",l,r);
    }
    else if(root->varname == "!=")
    {
        fprintf(fptr,"NE R%d, R%d\n",l,r);
    }
    else if(root->varname == "==")
    {
        fprintf(fptr,"EQ R%d, R%d\n",l,r);                                                         
    }

    fprintf(fptr,"JNZ R%d, L%d\n",l,lno);
}

void doWhileBlock(FILE *fptr,struct tnode *root)
{
    int lno = getLabel();
    
    fprintf(fptr,"L%d:\n",lno);
    
    int check = codeGen(root->left,fptr);//do Block
    
    int breaklno = getLabel();

    if(check==-2)//break
    {
        fprintf(fptr,"JMP L%d\n",breaklno);
    }
    if(check==-3)//continue
    {
        fprintf(fptr,"JMP L%d\n",lno);
    }
    doWhileCondBlock(fptr,root->right->left,lno);

    if(check==-2)
    {
        fprintf(fptr,"L%d:\n",breaklno);
    }

}

void repuntilCondBlock(FILE *fptr,struct tnode *root, int lno)
{
    int l = codeGen(root->left,fptr);
    int r = codeGen(root->right,fptr);

    if(root->left->nodetype==1)
    {
        fprintf(fptr,"MOV R%d, [R%d]\n",l,l);
    }
    if(root->right->nodetype==1)
    {
        fprintf(fptr,"MOV R%d, [R%d]\n",r,r);
    }
     
    if((root->varname) == "<")
    {
        fprintf(fptr,"LT R%d, R%d\n",l,r);
    }
    else if(root->varname == "<=")
    {
        fprintf(fptr,"LE R%d, R%d\n",l,r);
    }
    else if(root->varname == ">")
    {
        fprintf(fptr,"GT R%d, R%d\n",l,r);
    }
    else if(root->varname == ">=")
    {
        fprintf(fptr,"GE R%d, R%d\n",l,r);
    }
    else if(root->varname == "!=")
    {
        fprintf(fptr,"NE R%d, R%d\n",l,r);
    }
    else if(root->varname == "==")
    {
        fprintf(fptr,"EQ R%d, R%d\n",l,r);                                                         
    }

    fprintf(fptr,"JZ R%d, L%d\n",l,lno);
}

void repuntilBlock(FILE *fptr,struct tnode *root)
{
    int lno = getLabel();
    
    fprintf(fptr,"L%d:\n",lno);
    
    codeGen(root->left,fptr);//do Block
    
    repuntilCondBlock(fptr,root->right->left,lno);
}

int codeGen(struct tnode *root, FILE *fptr)
{
    if(root->left==NULL && root->right==NULL)
    {
        int reg = getReg();
        if(root->nodetype==0)
        {
            fprintf(fptr, "MOV R%d, %d\n",reg,root->val);
        }
        else if(root->nodetype==1)
        {
            int add = varaddress(*(root->varname));
            fprintf(fptr, "MOV R%d, %d\n",reg,add);
        }    
        return reg;
    }

    if(root->nodetype==6)
    {
        ifBlock(fptr,root);
        return -1;
    }

    if(root->nodetype==7)
    {
        whileBlock(fptr,root);
        return -1;
    }

    if(root->nodetype==13)
    {
        doWhileBlock(fptr,root);
        return -1;
    }

    if(root->nodetype==12)
    {
        repuntilBlock(fptr,root);
        return -1;
    }

    if(root->nodetype==11)
    {
        if(root->varname=="break")
        {
            return -2;
        }
        if(root->varname=="continue")
        {
            return -3;
        }
    }

    int l = codeGen(root->left,fptr);

    if(root->nodetype==2)
    {
        callread(l,fptr);
        freeReg();
        return -1;
    }
    else if(root->nodetype==3)
    {
        if(root->left->nodetype==1)
        {
            fprintf(fptr,"MOV R%d, [R%d]\n",l,l);
        }
        callwrite(l,fptr);
        freeReg();
        return -1;
    }

    else if(root->nodetype==4) //connector
    {
        int r = codeGen(root->right,fptr);

        if(l!=-1)
			freeReg();

		if(r!=-1)
			freeReg();
		return -1;
    }
    else
    {    
        int r = codeGen(root->right,fptr);
        

        if(*(root->varname)=='=')
        {
            fprintf(fptr,"MOV [R%d], R%d\n",l,r);
        }
        else
        {
            if(root->left->nodetype==1)
            {
                fprintf(fptr,"MOV R%d,[R%d]\n",l,l);
            }
            if(root->right->nodetype==1)
            {
                fprintf(fptr,"MOV R%d, [R%d]\n",r,r);
            }

            switch(*(root->varname))
            {
                case '+' : fprintf(fptr,"ADD R%d, R%d\n",l,r);
                           break;
                case '-' : fprintf(fptr,"SUB R%d, R%d\n",l,r);
                           break;
                case '*' : fprintf(fptr,"MUL R%d, R%d\n",l,r);
                           break;
                case '/' : fprintf(fptr,"DIV R%d, R%d\n",l,r);
                           break;
            }
        }
    }

    freeReg();
    return l;
}

void codegenerator(struct tnode *root)
{
    FILE *fptr = fopen("exptree.o", "w");
    fprintf(fptr, "%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n",0,2056,0,0,0,0,0,0);
    fprintf(fptr,"MOV SP, 4112\n");
    fprintf(fptr,"MOV BP, 4113\n");
    int ret = codeGen(root,fptr);
    fprintf(fptr,"INT 10");
}

int retindex(char c)
{
    return (c-'a');
}

int evaluate(struct tnode *root)
{
    if(root->left==NULL && root->right==NULL)
    {
        if(root->nodetype==0)
        {
            return root->val;
        }
        else
        {
            int iter = retindex(*(root->varname));
            return iter;
        }    
    }

    int l = evaluate(root->left);

    if(root->nodetype==2) //read
    {
        scanf("%d",&arr[l]);
    }
    else if(root->nodetype==3) //write
    {
        if(root->left->nodetype==1) //variable
        {
            printf("%d\n",arr[l]);
        }
        printf("%d\n",l);
    }

    else if(root->nodetype==4)
    {
        int r = evaluate(root->right);
    }
    else
    {    
        int r = evaluate(root->right);
        

        if(*(root->varname)=='=')
        {
            arr[l]=r;
        }
        else
        {
            if(root->left->nodetype==1)
            {
                l=arr[l];
            }
            if(root->right->nodetype==1)
            {
                r=arr[r];
            }

            switch(*(root->varname))
            {
                case '+' : return l+r;
                           break;
                case '-' : return l-r;
                           break;
                case '*' : return l*r;
                           break;
                case '/' : return l/r;
                           break;
            }
        }
    }
}