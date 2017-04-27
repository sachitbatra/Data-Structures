#include<stdio.h>

typedef struct node
{
    int data;
    struct node *next;
}NODE;

NODE *head = NULL;
int lengthOfList();
void display();
void insertFront(int);
void insertEnd(int);
void insertPos(int, int);
void deleteFront();
void deleteEnd();
void delPos(int);

main()
{
    int input,value,position;

    while(1)
    {
        scanf("%d", &input);
        if (input == 1)
        {
            printf("\n");
            display();
            printf("\n");
        }

        if (input == 2)
        {
            printf("Enter value to be inserted: ");
            scanf("%d", &value);
            insertFront(value);
            display();
            printf("\n");
        }

        if (input == 3)
        {
            printf("Enter value to be inserted: ");
            scanf("%d", &value);
            insertEnd(value);
            display();
            printf("\n");
        }

        if (input == 4)
        {
            printf("Enter value to be inserted: ");
            scanf("%d", &value);
            printf("Enter position: ");
            scanf("%d", &position);
            insertPos(position, value);
            display();
            printf("\n");
        }

        if (input == 5)
        {
            printf("\n");
            deleteFront();
            display();
            printf("\n");
        }

        if (input == 6)
        {
            printf("\n");
            deleteEnd();
            display();
            printf("\n");
        }

        if (input == 7)
        {
            printf("Enter position: ");
            scanf("%d", &position);
            delPos(position);
            display();
            printf("\n");
        }
    }
}

int lengthOfList()
{
    NODE *temp = head;
    int length = 0;

    if (temp == NULL)
    {
        return 0;
    }

    do
    {
        temp=temp->next;
        length++;
    } while(temp!=head);

    return length;
}

void display()
{
    NODE *temp = head;

    if (temp == NULL)
    {
        printf("Empty List! \n");
        return;
    }

    do
    {
        printf("%d -> ",temp->data);
        temp = temp->next;
    } while(temp!=head);
}

void insertFront(int x)
{
    NODE *link = (NODE *)malloc(sizeof(NODE));
    link->data = x;

    if (head==NULL)
    {
        link->next = link;
        head = link;
        return;
    }

    link->next=head;

    NODE *temp = head;

    while(temp->next!=head)
    {
        temp=temp->next;
    }

    temp->next = link;
    head = link;
}

void insertEnd(int x)
{
    NODE* link = (NODE *)malloc(sizeof(NODE));
    link->data = x;
    link->next = head;

    if (head == NULL)
    {
        insertFront(x);
        return;
    }

    NODE *temp = head;
    while(temp->next!=head)
    {
        temp=temp->next;
    }

    temp->next = link;
}

void insertPos(int pos, int x)
{
    if (pos == 1)
    {
        insertFront(x);
        return;
    }

    if (pos == lengthOfList() + 1)
    {
        insertEnd(x);
        return;
    }

    if (pos<1 || pos>lengthOfList() + 1)
    {
        printf("Invalid Position\n");
        return;
    }

    NODE* link = (NODE *)malloc(sizeof(NODE));
    link->data = x;
    NODE *temp=head;

    int curPos = 1;
    while(curPos != pos-1)
    {
        temp=temp->next;
        curPos++;
    }

    link->next = temp->next;
    temp->next = link;
}

void deleteFront()
{
    if (head == NULL)
    {
        printf("Empty List!");
        return;
    }

    if (head->next == head)
    {
        head = NULL;
        return;
    }

    NODE *h = head;
    NODE *temp = head;

    while(temp->next!=head)
    {
        temp=temp->next;
    }

    temp->next = head->next;
    head = head->next;
    free(h);
}

void deleteEnd()
{
    NODE *temp,*tail;
    tail = head;

    if (head == NULL)
    {
        printf("Empty List!\n");
        return;
    }

    if (head->next == head)
    {
        head = NULL;
        return;
    }

    while(tail->next!=head)
    {
        temp = tail;
        tail = tail->next;
    }

    temp->next=tail->next;
    free(tail);
}

void delPos(int pos)
{
    if (pos == 1)
    {
        deleteFront();
        return;
    }

    if (pos == lengthOfList())
    {
        deleteEnd();
        return;
    }

    if (pos<1 || pos>lengthOfList())
    {
        printf("Invalid Position!");
        return;
    }

    int curPos=1;
    NODE *temp = head;

    while(curPos!=pos-1)
    {
        temp=temp->next;
        curPos++;
    }

    NODE* del = temp->next;
    temp->next=temp->next->next;

    free(del);
}
