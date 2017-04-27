#include<stdio.h>
#include<stdlib.h>

typedef struct cNode
{
    int *array;
    int front;
    int rear;
    int capacity;
}cQueue;

cQueue* createQueue(int);
int isEmpty(cQueue*);
int isFull(cQueue*);
void enQueue(cQueue*, int);
int deQueue(cQueue*);

void main()
{
    int capacity;
    printf("Enter the capacity of the queue: ");
    scanf("%d", &capacity);
    cQueue *queue = createQueue(capacity);

    int input, value;
    while(1)
    {
        printf("\n1. Enqueue.\n2. Dequeue.\n");
        scanf("%d", &input);
        switch(input)
        {
            case(1):    printf("Enter the value to be inserted: ");
                        scanf("%d", &value);
                        enQueue(queue, value);
                        break;
            case(2):    printf("%d\n", deQueue(queue));
                        break;
        }
    }
}

cQueue* createQueue(int cap)
{
    cQueue *retVal = (cQueue*)malloc(sizeof(cQueue));
    retVal->capacity = cap;
    retVal->front = retVal->rear = -1;
    retVal->array = (int*)malloc(sizeof(int) * cap);
}

int isEmpty(cQueue *queue)
{
    return (queue->front == -1);
}

int isFull(cQueue *queue)
{
    return ((queue->rear + 1)%(queue->capacity) == queue->front);
}

void enQueue(cQueue *queue, int data)
{
    if (isFull(queue))
    {
        printf("Overflow Error.\n");
        return;
    }

    queue->rear = ((queue->rear + 1) % (queue->capacity));
    queue->array[queue->rear] = data;

    if (queue->front == -1)
    {
        queue->front = queue->rear;
    }
}

int deQueue(cQueue *queue)
{
    if (isEmpty(queue))
    {
        printf("Underflow Error.\n");
        return;
    }

    int retVal = queue->array[queue->front];

    if (queue->front == queue->rear)
    {
        queue->front = queue->rear = -1;
        return retVal;
    }

    queue->front = ((queue->front + 1) % (queue->capacity));
    return retVal;
}
