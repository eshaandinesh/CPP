#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void add(struct Node **head_ref, int val) // double pointer as values which head points to are going to be changed so we will use a pointer which points to head
{
    // This one inserts in beginning
    //  struct Node* p = (struct Node*)malloc(sizeof(struct Node));
    //  p->data = val;
    //  p->next = *head_ref; //this node points to what head was pointing to (the last entered node)
    //  *head_ref = p; //head then points to this node as it is the last entered node

    // This one inserts at end
    struct Node *newnode = (struct Node *)malloc(sizeof(struct Node));
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
}

void insert(struct Node **head_ref, int val, int pos)
{
    struct Node *newnode = (struct Node *)malloc(sizeof(struct Node));
    newnode->data = val;
    newnode->next = NULL;

    if (*head_ref == NULL) // first entry
    {
        *head_ref = newnode;
    }
    else if (pos == 0) // if temp is 0
    {
        struct Node *temp = *head_ref; // temp node which points to first node
        newnode->next = temp;          // new node points to first node
        *head_ref = newnode;           // head points to new node now making it the first node
    }
    else
    {
        struct Node *temp = *head_ref;
        for (int i = 1; i < pos; i++) // loops till end or till temp
        {
            if (temp->next != NULL)
            {
                temp = temp->next;
            }
            else
            {
                break;
            }
        }
        newnode->next = temp->next;
        temp->next = newnode;
    }
}

void delete(struct Node **head_ref, int pos)
{
    struct Node *temp = *head_ref, *prev;
    if (pos == 0 && temp != NULL) // checks first node and also checks if list is empty
    {
        *head_ref = temp->next;
        free(temp); // head points to next node after temp(here temp is first node so points to second node) hence temp not needed anymore so freed
        return;     // temp is the node itself, not the pointer to the memory, hence here we can free as that node is no longer needed while in other functions we cant because that memory is needed and cannot be erased
    }
    for (int i = 0; i != pos - 1 && temp != NULL; i++) // loops till end of list or till position-1 reached
    {
        temp = temp->next;
    }
    if (temp == NULL) // if loop reached end and the position was not found then we exit the function
        return;

    struct Node *nextnode = temp->next; // using nextnode to free the memory
    temp->next = temp->next->next;      // prev node points to node after deleted one
    free(nextnode);
}

void display(struct Node *head) // no changes being done hence only single pointer
{
    struct Node *ptr = head;
    while (ptr != NULL) // loops till end
    {
        printf("%d    ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

void search(struct Node *head, int val)
{
    int i = 0;
    struct Node *ptr = head;
    while (ptr != NULL)
    {
        if (ptr->data == val)
        {
            printf("Data found at %d position\n", i);
            return;
        }
        ptr = ptr->next;
        i++;
    }
    printf("Data not in list\n");
}

int main()
{
    struct Node *head = NULL;
    delete (&head, 0);
    add(&head, 1);
    delete (&head, 0);
    add(&head, 1);
    add(&head, 2);
    add(&head, 3);
    display(head);
    insert(&head, 4, 2);
    display(head);
    delete (&head, 2);
    display(head);
    search(head, 3);

    return 0;
}
