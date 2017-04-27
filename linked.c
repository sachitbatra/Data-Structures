#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct node N;
typedef N* nodepointer;
struct node{
    int data;
    nodepointer next; 
};


nodepointer head1;
nodepointer head2;
nodepointer newh;



struct node* addatlast(nodepointer head,int value);
struct node* addfront(nodepointer head,int value);
nodepointer addAfter(nodepointer head,int b, int data);
void show(nodepointer head);
nodepointer reverse(nodepointer head);
void alternatingsplit(nodepointer head);
nodepointer replace(nodepointer head,int b, int data);
int count(nodepointer head,int value);
nodepointer removeDuplicates(nodepointer head);
nodepointer deleteVal(nodepointer head,int value);
nodepointer recurReverse(nodepointer head);
bool issorted(nodepointer head);
bool recurIsSort(struct node **temp);
int nodeCount(nodepointer head);
nodepointer deletefront(nodepointer head);
nodepointer MergeLists(nodepointer headA, nodepointer headB);
nodepointer recur(nodepointer head);
nodepointer rotate(int k, nodepointer head);
int  main(){
	
	/*head1=addatlast(head1,0);
	head1=addatlast(head1,1);*/
	//head1=addatlast(head1,7);
	head2=addatlast(head2,2);
	head2=addatlast(head2,3);
	head2=addatlast(head2,4);
	head2=addatlast(head2,7);
	head2=addatlast(head2,5);
	head2=addatlast(head2,6);
	//show(head1);
	//head=deletefront(head);
	show(head2);
	head2=recur(head2);
	show(head2);
	head2=rotate(4,head2);
	show(head2);
	//newh=MergeLists(head1,head2);
	//show(newh);
	
}
nodepointer rotate(int k, nodepointer head){
	nodepointer temp,beftemp;;
	int i=1;
	temp=head;
	while(i<=k&&temp!=NULL){
		beftemp=temp;
		temp=temp->next;
		i++;
	}
	nodepointer last;
	last=temp;
	while(last->next!=NULL){
		last=last->next;
	}
	last->next=head;
	beftemp->next=NULL;
	head=temp;
	return head;
	
}

nodepointer recur(nodepointer head){
	nodepointer first,rest;
	printf("\nin recur");
	first=head;
	rest=first->next;
	//first->next=rest;
	printf("\nfirst %d rest %d",first->data,rest->data);
	if(rest->next!=NULL){
		rest=recur(rest);
	}
	first->next->next=first;
	first->next=NULL;
	head=rest;
	printf("\nfirst %d rest %d head %d",first->data,rest->data,head->data);
	return rest;
}
nodepointer MergeLists(nodepointer headA, nodepointer headB)
{
  // This is a "method-only" submission. 
  // You only need to complete this method 
    nodepointer currA,currB;
    //nodepointer newh;
    
    currA=headA;
    currB=headB;
    while(currA!=NULL&&currB!=NULL){
		printf("\ninwhile");
        if(currA->data<currB->data){
			printf("\nin if");
            newh=addatlast(newh,currA->data);
            currA=currA->next;
        }
        else{
            newh=addatlast(newh,currB->data);
            currB=currB->next;
        }
		//currA=currA->next;
		//currA=currA->next;
    }
	if(currA==NULL){
		nodepointer temp=currB;
		while(temp!=NULL){
			newh=addatlast(newh,temp->data);
			temp=temp->next;
		}
	}
	else{
		nodepointer temp=currA;
		while(temp!=NULL){
			newh=addatlast(newh,temp->data);
			temp=temp->next;
		}
	}
	
    return newh;
    
}
nodepointer deletefront(nodepointer head){
	nodepointer temp;
	if(head==NULL){printf("\nempty");}
	else{
		temp=head;
		head=head->next;
		free(temp);
	}
	return head;
}

//Quetion 1
nodepointer addAfter(nodepointer head,int b, int value){
	printf("\nin add");
	nodepointer current,temp,add;
	current=head;
	add=malloc(sizeof(N));
	add->data=value;
	if(head==NULL){printf("\nempty list");}
	else {
		printf("\nadd %d",add->data);
		while(current->next!=NULL&&current->data!=b){
			current=current->next;
			temp=current->next;
		}
		current->next=add;
		add->next=temp;
			
	}
	
	return head;
}
//Question 2
nodepointer deleteVal(nodepointer head,int value){
	nodepointer temp,current;
	current=head;
	temp=NULL;
	if(head==NULL){printf("\nlist empty");}
	else if(head->data==value){
		head=head->next;
		free(current);
	}
	else{
		while(current!=NULL&&current->data!=value){
			temp=current;
			current=current->next;
				
		}
		temp->next=current->next;
		free(current);
		
	}
	return head;
}

//Question 3
nodepointer replace(nodepointer head,int b, int value){
	nodepointer current;
	if(head==NULL){printf("\nempty list");}
	else{
		current=head;
		while(current->next!=NULL&&current->data!=b){
			current=current->next;
		}
		current->data=value;
	}
	return head;
}

//Question 4
int count(nodepointer head,int value){
	int c=0;
	nodepointer current;
	current=head;
	while(current!=NULL){
		if(current->data==value){c++;}
		current=current->next;
	}
	return c;
}

//Question 5 
bool issorted(nodepointer head){
	if(head==NULL){printf("\nempty");}
	nodepointer temp;
	temp=head;
	while(temp->next!=NULL){
		if(temp->data > temp->next->data){
			break;
		}
		else{
			temp=temp->next;
		}
	}
	if(temp->next==NULL){
		return true;
	}
	else{
		return false;
	}
}
//Question 6 

bool recurIsSort(struct node **temp){
	nodepointer q= *temp;;
	if(q->next==NULL){
		return 1;
	}
	else if(q->data > q->next->data){
		return 1;
	}
	else{
		q=q->next;
		return recurIsSort(&q);
	}
}


//Question 7
nodepointer removeDuplicates(nodepointer head){
	nodepointer current,copy;
	current=head;
	copy=NULL;
	int c,i=0;
	while(current!=NULL){
		c=count(head,current->data);
		i=c;
		while(i!=1){
			copy=current->next;
			head=deleteVal(head,current->data);
			current=copy;
			i--;
		}
		current=current->next;
	}
	return head;
	
}

//Question 8
nodepointer a,b;
//repair
void alternatingsplit(nodepointer head){
	
	nodepointer temp;
	a=NULL;
	b=NULL;
	temp=head;
	if(head==NULL){
		printf("\nlist empty");
	}
	else{
		while(temp->next!=NULL){
			printf("\n\t temp %d",temp->data);
			printf("\n\t temp next %d",temp->next->data);
			a=addatlast(a,temp->data);
			b=addatlast(b,temp->next->data);
			temp=temp->next->next;
			printf("\n temp now %d",temp->data);
		}
		
		
	}
	printf("\n a: ");
	show(a);
	printf("\n b: ");
	show(b);
	
}


int nodeCount(nodepointer head){
	nodepointer current;
	current=head;
	int c=0;
	if(head==NULL){printf("\nlist empty");}
	else{
		while(current!=NULL){
			c++;
			current=current->next;
		}
		return c;
	}
	
}

nodepointer addatlast(nodepointer head,int value){
	printf("\nin add");
	nodepointer temp;
	temp=head;
    if(head==NULL){
        head=malloc(sizeof(N));
		head->data=value;
        head->next=NULL;
    }
    else{
        while(temp->next!=NULL){
            temp=temp->next;
           
        }
        temp->next=malloc(sizeof(N));
		temp->next->data=value;
		temp->next->next=NULL;
    }
	return head;
    
    
}

struct node* addfront(nodepointer head,int value){

	
	nodepointer add;
	add=(struct node*)malloc(sizeof(N));
	add->data=value;

	if(head==NULL){
		
		head=add;
	}
	else{
		add->next=head;
		head=add;
	}
	return head;
}



nodepointer reverse(nodepointer head){
    nodepointer current,next,prev;
    prev=NULL;
    next=NULL;
    current=head;
    while(current!=NULL){
        next=current->next;
        current->next=prev;
        prev=current;
        current=next;
        
    }
    head=prev;
    
    return head;
}

void show(nodepointer head){
	printf("\ncurrent list : ");
    nodepointer current;
    current=head;
    while(current!=NULL){
        printf("%d->",current->data);
        current=current->next;
    }
    printf("\n");
    //printf("%d\n",temp->data);
}
