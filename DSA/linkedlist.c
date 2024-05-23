#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

int addFront(struct Node **head_ref, int val)
{
    int retVal = 1;

    struct Node *p = (struct Node *)malloc(sizeof(struct Node));
    if (NULL == p)
    {
        retVal = 0;
        return retVal;
    }
    p->data = val;
    p->next = *head_ref; // this node points to what head was pointing to (the last entered node)
    *head_ref = p;       // head then points to this node as it is the last entered node

    return retVal;
}

int addBack(struct Node **head_ref, int val) // double pointer as values which head points to are going to be changed so we will use a pointer which points to head
{
    int retVal = 1;

    // This one inserts at end
    struct Node *newnode = (struct Node *)malloc(sizeof(struct Node));
    if (NULL == newnode)
    {
        retVal = 0;
        return retVal;
    }
    newnode->data = val;
    newnode->next = NULL;

    if (*head_ref == NULL) // if list is empty makes head point to first node
    {
        *head_ref = newnode;
    }
    else
    {
        struct Node *last = *head_ref;
        while (last->next != NULL) // loops till last node
        {
            last = last->next;
        }
        last->next = newnode; // attaches new node to last node
    }
    return retVal;
}

int insert(struct Node **head_ref, int val, int pos)
{
    int retVal = 1;
    struct Node *newnode = (struct Node *)malloc(sizeof(struct Node));
    if (NULL == newnode)
    {
        retVal = 0;
        return retVal;
    }
    newnode->data = val;
    newnode->next = NULL;

    if (pos < 0) // invalid input
    {
        retVal = 0;
    }
    else if (pos == 0) // if temp is 0
    {
        if (*head_ref == NULL) // first entry
        {
            *head_ref = newnode;
        }
        else
        {
            struct Node *temp = *head_ref; // temp node which points to first node
            newnode->next = temp;          // new node points to first node
            *head_ref = newnode;           // head points to new node now making it the first node
        }
    }
    else
    {
        struct Node *temp = *head_ref;
        for (int i = 0; i < pos - 1; i++) // loops till position
        {
            temp = temp->next;
            if (temp->next == NULL)
            {
                retVal = 0;
                return retVal;
            }
        }
        newnode->next = temp->next;
        temp->next = newnode;
    }
    return retVal;
}

int delete(struct Node **head_ref, int pos)
{
    int retVal = 1;
    struct Node *temp = *head_ref, *prev;
    if (temp == NULL) // empty list
    {
        retVal = 0;
        return retVal;
    }
    if (pos == 0) // checks first node
    {
        *head_ref = temp->next;
        free(temp);    // head points to next node after temp(here temp is first node so points to second node) hence temp not needed anymore so freed
        return retVal; // temp is the node itself, not the pointer to the memory, hence here we can free as that node is no longer needed while in other functions we cant because that memory is needed and cannot be erased
    }
    for (int i = 0; i != pos - 1; i++) // loops till end of list or till position-1 reached
    {
        if (temp == NULL)
        {
            retVal = 0;
            return retVal;
        }
        else
        {
            temp = temp->next;
        }
    }

    struct Node *nextnode = temp->next; // using nextnode to free the memory
    temp->next = temp->next->next;      // prev node points to node after deleted one
    free(nextnode);

    return retVal;
}

void display(struct Node *head) // no changes being done hence only single pointer
{
    struct Node *ptr = head;
    while (ptr != NULL) // loops till end
    {
        printf("%d  ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

int search(struct Node *head, int val)
{
    int i = 0;
    struct Node *ptr = head;
    while (ptr != NULL)
    {
        if (ptr->data == val)
        {
            printf("Data found at %d position\n", i);
            return i;
        }
        ptr = ptr->next;
        i++;
    }
    printf("Data not in list\n");
    return -1;
}

int main()
{
    struct Node *head = NULL;
    delete (&head, 0);
    addBack(&head, 1);
    delete (&head, 0);
    addBack(&head, 1);
    addBack(&head, 2);
    addBack(&head, 3);
    display(head);
    insert(&head, 4, 2);
    display(head);
    delete (&head, 2);
    display(head);
    search(head, 3);

    return 0;
}
