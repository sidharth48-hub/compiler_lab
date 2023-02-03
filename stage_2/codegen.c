int reg=-1;
int arr[26];


int getReg()
{
    return ++reg;
}

void freeReg()
{
    if(reg>=0)
        reg--;
}

void callwrite(int reg,FILE *fptr)
{
    int r = getReg();
    fprintf(fptr,"MOV SP, 4112\n");
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
    fprintf(fptr,"MOV SP, 4112\n");
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


int codeGen(struct tnode *root, FILE *fptr)
{
    if(root->left==NULL && root->right==NULL)
    {
        int reg = getReg();
        if(root->nodetype==0)
        {
            fprintf(fptr, "MOV R%d, %d\n",reg,root->val);
        }
        else
        {
            int add = varaddress(*(root->varname));
            fprintf(fptr, "MOV R%d, %d\n",reg,add);
        }    
        return reg;
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
        {
            freeReg();
        }
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
    FILE *fptr = fopen("exptree.xsm", "w");
    fprintf(fptr, "%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n",0,2056,0,0,0,0,0,0);
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