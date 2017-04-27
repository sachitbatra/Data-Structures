//program to convert infix to postfix

 #include<stdlib.h>
 #include<stdio.h>

 void push(char, char*,int*);
 char pop(char*, int*);
 char peep(char*, int*);
 int input_prec(char);
 int stack_prec(char);
 void convert_postfix(char*, char*);

void main()
{
  char infix[10];
  char postfix[10];
  printf("enter valid infix Expression...");
  scanf("%s",infix);
  convert_postfix(infix,postfix);
  printf("\nThe postfix equivalent = %s\n",postfix);
 }

  void convert_postfix(char *infix,char *postfix)
  {
    char stk[10],sym;
    int top,i,j;
    i=j=0;
    top=-1;
    push('#',stk,&top);
    while(infix[i]!='\0')
    {
      sym=infix[i];
      while(stack_prec(peep(stk,&top)) >input_prec(sym))
          postfix[j++]=pop(stk,&top);
      if(stack_prec(peep(stk,&top))!=input_prec(sym))
          push(sym,stk,&top);
      else
          pop(stk,&top);
      i++;
     }
     while(peep(stk,&top)!='#')
         postfix[j++]=pop(stk,&top);
      postfix[j]='\0';
    }




   int input_prec(char ch)
   {
      switch(ch)
      {
      case '+':
      case '-':return 1;
      case '*':
      case '/':return 3;
      case '^':return 6;
      case '(':return 9;
      case ')':return 0;
      default :return 7;
     }
    }

   int stack_prec(char ch)
   {
     switch(ch)
     {
      case '+':
      case '-':return 2;
      case '*':
      case '/':return 4;
      case '^':return 5;
      case '(':return 0;
      case '#':return -1;
      default :return 8;
     }
    }

    void push(char x, char *s, int *top)
    {
         ++*top;
         s[*top]=x;
     }

     char pop(char *s, int *top)
     {
          char x;
          x=s[*top];
          --*top;
          return x;
      }

      char peep(char *s, int *top)
      {
         return(s[*top]);
       }








