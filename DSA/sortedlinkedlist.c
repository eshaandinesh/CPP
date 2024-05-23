#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

int add(struct Node **head_ref, int val)
{
    int retval = 1;
    struct Node *newnode = (struct Node *)malloc(sizeof(struct Node));
    if(NULL == newnode)
    {
        retval = 0;
        return retval;
    }
    newnode->data = val;
    newnode->next = NULL;

    struct Node *temp = *head_ref, *prev;

    if (*head_ref == NULL) // first entry
    {
        *head_ref = newnode;
    }
    else if(temp->data >= val) //if the first node is already greater than added node then new node becomes first node
    {
        newnode->next = temp;
        *head_ref = newnode;
    }
    else
    {
        while(temp!=NULL)
        {
            prev = temp;
            temp = temp->next;
            if((prev->data < val) && (temp == NULL)) //if end of list reached
            {
                prev->next = newnode;
            }
            else if((prev->data < val) && (temp->data >= val)) //middle of list
            {
                newnode->next = temp;
                prev->next = newnode;
            }
        }
    }
    return retval;
}

int delete(struct Node **head_ref, int pos)
{
    int retVal = 1;
    struct Node *temp = *head_ref, *prev;
    if (temp == NULL)
    {
        retVal = 0;
        return retVal;
    }
    if (pos == 0)
    {
        *head_ref = temp->next;
        free(temp);    
        return retVal; 
    }
    for (int i = 0; i != pos - 1; i++) 
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

    struct Node *nextnode = temp->next;
    temp->next = temp->next->next;
    free(nextnode);

    return retVal;
}

void display(struct Node *head) 
{
    struct Node *ptr = head;
    while (ptr != NULL)
    {
        printf("%d    ", ptr->data);
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
    add(&head, 5);
    add(&head, 4);
    add(&head, 3);
    add(&head, 2);
    add(&head, 1);
    add(&head, 4);
    display(head);
    delete (&head, 0);
    add(&head, 1);
    delete (&head, 0);
    add(&head, 1);
    add(&head, 3);
    add(&head, 5);
    display(head);
    add(&head, 2);
    add(&head, 2);
    add(&head, 7);
    add(&head, 4);
    add(&head, 1);
    add(&head, 10);
    display(head);
    delete (&head, 4);
    display(head);
    search(head, 3);
    add(&head, 0);
    display(head);

    return 0;
}
