#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	int prty;
};

struct priority
{
	int count;
	struct node pQueue[50];

};
void display(struct priority *);
void qinsert(int, int, struct priority *);
int qdelete(struct priority *);

int main()
{
	struct priority pty;
	pty.count=0;
	int input,ptyInt,value;
  	int temp;

    while(1)
    {
        display(&pty);
        printf("\n1. Insert");
        printf("\n2. Remove");
        printf("\n3. Display");
        printf("\n4. Exit\n");
        scanf("%d",&input);
        switch(input)
        {
            case 1: printf("Enter the priority: ");
                    scanf("%d",&ptyInt);
                    printf("Enter the value: ");
                    scanf("%d",&value);
                    qInsert(value,ptyInt,&pty);
                    break;

            case 2: temp=qDelete(&pty);
                    if(temp>=0)
                    {
                        printf("deleted element: data=%d\n",temp);
                    }
                    else
                    {
                        printf("Empty list\n");
                    }
                    break;

            case 3: display(&pty);
                    break;

            case 4: exit(0);
        }
    }
}

void qInsert(int info, int ptyInt, struct priority *pty)
{
	struct node *temp;
	temp = (struct node *)malloc(sizeof(struct node));
	int curIndex;
	temp->data = info;
	temp->prty = ptyInt;
	curIndex = pty->count-1;
	while(curIndex>=0 && (pty->pQueue[curIndex]).prty > ptyInt)
	{
		pty->pQueue[curIndex+1]= pty->pQueue[curIndex];
		curIndex = curIndex-1;
	}

	pty->pQueue[curIndex+1]= *temp;
	++pty->count;
}

int qDelete(struct priority *pty)
{
	int delValue,curIndex;
	if(pty->count == 0)
    {
        return -1;
    }

	else
	{
		delValue = (pty->pQueue[0]).data;
		for(curIndex=1; curIndex < pty->count; curIndex++)
        {
            pty->pQueue[curIndex-1] = pty->pQueue[curIndex];
        }
		--(pty->count);
		return delValue;
	}
}

void display(struct priority *pty)
{
	int curIndex;
	printf("The numbers are :");
	for(curIndex=0; curIndex< pty->count; curIndex++)
	{
		printf("%d -> ", (pty->pQueue[curIndex]).data);
	}
}
