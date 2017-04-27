#include<stdio.h>
#include<stdlib.h>

typedef struct listNode
{
    int data;
    struct listNode *prev;
    struct listNode *next;
}list;

void displayList(list*);
void insertHead(list**, int);
void insertEnd(list**, int);
void insertMid(list**, int, int);
void deleteElement(list**, int);

void main()
{
    list *head = NULL;
    int input, value, position;

    while(1)
    {
        printf("1. Display List.\n2. Insert Head.\n3. Insert Element at a specific Position.\n4. Insert End.\n5. Delete Element.\n");
        scanf("%d", &input);

        switch(input)
        {
            case(1):    displayList(head);
                        break;

            case(2):    printf("Enter the value to be inserted: ");
                        scanf("%d", &value);
                        insertHead(&head, value);
                        break;

            case(3):    printf("Enter the value to be inserted: ");
                        scanf("%d", &value);
                        printf("Enter the position: ");
                        scanf("%d", &position);
                        insertMid(&head, value, position);
                        break;

            case(4):    printf("Enter the value to be inserted: ");
                        scanf("%d", &value);
                        insertEnd(&head, value);
                        break;

            case(5):    printf("Enter the value to be deleted: ");
                        scanf("%d", &value);
                        deleteElement(&head, value);
                        break;
        }
    }
}

void displayList(list *head)
{
    if ((head) == NULL)
    {
        printf("Empty List.\n");
        return;
    }

    while((head)->next != NULL)
    {
        printf("%d -> ", (head)->data);
        (head) = (head)->next;
    }

    printf("%d\n", (head)->data);
}

void insertHead(list **head, int value)
{
    list *link = (list*)malloc(sizeof(list));
    link->data = value;
    link->prev = NULL;
    link->next = (*head);

    if ((*head))
    {
        (*head)->prev = link;
    }

    (*head) = link;
}

void insertMid(list **head, int value, int position)
{
    list *link = (list*)malloc(sizeof(list));
    link->data = value;
    link->next = link->prev = NULL;

    int curPos = 1;

    if (curPos == position)
    {
        link->next = (*head);

        if (*head)
        {
            (*head)->prev = link;
        }

        (*head) = link;
        return;
    }

    if ((*head) == NULL)
    {
        printf("Invalid Position.\n");
        return;
    }

    list *temp = (*head);

    while((temp->next != NULL) && (curPos != position))
    {
        temp = temp->next;
        curPos++;
    }

    if (temp->next == NULL)
    {
        if (curPos == position)
        {
            link->next = temp;
            temp->prev->next = link;
            temp->prev = link;
            return;
        }

        else if (curPos == position-1)
        {
            link->prev = temp;
            temp->next = link;
            return;
        }

        else
        {
            printf("Invalid Position.\n");
            return;
        }
    }

    if (curPos == position)
    {
        link->next = temp;
        temp->prev->next = link;
        temp->prev = link;
        return;
    }
}

void insertEnd(list **head, int value)
{
    list *link = (list*)malloc(sizeof(list));
    link->data = value;
    link->prev = link->next = NULL;

    if ((*head) == NULL)
    {
        (*head) = link;
        return;
    }

    list *temp = (*head);

    while(temp->next != NULL)
    {
        temp = temp->next;
    }

    link->prev = temp;
    temp->next = link;
}

void deleteElement(list **head, int key)
{
    list *temp = (*head);

    if ((*head)->data == key)
    {
        (*head)->next->prev = NULL;
        (*head) = (*head)->next;
        free(temp);
        return;
    }

    while((temp!=NULL) && (temp->data != key))
    {
        temp = temp->next;
    }

    if (temp == NULL)
    {
        printf("Element not found!\n");
        return;
    }

    if (temp->data == key)
    {
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        free(temp);
        return;
    }
}
