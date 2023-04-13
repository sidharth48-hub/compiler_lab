struct Typetable *Field_head;


int calldynamic(FILE *fptr,struct tnode *root)
{
    ////pushing used reg
    int no_used_reg = reg;
    push_used_reg(fptr);
    reg = 0;

    int r = getReg();

    if(strcmp(root->varname,"alloc")==0)
    {
        fprintf(fptr,"MOV R%d ,\"Alloc\"\n",r);
        fprintf(fptr,"PUSH R%d\n",r);
        fprintf(fptr,"MOV R%d, %d\n",r,8);
        fprintf(fptr,"PUSH R%d\n",r);
    }
    else if(strcmp(root->varname,"free")==0)
    {
        fprintf(fptr,"MOV R%d ,\"Free\"\n",r);
        fprintf(fptr,"PUSH R%d\n",r);
        
        int temp_reg = codegen(root->left,fptr);
        fprintf(fptr,"MOV R%d,[R%d]\n",temp_reg,temp_reg);
        fprintf(fptr,"PUSH R%d\n",temp_reg); //pushing the address to free
        freeReg();
        
    }
    else if(strcmp(root->varname,"initialize")==0)
    {
        fprintf(fptr,"MOV R%d ,\"Heapset\"\n",r);
        fprintf(fptr,"PUSH R%d\n",r);
        fprintf(fptr,"PUSH R0\n");
    }

    
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
    
    ///popping used reg
    pop_used_reg(no_used_reg,fptr);
    reg = no_used_reg;


    return 0;

}

int callnull(FILE *fptr)
{
    int r = getReg();
    fprintf(fptr,"MOV R%d,%d\n",r,0);
    return r;
}

void fieldVars(FILE *fptr,int r,struct tnode *root)
{
    if(root->nodetype == NODE_FIELD_VAR)
    {
        int temp_reg = codegen(root,fptr);

        fprintf(fptr,"MOV R%d,R%d\n",r,temp_reg);

        freeReg();

        if(root->lentry!=NULL)
        {
            Field_head = root->lentry->type;
            return;
        }

        struct Gsymbol *temp = Lookup(root->varname);
        Field_head = temp->type;
        return;
    }

    if(root->left!=NULL)
    {
        fieldVars(fptr,r,root->left);
    }

    if(root->nodetype == NODE_FIELD)
    {

        fprintf(fptr,"MOV R%d,[R%d]\n",r,r);

        struct tnode *right = root->right;
        char *fieldname = right->varname;

        struct Fieldlist *fields = Field_head->fields;

        struct Fieldlist *field = FLookup(fields,fieldname);

        fprintf(fptr,"ADD R%d,%d\n",r,field->fieldIndex);

        Field_head = field->type;
    }
}

int callfield(FILE *fptr,struct tnode *root)
{
    int r = getReg();
    fieldVars(fptr,r,root);
    return r;
}

int setupFieldVar(FILE *fptr,struct tnode *root,int r)
{
    if(root->lentry!=NULL)
    {
        int binding = root->lentry->binding;
        fprintf(fptr,"MOV R%d,BP\n",r);
        fprintf(fptr,"ADD R%d,%d\n",r,binding);
        return r;
    }

    struct Gsymbol *temp = Lookup(root->varname);
    
    if(temp==NULL && root->lentry==NULL)
    {
        printf("ERROR!!! Variable %s not found in declaration\n",root->varname);
        exit(1);
    }

    int binding = temp->binding;
    fprintf(fptr,"MOV R%d,%d\n",r,binding);
}

void findTypeField(struct tnode *root)
{
    if(root->nodetype == NODE_FIELD_VAR)
    {
        if(root->lentry!=NULL)
        {
            Field_head = root->lentry->type;
            return;
        }

        struct Gsymbol *temp = Lookup(root->varname);
        Field_head = temp->type;
        return;
    }

    if(root->left!=NULL)
    {
        findTypeField(root->left);
    }

    if(root->nodetype == NODE_FIELD)
    {
        struct tnode *right = root->right;
        char *fieldname = right->varname;

        struct Fieldlist *fields = Field_head->fields;

        struct Fieldlist *field = FLookup(fields,fieldname);

        Field_head = field->type;
    }
}

void printField(struct tnode *root)
{
    if(root->nodetype == NODE_FIELD_VAR)
    {
        printf("%s\n",root->varname);
        return;
    }

    if(root->left!=NULL)
    {
        printField(root->left);
    }

    if(root->nodetype == NODE_FIELD)
    {
        struct tnode *right = root->right;
        char *fieldname = right->varname;

        printf(".\n");
        printf("%s\n",fieldname);
    }
}