int reg=-1;


int getReg()
{
    return ++reg;
}

void freeReg()
{
    reg--;
}

int codeGen(struct tnode *root, FILE *fptr)
{
    if(root->op==NULL)
    {
        int r = getReg();
        fprintf(fptr, "MOV R%d, %d\n",r,root->val);
        return r;
    }
    else{

        int l = codeGen(root->left,fptr);
        int r = codeGen(root->right,fptr);
        switch(*(root->op)){
            case '+' : fprintf(fptr,"ADD R%d, R%d\n",l,r);
                       break;
            case '-' : fprintf(fptr,"SUB R%d, R%d\n",l,r);
                       break;
            case '*' : fprintf(fptr,"MUL R%d, R%d\n",l,r);
                       break;
            case '/' : fprintf(fptr,"DIV R%d, R%d\n",l,r);
                       break;
        }
        
        freeReg();
        if(l<r)
        {
            return l;
        }
        else
        {
            return r;
        }
    }
}

void codegenerator(struct tnode *root)
{
    FILE *fptr = fopen("exptree.xsm", "w");
    fprintf(fptr, "%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n",0,2056,0,0,0,0,0,0);
    int ret = codeGen(root,fptr);
    fprintf(fptr,"MOV SP, 4095\n");

    int reg = getReg();
    fprintf(fptr,"MOV R%d, 5\n",reg);
    fprintf(fptr,"PUSH R%d\n",reg);
    fprintf(fptr,"MOV R%d, -2\n",reg);
    fprintf(fptr,"PUSH R%d\n",reg);
    fprintf(fptr,"PUSH R%d\n",ret);
    fprintf(fptr,"PUSH R%d\n",reg);
    fprintf(fptr,"PUSH R%d\n",reg);
    freeReg();

    fprintf(fptr,"INT 7\n",reg);
    fprintf(fptr,"POP R%d\n",ret);
    fprintf(fptr,"POP R1\n");
    fprintf(fptr,"POP R1\n");
    fprintf(fptr,"POP R1\n");
    fprintf(fptr,"POP R1\n");
    fprintf(fptr,"INT 10");
}

