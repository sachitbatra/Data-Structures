//program to evaluate a postfix expression

#include<stdlib.h>

#include<stdio.h>



int pevaluate(char *);
void push(int,int*,int*);


int pop(int*, int*);

int isoper(char);


void main()

{



  char postfix[10];

  int ch,k,x;


  printf("Enter the postfix expression...");

  scanf("%s",postfix);

 k=pevaluate(postfix);

  printf("Result = %d\n",k);

}



 int pevaluate(char *st)

 {
   int s[10];
//stack

 int top,r;


  top=-1;

 int i=0;

while(st[i]!='\0')

 {

  char ch=st[i];

  if(isoper(ch))
//check if operator

  {

    int op1=pop(s,&top);

     int op2=pop(s,&top);

     switch(ch)

 {

  case '+':r=op1+op2;
 break;


  case '-':r=op2-op1;
 break;

  case '*':r=op1*op2;
 break;

  case '/':r=op2/op1;
 break;
 }


     push(r,s,&top);

    }

  else

     push(ch-'0',s,&top);
//if operand

   i++;
  }

return(pop(s,&top));

 }



  int isoper(char ch)

   {

    if((ch=='+')||(ch=='-')||(ch=='*')||(ch=='/'))

          return 1;

     return 0;

 }


   void push(int x,int *s, int *t)

   {

    (*t)++;

    s[*t]=x;

  }



   int pop(int *s,int *t)

    {

    int x;

    x=s[*t];

    (*t)--;

    return x;

  }






















