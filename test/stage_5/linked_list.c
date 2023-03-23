struct tnode* head = NULL;

void insertlink(struct tnode* node)
{
    if(head==NULL)
    {
        head=node;
        return;
    }
    
    struct tnode* temp = head;

    while(temp->next!=NULL)
    {
        temp=temp->next;
    }

    temp->next = node;
    node->next = NULL;

}

int findout(char label[10])
{
    struct tnode* temp = head;

    while(temp!=NULL)
    {
        if(strcmp(temp->label,label)==0)
        {
            return temp->address;
        }
        temp=temp->next;
    }

    return -1;
}