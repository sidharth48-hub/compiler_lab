typedef struct lnode
{
    char *label;
    int addr;
    struct lnode* next;
}lnode; 

void insertlink(struct lnode* newnode);

int findout(char label[10]);