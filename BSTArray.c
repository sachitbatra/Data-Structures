#include<stdio.h>
#include<stdlib.h>

void insert(int*, int);
void preOrder(int*, int);

void main()
{
    int a[100];
    int i, input, value;

    for (int i=0; i<100; i++)
    {
        a[i] = 0;
    }

    while(1)
    {
        scanf("%d", &input);
        switch(input)
        {
            case(1):    printf("Enter the value to be inserted: ");
                        scanf("%d", &value);
                        insert(a, value);
                        break;
            case(2):    preOrder(a, 0);
                        break;
            case(3):    printf("%d", min(a));
                        break;
        }
    }
}

void insert(int *a, int value)
{
    int i = 0;
    while(a[i]!=0)
    {
        if (value<a[i])
        {
            i = 2*i + 1 ;
        }

        else
        {
            i = 2*i + 2;
        }
    }
    a[i] = value;
}

void preOrder(int *a, int i)
{
    if (a[i] != 0)
    {
        printf("%d ", a[i]);
        preOrder(a, 2*i + 1);
        preOrder(a, 2*i + 2);
    }
}

int min(int *a)
{
    int i = 0;
    while(a[2*i + 1] != 0)
    {
        i = 2*i + 1;
    }

    return (a[i]);
}
