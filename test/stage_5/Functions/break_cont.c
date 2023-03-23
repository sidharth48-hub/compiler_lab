int break_arr[100];
int continue_arr[100];

int break_index=-1;
int continue_index=-1;

void callbreak(FILE *fptr)
{
    int break_label = break_arr[break_index];
    break_index--;
    fprintf(fptr,"JMP L%d\n",break_label);
}

void callcontinue(FILE *fptr)
{
    int continue_label = continue_arr[continue_index];
    continue_index--;
    fprintf(fptr,"JMP L%d\n",continue_label);
}