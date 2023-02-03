#include<stdio.h>

int main()
{
    FILE *fptr = fopen("test.xsm", "w");
    fprintf(fptr, "%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n",0,2056,0,0,0,0,0,0);
    fprintf(fptr, "BRKP\n");
    fprintf(fptr, "MOV R0, 3\n");
    fprintf(fptr, "MOV R1, 2\n");
    fprintf(fptr, "ADD R0, R1");
    
    fclose(fptr);
    return 0;
}