#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
};

int insertFront(struct Node **head_ref, struct Node **tail_ref, int val)
{
    int retval = 1;
    struct Node *newnode = (struct Node *)malloc(sizeof(struct Node));
    if (NULL == newnode)
    {
        retval = 0;
        return retval;
    }
    newnode->data = val;
    newnode->next = NULL;
    newnode->prev = NULL;
    if (*head_ref == NULL)
    {
        *head_ref = newnode;
        *tail_ref = newnode;
    }
    else
    {
        struct Node *ptr = *head_ref;
        newnode->next = ptr;
        ptr->prev = newnode;
        *head_ref = newnode;
    }
    return retval;
}

int insertBack(struct Node **head_ref, struct Node **tail_ref, int val)
{
    int retval = 1;
    struct Node *newnode = (struct Node *)malloc(sizeof(struct Node));
    if (NULL == newnode)
    {
        retval = 0;
        return retval;
    }
    newnode->data = val;
    newnode->next = NULL;
    newnode->prev = NULL;
    if (*head_ref == NULL)
    {
        *head_ref = newnode;
        *tail_ref = newnode;
    }
    else
    {
        struct Node *ptr = *tail_ref;
        newnode->prev = ptr;
        ptr->next = newnode;
        *tail_ref = newnode;
    }
    return retval;
}

int insertIn(struct Node **head_ref, struct Node **tail_ref, int val, int pos)
{
    int retval = 1;
    struct Node *newnode = (struct Node *)malloc(sizeof(struct Node));
    if (NULL == newnode)
    {
        retval = 0;
        return retval;
    }
    newnode->data = val;
    newnode->next = NULL;
    newnode->prev = NULL;

    if ((pos < 0) || (*head_ref == NULL && pos > 0))
    {
        retval = 0;
        free(newnode);
    }
    else if (pos == 0)
    {
        if (*head_ref == NULL)
        {
            *head_ref = newnode;
            *tail_ref = newnode;
        }
        else
        {
            struct Node *ptr = *head_ref;
            newnode->next = ptr;
            ptr->prev = newnode;
            *head_ref = newnode;
        }
    }
    else
    {
        struct Node *ptr = *head_ref;
        for (int i = 0; i < pos - 1; i++)
        {
            if (ptr->next == NULL)
            {
                retval = 0;
                free(newnode);
                return retval;
            }
            ptr = ptr->next;
        }
        if (ptr->next == NULL)
        {
            ptr->next = newnode;
            newnode->prev = ptr;
            *tail_ref = newnode;
        }
        else
        {
            struct Node *previous = ptr;
            ptr = ptr->next;
            previous->next = newnode;
            newnode->prev = previous;
            ptr->prev = newnode;
            newnode->next = ptr;
        }
    }
    return retval;
}

int deletePos(struct Node **head_ref, struct Node **tail_ref, int pos)
{
    int retval = 1;
    struct Node *temp = *head_ref;
    if (temp == NULL || pos < 0)
    {
        retval = 0;
        return retval;
    }
    else if (pos == 0)
    {
        if (temp->next == NULL)
        {
            *head_ref = NULL;
            *tail_ref = NULL;
            free(temp);
            return retval;
        }
        *head_ref = temp->next;
        temp->next->prev = NULL;
        free(temp);
    }
    else
    {
        for (int i = 0; i < pos - 1; i++)
        {
            if (temp->next == NULL)
            {
                retval = 0;
                return retval;
            }
            temp = temp->next;
        }
        if (temp->next == NULL)
        {
            retval = 0;
            return retval;
        }
        else
        {
            struct Node *previous = temp;
            temp = temp->next;
            if (temp->next == NULL)
            {
                previous->next = NULL;
                *tail_ref = previous;
                free(temp);
                return retval;
            }
            previous->next = temp->next;
            temp->next->prev = previous;
            if (temp->next->next == NULL)
            {
                *tail_ref = temp->next;
            }
            free(temp);
        }
    }
    return retval;
}

int deleteVal(struct Node **head_ref, struct Node **tail_ref, int val) // WIP
{
    int retval = 1;
    struct Node *temp = *head_ref;
    if (temp == NULL)
    {
        retval = 0;
    }
    else if(temp->data == val)
    {
        *head_ref = temp->next;
        temp->next->prev = NULL;
        free(temp);
    }
    else
    {
        while (temp!= NULL)
        {
            if (temp->next != NULL && temp->next->data == val)
            {
                struct Node *previous = temp;
                temp = temp->next;
                if (temp->next == NULL)
                {
                    previous->next = NULL;
                    *tail_ref = previous;
                    free(temp);
                    return retval;
                }
                previous->next = temp->next;
                temp->next->prev = previous;
                if (temp->next->next == NULL)
                {
                    *tail_ref = temp->next;
                }
                free(temp);
            }
            temp = temp->next;
        }
    }
    return retval;
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

void displayFront(struct Node *head)
{
    struct Node *ptr = head;
    while (ptr != NULL)
    {
        printf("%d  ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

void displayBack(struct Node *tail)
{
    struct Node *ptr = tail;
    while (ptr != NULL)
    {
        printf("%d  ", ptr->data);
        ptr = ptr->prev;
    }
    printf("\n");
}

int main()
{
    struct Node *head = NULL;
    struct Node *tail = NULL;
    int x;

    // x = deletePos(&head, &tail, -2);
    // printf("x = %d\n\n",x);

    // insertFront(&head, &tail, 1);
    // displayFront(head);
    // displayBack(tail);
    // x = deletePos(&head, &tail, -9);
    // printf("x = %d\n",x);
    // displayFront(head);
    // displayBack(tail);
    // printf("\n");

    // insertFront(&head, &tail, 1);
    // insertFront(&head, &tail, 2);
    // displayFront(head);
    // displayBack(tail);
    // x = deletePos(&head, &tail, 0);
    // printf("x = %d\n",x);
    // displayFront(head);
    // displayBack(tail);
    // printf("\n");

    insertFront(&head, &tail, 10);
    insertFront(&head, &tail, 3);
    insertFront(&head, &tail, 4);
    // displayFront(head);
    // displayBack(tail);
    // x = deletePos(&head, &tail, 0);
    // printf("x = %d\n",x);
    // displayFront(head);
    // displayBack(tail);
    // printf("\n");

    insertFront(&head, &tail, 1);
    insertFront(&head, &tail, 2);
    insertBack(&head, &tail, 8);
    insertBack(&head, &tail, 7);
    insertIn(&head, &tail, 5, 5);
    // insertIn(&head, &tail, -3, -3);
    displayFront(head);
    displayBack(tail);
    x = deleteVal(&head, &tail, 7);
    printf("x = %d\n", x);
    // deletePos(&head, &tail, 0);
    displayFront(head);
    displayBack(tail);
}
