int num_of_params;
int num_of_given_params;


void push_used_reg(FILE *fptr)
{
    for(int i=1;i<=reg;i++)
    {
        fprintf(fptr,"PUSH R%d\n",i);
    }
}

void pop_used_reg(int num_reg,FILE *fptr)
{
    for(int i=num_reg;i>0;i--)
    {
        fprintf(fptr,"POP R%d\n",i);
    }
}

void push_arglist(struct tnode *root,FILE *fptr)
{
    int reg_no;
    switch(root->nodetype)
    {
        case NODE_VARIABLE: 
        case NODE_VAR_ARRAY:reg_no = codegen(root,fptr); //reg_no of variable;
                            fprintf(fptr,"MOV R%d,[R%d]\n",reg_no,reg_no);
                            fprintf(fptr,"PUSH R%d\n",reg_no);
                            return;
        case NODE_CONSTANT: 
        case NODE_STRINGS:
        case NODE_VAR_FUNC_CALL:
        default:if(root->nodetype!=NODE_ARGLIST)
                {
                    reg_no = codegen(root,fptr);
                    //printf("%d %s\n",reg_no,root->varname);
                    fprintf(fptr,"PUSH R%d\n",reg_no);
                    return;
                }                           
    }

    if(root->right!=NULL)
        push_arglist(root->right,fptr);
    if(root->left!=NULL)
        push_arglist(root->left,fptr);    
}

void pop_arglist(struct tnode *root,FILE *fptr)
{
    switch(root->nodetype)
    {
        case NODE_VARIABLE: 
        case NODE_VAR_ARRAY:
        case NODE_CONSTANT: 
        case NODE_STRINGS:
        case NODE_VAR_FUNC_CALL:
        default:if(root->nodetype!=NODE_ARGLIST)
                {
                    fprintf(fptr,"POP R1\n");
                    return;
                }                           
    }

    if(root->right!=NULL)
        pop_arglist(root->right,fptr);
    if(root->left!=NULL)
        pop_arglist(root->left,fptr); 
}

void CheckFuncVar(struct Paramstruct *list,struct tnode *root)
{
    int type;
    struct Gsymbol *temp1,*temp2;

    switch(root->nodetype)
    {
        case NODE_STRINGS:type = stringType;
                          if(type!=list->type)
                          {
                            printf("Error!!! Type of paramters do not match the declaration\n");
                            exit(1);
                          } 
                          list=list->next;
                          num_of_params--;
                          num_of_given_params--;
                          break;
        case NODE_CONSTANT:type = intType;
                           if(type!=list->type)
                           {
                            printf("Error!!! Type of paramters do not match the declaration\n");
                            exit(1);
                           }
                           list=list->next;
                           num_of_params--;
                           num_of_given_params--;
                           break;
        case NODE_VARIABLE:if(root->lentry!=NULL)
                           {
                              type = root->lentry->type;
                           }
                           else
                           {
                              struct Gsymbol *temp = Lookup(root->varname);
                              if(temp==NULL)
                              {
                                    printf("Error!!! parameter %s in function does not exist\n",root->varname);
                                    exit(1);
                              }
                              type = temp->type;
                           }
                           if(type!=list->type)
                          {
                            printf("Error!!! Type of paramters do not match the declaration\n");
                            exit(1);
                          }
                           list=list->next;
                           num_of_params--;
                           num_of_given_params--;
                           break;
        case NODE_VAR_ARRAY:temp1 = Lookup(root->varname);
                            if(temp1==NULL)
                            {
                                printf("Error!!! parameter %s in function does not exist\n",root->varname);
                                exit(1);
                            }
                            type = temp1->type;

                            if(type!=list->type)
                            {
                                printf("Error!!! Type of paramters do not match the declaration\n");
                                exit(1);
                            }
                            list=list->next;
                            num_of_params--;
                            num_of_given_params--;
                            break;
        case NODE_VAR_FUNC_CALL:temp2 = Lookup(root->varname);
                               type = temp2->type;
                               if(type!=list->type)
                               {
                                    printf("Error!!! Type of paramters do not match the declaration\n");
                                    exit(1);
                               }
                               list=list->next;
                               num_of_params--;
                               num_of_given_params--;
                               break;
        default: if(root->nodetype!=NODE_ARGLIST)
                 {
                    type = root->type;
                    if(type!=list->type)
                    {
                        printf("Error!!! Type of paramters do not match the declaration\n");
                        exit(1);
                    }
                    list=list->next;
                    num_of_params--;
                    num_of_given_params--;
                 }    
                break;
    }
    
    if(list==NULL && num_of_params==0 && num_of_given_params!=0)
    {
        printf("Error!!! No of paramters exceeds\n");
        exit(1);
    }

    if(num_of_params!=0 && num_of_given_params==0)
    {
        printf("Error!!! less no of parameters\n");
        exit(1);
    } 

    if(root->left!=NULL && root->nodetype==NODE_ARGLIST)
        CheckFuncVar(list,root->left);
    if(root->right!=NULL && root->nodetype==NODE_ARGLIST)   
        CheckFuncVar(list,root->right);           
}

void numParams(struct Paramstruct *list)
{
    while(list!=NULL)
    {
        num_of_params++;
        list=list->next;
    }
}

void numGivenParams(struct tnode *root)
{
    switch(root->nodetype)
    {
        case NODE_CONSTANT:
        case NODE_STRINGS:
        case NODE_VARIABLE:
        case NODE_VAR_FUNC_CALL:
        case NODE_VAR_ARRAY:
        default: if(root->nodetype!=NODE_ARGLIST)
                 {
                    num_of_given_params++;
                    return;
                 }   
    }

    if(root->left!=NULL)
        numGivenParams(root->left);
    if(root->right!=NULL)    
        numGivenParams(root->right);
}

void TypeCheckFunc_call(struct tnode *root)
{
    struct Gsymbol *temp = Lookup(root->varname);

    if(temp==NULL)
    {
        printf("Error!! Wrong function name\n");
        exit(1);
    }
    
    struct Paramstruct *paramlist = temp->paramlist;
    
    num_of_params = 0;
    numParams(paramlist);

    struct tnode *arglist = root->left;
    
    if(paramlist!=NULL && arglist==NULL)
    {
        printf("Error!!! No parameters are provided for function call of %s",root->varname);
        exit(1);
    }

    num_of_given_params=0;
    numGivenParams(arglist);

    CheckFuncVar(paramlist,arglist);
}

void function_call_AtoB(struct tnode *root,FILE *fptr)
{
    push_used_reg(fptr); //pushing used registers

    struct tnode *arglist = root->left;//arglist of the callee

    if(arglist!=NULL)
    {
        push_arglist(arglist,fptr); //push arglist of callee
    }

    fprintf(fptr,"PUSH R0\n"); //return value
    
    reg = 0;//setting to -1 for callee to use

    struct Gsymbol *temp = Lookup(root->varname);
    int flabel  = temp->flabel;
    fprintf(fptr,"CALL F%d\n",flabel);
}

int function_call(struct tnode *root,FILE *fptr)
{
    int no_used_reg = reg;//No of used registers
    
    TypeCheckFunc_call(root);//Typechecking the paramters provided

    function_call_AtoB(root,fptr);//calling function B from function A
    
    fprintf(fptr,"POP R0\n");//return value
    
    struct tnode *arglist = root->left;//arglist of the callee

    if(arglist!=NULL)
    {
        pop_arglist(arglist,fptr); //pop arglist of callee
    }

    pop_used_reg(no_used_reg,fptr);//popping used reg

    reg = no_used_reg;//setting reg value to previous state

    int new_reg = getReg();

    fprintf(fptr,"MOV R%d,R0\n",new_reg);//storing return value to new register

    return new_reg;

}
