#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	int data;
	struct node *next;

}NODE;

void qinsert(int, NODE **, NODE **);
int qremove(NODE **, NODE **);
void qdisplay(NODE *, NODE *);

void main()
{

	int k, x, ch;
	NODE *front, *rear;

	front = rear = NULL;

	while(1)
	{
		qdisplay(front, rear);

		printf("\n 1.INSERT \n");
		printf("\n 2.REMOVE \n");
		printf("\n 3.DISPLAY \n");
		printf("\n 4.EXIT \n");

		scanf("%d",&ch);
		switch(ch)
		{

			case 1: printf("Enter the Element: ");
					scanf("%d",&x);
					qinsert(x,&front,&rear);
					break;

			case 2: k = qremove(&front, &rear);
					break;

			case 3: qdisplay(front, rear);

			case 4: exit(0);

		}

	}

}

//Inserting
void qinsert(int x, NODE **f, NODE **r)
{

	NODE *temp;

    temp = (NODE*)malloc(sizeof(NODE));
    temp->data = x;
    temp->next = NULL;

    if(*f==NULL)
        *f = *r = temp;

    else
    {
		(*r)->next = temp;
        *r = temp;
    }
}

//Removing
int qremove(NODE **f, NODE **r)
{

    NODE *q;
	q = *f;

    int x;

    if(q==NULL)
    {
        printf("QUEUE EMPTY \n");
        return -1;
    }
    else
    {
        x = q->data;

        if(*f==*r)
			*f = *r = NULL;

        else
            *f = q->next;

        free(q);
        return x;

    }

}

//Displaying
void qdisplay(NODE *f, NODE *r)
{

    if(f==NULL)
        printf("QUEUE EMPTY \n");

    else
    {

		while(f!=r)
        {

			printf("%d-> ",f->data);
			f = f->next;

        }

      printf("%d-> ",f->data);

    }

}

























