typedef struct tnode
{
    char *label;
    int address;
    struct tnode* next;
}tnode; 

void insertlink(struct tnode* node);

int findout(char *label);

