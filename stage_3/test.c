#include<stdio.h>

void print(char *name)
{
    printf("%s",name);

    if(name=="hello")
    {
        printf("1");
    }
}

int main()
{
    print("hello");
    return 0;
}