#include<stdio.h>
#include<stdlib.h>

int insert(int *, int, int *, int *, int);
int remove1(int *, int *, int *);
void display(int *, int, int);

void main()
{
	
	int *q, x, ch, k;
	int f, r, size;
   
	printf("\n Enter the Size \n");
	scanf("%d",&size);
	
	q = (int*)malloc(sizeof(int)*size);
	f = r = -1;
	
	while(1)
	{
		display(q, f, r);
		
		printf("\n 1.INSERT \n");
		printf("\n 2.DELETE \n");
		printf("\n 3.DISPLAY \n");
    
		scanf("%d",&ch);
		switch(ch)
		{
			
			case 1: printf("Enter the Element: \n");
					scanf("%d",&x);
					
					k = insert(q, x, &f, &r, size);
					if(k>=0)
						printf("\n Element Inserted Successfully \n");
					break;
					
			case 2: k = remove1(q, &f, &r);
					if(k>=0)
						printf("Element Deleted is %d \n",k);
					break;
					
			case 3: display(q, f, r);
					break;
					
			case 4: exit(0);
		}
		
	}
	
}

//Inserting
int insert(int *q, int x, int *f, int *r, int size)
{
 
	if(*r==size-1)
    {
		printf("QUEUE FULL \n");
        return -1;
    }
    
	(*r)++; 
    q[*r] = x;
	
    if(*f==-1)
		*f = 0;
	
    return 1; 
	
}

//Removing  
int remove1(int *q, int *f, int *r)
{
	
    int x;
	
    if(*f==-1)
    {
		printf("Queue empty\n");
        return -1;
    }
	
    x = q[*f];
	
    if(*f==*r)
        *f = *r = -1;
	
    else
        (*f)++;
	
    return x; 
	
}

//Displaying 
void display(int *q, int f, int r)
{
	
	int i;
	
    if(f==-1)
		printf("QUEUE EMPTY \n");
	
	else
    {
		for(i=f; i<=r;i++)
			printf("%d ",q[i]);
    }
}



















   













