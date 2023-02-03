int freereg_no=-1;

int getReg()
{
    freereg_no++;

    if(freereg_no==20)
    {    printf("Register full\n");
        return -1;
    }

    else
        return freereg_no;
} 

void freeReg()
{
    if(freereg_no>=0)
        freereg_no--;

    else
        printf("All registers already freed\n");

}

void callwrite(FILE *fptr,int resreg_no)
{
    int reg=getReg();
    
    fprintf(fptr,"MOV SP, 4122\n");         //AS first 26 locations are reserved for static variables
    fprintf(fptr,"MOV R%d,\"Write\"\n",reg);
    fprintf(fptr,"PUSH R%d\n",reg);
    fprintf(fptr,"MOV R%d, -2\n",reg);
    fprintf(fptr,"PUSH R%d\n",reg);
    fprintf(fptr,"PUSH R%d\n",resreg_no);
    fprintf(fptr,"PUSH R%d\n",reg);
    fprintf(fptr,"PUSH R%d\n",reg);
    
    freeReg();
    
    fprintf(fptr,"CALL 0\n");

    fprintf(fptr,"POP R0\n");
    fprintf(fptr,"POP R1\n");
    fprintf(fptr,"POP R1\n");
    fprintf(fptr,"POP R1\n");
    fprintf(fptr,"POP R1\n");
}

void callread(FILE *fptr,int resreg_no)
{
    int reg=getReg();
    
    fprintf(fptr,"MOV SP, 4122\n");   //AS first 26 locations are reserved for static variables
    fprintf(fptr,"MOV R%d,\"Read\"\n",reg);
    fprintf(fptr,"PUSH R%d\n",reg);
    fprintf(fptr,"MOV R%d,-1\n",reg);
    fprintf(fptr,"PUSH R%d\n",reg);
    fprintf(fptr,"PUSH R%d\n",resreg_no);
    fprintf(fptr,"PUSH R%d\n",reg);
    fprintf(fptr,"PUSH R%d\n",reg);
    
    freeReg();
    
    fprintf(fptr,"CALL 0\n");

    fprintf(fptr,"POP R0\n");
    fprintf(fptr,"POP R1\n");
    fprintf(fptr,"POP R1\n");
    fprintf(fptr,"POP R1\n");
    fprintf(fptr,"POP R1\n");
}


int address(char c)
{
    return 4096+(c-'a');
}

int codeGen(struct tnode* t,FILE* fptr)
{
    if(t->left==NULL && t->right==NULL)
    {
        if(t->nodetype==0)          //CONSTANT
        {
          int p=getReg();
          fprintf(fptr,"MOV R%d,%d\n",p,t->val);
          return p;
        }

        else                        //Variable
        {
            int p=getReg();
            int addr=address(*(t->varname));

            fprintf(fptr,"MOV R%d,%d\n",p,addr); //Moving the address to a register
            return p;
        }
    }

    int left=codeGen(t->left,fptr);
    
    if(t->nodetype==2)          //read
        callread(fptr,left);
    
    else if(t->nodetype==3)          //write
    {   
        if(t->left->nodetype==1)   //Variables
            fprintf(fptr,"MOV R%d,[R%d]\n",left,left);

        callwrite(fptr,left);
    }

    else if(t->nodetype==4)         //Connector
    {    int right=codeGen(t->right,fptr);}

    else                    //operator:+-*=
    {
        int right=codeGen(t->right,fptr);
        
        if(*(t->varname)=='=')
            fprintf(fptr,"MOV [R%d],R%d\n",left,right);
        
        
        else
        {
            if(t->left->nodetype==1)    //variable
                fprintf(fptr,"MOV R%d,[R%d]\n",left,left);
            
            if(t->right->nodetype==1)    //variable
                fprintf(fptr,"MOV R%d,[R%d]\n",right,right);

            switch(*(t->varname))
            {
                case '+' : fprintf(fptr,"ADD R%d,R%d\n",left,right);
                        break;
                case '-' : fprintf(fptr,"SUB R%d,R%d\n",left,right);
                        break;
                case '*' : fprintf(fptr,"MUL R%d,R%d\n",left,right);
                        break;
                case '/' : fprintf(fptr,"DIV R%d,R%d\n",left,right);
                        break;
            }
        }
    }

    freeReg();
    return left;
}

void codegenerator(struct tnode *root)
{
    FILE *fptr = fopen("exptree.xsm", "w");
    fprintf(fptr, "%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n",0,2056,0,0,0,0,0,0);
    int ret = codeGen(root,fptr);
    fprintf(fptr,"INT 10");
}