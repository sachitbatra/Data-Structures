#include<stdio.h>
#include<stdlib.h>

typedef struct listNode
{
    int data;
    struct listNode *next;
}list;

void displayList(list*);
void insertHead(list**, int);
void insertMid(list**, int, int);
void insertEnd(list**, int);
void deleteElement(list**, int);
void reverseList(list**);

void main()
{
    list *head = NULL;
    int input, value, position;

    while(1)
    {
        printf("1. Display List.\n2. Insert Head.\n3. Insert Element at a Specific Position.\n4. Insert End.\n5. Delete Element.\n6. Reverse List.\n");
        scanf("%d", &input);

        switch(input)
        {
            case(1):    displayList(head);
                        break;

            case(2):    printf("Enter the value you want to insert: ");
                        scanf("%d", &value);
                        insertHead(&head, value);
                        break;

            case(3):    printf("Enter the value you want to insert: ");
                        scanf("%d", &value);
                        printf("Enter the position for the new Element: ");
                        scanf("%d", &position);
                        insertMid(&head, value, position);
                        break;

            case(4):    printf("Enter the value you want to insert: ");
                        scanf("%d", &value);
                        insertEnd(&head, value);
                        break;

            case(5):    printf("Enter the value you want to delete: ");
                        scanf("%d", &value);
                        deleteElement(&head, value);
                        break;

            case(6):    reverseList(&head);
                        break;
        }
    }
}

void displayList(list *head)
{
    if (head == NULL)
    {
        printf("Empty List.\n");
        return;
    }

    while(head->next != NULL)
    {
        printf("%d -> ", head->data);
        head = head->next;
    }

    printf("%d\n", head->data);
}

void insertHead(list **head, int value)
{
    list *link = (list*)malloc(sizeof(list));
    link->data = value;
    link->next = (*head);

    *head = link;
}

void insertMid(list **head, int value, int position)
{
    int curPos = 1;

    list *link = (list*)malloc(sizeof(list));
    link->data = value;
    link->next = NULL;

    if (curPos == position)
    {
        link->next = (*head);
        (*head) = link;
    }

    else
    {
        list *temp = (*head);
        list *prev = NULL;

        while((curPos != position) && (temp != NULL))
        {
            prev = temp;
            temp = temp->next;
            curPos++;
        }

        if (temp == NULL)
        {
            if (curPos == position)
            {
                prev->next = link;
                return;
            }

            else
            {
                printf("Invalid Position.\n");
                return;
            }
        }

        else
        {
            link->next = temp;
            prev->next = link;
        }
    }
}

void insertEnd(list **head, int value)
{
    list *link = (list*)malloc(sizeof(list));
    link->data = value;
    link->next = NULL;

    if ((*head) == NULL)
    {
        (*head) = link;
    }

    else
    {
        list *temp = (*head);
        while(temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = link;
    }
}

void deleteElement(list **head, int key)
{
    if ((*head) == NULL)
    {
        printf("Empty List.\n");
        return;
    }

    list *temp = (*head);
    list *prev = NULL;

    if ((*head)->data == key)
    {
        (*head) = (*head)->next;
        free(temp);
        return;
    }

    while((temp != NULL) && (temp->data != key))
    {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL)
    {
        printf("Element not found.\n");
        return;
    }

    prev->next = temp->next;
}

void reverseList(list **head)
{
    list *prev = NULL;
    list *current = (*head);
    list *next;

    while(current!=NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    (*head) = prev;
}
