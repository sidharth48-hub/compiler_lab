struct Classtable temp_chead = NULL;


int call_classnew(FILE *fptr)
{
    ////pushing used reg
    int no_used_reg = reg;
    push_used_reg(fptr);
    reg = 0;

    int r = getReg();

    fprintf(fptr,"MOV R%d ,\"Alloc\"\n",r);
    fprintf(fptr,"PUSH R%d\n",r);
    fprintf(fptr,"MOV R%d, %d\n",r,8);
    fprintf(fptr,"PUSH R%d\n",r);
    
    fprintf(fptr,"PUSH R0\n");
    fprintf(fptr,"PUSH R0\n");
    fprintf(fptr,"PUSH R0\n");

    fprintf(fptr,"CALL 0\n");

    fprintf(fptr,"POP R%d\n",r);//return value
    fprintf(fptr,"POP R0\n");
    fprintf(fptr,"POP R0\n");
    fprintf(fptr,"POP R0\n");
    fprintf(fptr,"POP R0\n");

    fprintf(fptr,"MOV R0,R%d\n",r);//moving return value to R0

    freeReg();
    
    ///popping used reg
    pop_used_reg(no_used_reg,fptr);
    reg = no_used_reg;


    return 0;
}

void findClasstable(struct tnode *root)
{
    if(root->nodetype == NODE_SELF || root->nodetype == NODE_VARIABLE)
    {
        
    }
}

void classFunction(FILE *fptr,struct tnode *root)
{
    struct tnode *classField = root->left;
    struct tnode *func = root->right;
    struct tnode *Arglist = func->left;
    
    int r = getReg();

    if(classField->nodetype == NODE_SELF || classField->nodetype == NODE_VARIABLE)
    {
        int temp_reg = codegen(classField,fptr);

        fprintf(fptr,"MOV R%d,R%d\n",r,temp_reg);
    }
    else if(classField->nodetype == NODE_CLASSFIELD_FUNCTION)
    {
        ClassField(fptr,r,classField);
    }

    fprintf(fptr,"MOV R%d, [R%d]\n",r,r);
    fprintf(fptr,"MOV R0, R%d\n",r);
    fprintf(fptr,"PUSH R0\n");
    freeReg();


    if(Arglist!=NULL)
    {
        push_arglist(Arglist,fptr);
    }

    fprintf(fptr,"PUSH R0\n"); //return value
    
    reg = 0;//setting to -1 for callee to use

    findClasstable(root);
    struct Classtable *classtable = temp_chead;

    struct Memberfunclist *function = Class_Mlookup(classtable,func->varname);

    int flabel  = function->Flabel;
    fprintf(fptr,"CALL F%d\n",flabel);
}

int call_classFunction(FILE *fptr,struct tnode *root)
{
    int no_used_reg = reg;//No of used registers

    //typecheck;

    classFunction(fptr,root);

    struct tnode *func = root->right;
    struct tnode *Arglist = func->left;
    
    if(Arglist!=NULL)
    {
        pop_arglist(Arglist,fptr); //pop arglist of callee
    }

    pop_used_reg(no_used_reg,fptr);//popping used reg

    reg = no_used_reg;//setting reg value to previous state

    int new_reg = getReg();

    fprintf(fptr,"MOV R%d,R0\n",new_reg);//storing return value to new register

    return new_reg;
    
}

void ClassField(FILE *fptr, int r, struct tnode *root)
{
    if(root->nodetype == NODE_SELF || root->nodetype == NODE_CLASSFIELD_VAR || root->nodetype == NODE_VARIABLE)
    {
        int temp_reg = codegen(root,fptr);

        fprintf(fptr,"MOV R%d,R%d\n",r,temp_reg);
        freeReg();
        
        if(root->nodetype == NODE_SELF)
        {
            temp_chead = root->classtable;
        }
        else
        {
            temp->chead = root->lentry->classtable;
        }    
        return;
    }

    if(root->left!=NULL)
        ClassField(fptr,r,root->left)

    if(root->nodetype == NODE_CLASSFIELD || root->nodetype == NODE_CLASSFIELD_FUNCTION)
    {
        fprintf(fptr,"MOV R%d,[R%d]\n",r,r);

        struct tnode *right = root->right;
        char *fieldname = right->varname;

        struct Fieldlist *field = Class_FLookup(temp_chead,fieldname);

        fprintf(fptr,"ADD R%d,%d\n",r,field->fieldIndex);

        Field_head = Clookup(fieldname);
    }    
}

void checkforself(struct tnode *root)
{
    struct tnode *temp = root;

    int count = -1;

    while(temp->left!=NULL)
    {
        count++;
        temp = temp->left;
    }

    if(temp->nodetype == NODE_SELF)
    {
        if(count>0)
        {
            printf("self variable usage is wrong\n");
            exit(0);
        }
    }
}

void call_ClassField(FILE *fptr, int r ,struct tnode *root)
{
    checkforself(root);//checking if self.field_name.sub_field_name is there or not
    temp_chead = NULL;
    ClassField(fptr,r,root);
}