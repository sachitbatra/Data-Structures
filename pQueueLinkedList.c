#include<stdio.h>
#include<stdlib.h>

typedef struct tempQNode
{
    int data;
    int priority;
    struct tempQNode *next;
}QNode;

void enqueue(int, int, QNode**, QNode**);
int dequeue(QNode**, QNode**);
void display(QNode*, QNode*);

void main()
{
    QNode *front = NULL;
    QNode *rear = NULL;

    int input, value, priorityInput;
    while(1)
	{
		printf("\n1. Insert\n2. Delete\n3. Exit\n");
		scanf("%d",&input);

		switch(input)
		{
			case 1: printf("Enter the Element:");
					scanf("%d",&value);
					printf("Enter Priority:");
					scanf("%d",&priorityInput);

					enqueue(value, priorityInput, &front, &rear);
					display(front,rear);
					break;

			case 2: value=dequeue(&front, &rear);
              		if(value>=0)
                    {
                        printf("Element deleted=%d\n",value);
                    }
                	display(front, rear);
                	break;

			case 3: exit(0);
					break;
		}
	}
}

void enqueue(int value, int priority, QNode **front, QNode **rear)
{
    QNode *link = (QNode*)malloc(sizeof(QNode));
    link->data = value;
    link->priority = priority;
    link->next = NULL;

    if (*front == NULL)
    {
        *front = link;
        *rear = link;
    }

    else
    {
        if (link->priority < (*front)->priority)
        {
            link->next = *front;
            *front = link;
        }

        else if(link->priority > (*rear)->priority)
        {
            (*rear)->next = link;
            *rear = link;
        }

        else
        {
            QNode *temp = *front;
            QNode *prev = NULL;

            while(link->priority > temp->priority)
            {
                prev = temp;
                temp = temp->next;
            }

            link->next = temp;
            prev->next = link;
        }
    }
}

int dequeue(QNode **front, QNode **rear)
{
    if (*front == NULL)
    {
        printf("No Element.");
        return -1;
    }

    QNode *temp = *front;
    *front = (*front)->next;
    int retValue = temp->data;
    free(temp);
    return retValue;
}

void display(QNode *front, QNode *rear)
{
    while(front != rear)
    {
        printf("%d %d || ", front->data, front->priority);
        front = front->next;
    }

    printf("%d %d", front->data, front->priority);
}
