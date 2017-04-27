#include<stdio.h>
#include<stdlib.h>

typedef struct stackNode
{
    int data;
    struct stackNode *next;
}stack;

void push(stack **, int);
int pop(stack**);
int peep(stack**);

void main()
{
    stack *stackNode = NULL;
    int input, value;

    while(1)
    {
        printf("1. Push.\n2. Pop.\n3. Peep.\n");
        scanf("%d", &input);

        switch(input)
        {
            case(1):    printf("Enter the value you want to Push: ");
                        scanf("%d", &value);
                        push(&stackNode, value);
                        break;
            case(2):    printf("Returned value is: %d.\n", pop(&stackNode));
                        break;
            case(3):    printf("Returned value is: %d.\n", peep(&stackNode));
                        break;
        }
    }
}

void push(stack **node, int value)
{
    stack *link = (stack*)malloc(sizeof(stack));
    link->data = value;
    link->next = (*node);
    (*node) = link;
}

int pop(stack **node)
{
    if ((*node) == NULL)
    {
        printf("Underflow Error!\n");
        return -1;
    }

    stack *temp = (*node);
    int retVal = temp->data;
    (*node) = (*node)->next;
    return retVal;
}

int peep(stack **node)
{
    if ((*node) == NULL)
    {
        printf("Underflow Error!\n");
        return -1;
    }

    return ((*node)->data);
}
