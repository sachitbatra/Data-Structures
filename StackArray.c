#include<stdio.h>

typedef struct
{
    int top;
    int capacity;
    int *array;
}STACK;

STACK* createStack(int size)
{
    STACK *s = (STACK *)malloc(sizeof(STACK));
    s->top=-1;
    s->capacity=size;
    s->array = (int *)malloc(s->capacity*sizeof(int));
    return s;
}

int isEmptyStack(STACK *s)
{
    return (s->top==-1);
}

int isFullStack(STACK *s)
{
    if (s->top == s->capacity-1)
    {
        return 1;
    }

    return 0;
}

void push(STACK *s, int data)
{
    if (isFullStack(s))
    {
        printf("Overflow Error");
        return;
    }

    s->array[++s->top]=data;
}

int pop(STACK *s)
{
    if (isEmptyStack(s))
    {
        printf("Underflow Error");
        return;
    }

    return (s->array[(s->top)--]);
}

void display(STACK *s)
{
    if (s->top==-1)
    {
        printf("Empty List\n");
        return;
    }

    for (int i=s->top; i>=0; i--)
    {
        printf("%d ",s->array[i]);
    }

    printf("\n");
}

main()
{
    int size, input;
    printf("Enter size of stack: ");
    scanf("%d",&size);

    STACK *s=createStack(size);

    while(1)
    {
        int val;
        printf("\n");
        display(s);
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");

        scanf("%d",&input);
        switch(input)
        {
        case(1):
            printf("Enter value: ");
            scanf("%d",&val);
            push(s,val);
            break;
        case(2):
            printf("%d",pop(s));
            break;
        case(3):
            display(s);
            break;
        }
    }
}
