
#include <stdio.h>
#include<stdlib.h>


struct node
{	
	int value;
	struct node* next;

};

struct node* top=NULL;


////////// Pushing into stack ///////

void push(int data)
{
	struct node* temp=NULL;
	temp = (struct node*)malloc(sizeof(struct node));
	temp->value=data;
	temp->next=top;
	top=temp;


}

/////// Popping from stack ///////

int pop()
{
	int num=top->value;	
	struct node* temp=top;	
	top=top->next;
	free(temp);
	return num;	


}



int check_palindrome(struct node* head, int size)
{
	if(head==NULL)		////NULL list 
		return 0;
	
	int i=1;
	struct node *fast_ptr=head;
	struct node *slow_ptr=head;
	

	while(fast_ptr && fast_ptr->next)
	{
		fast_ptr=fast_ptr->next->next;
		push(slow_ptr->value);
		slow_ptr=slow_ptr->next;
	

	}

	printf("\nmid value: %d ", slow_ptr->value);
	
	if(size%2!=0)
	{
		slow_ptr=slow_ptr->next;	
	}

	while(slow_ptr)
	{

		int num=pop();
		if(num!=slow_ptr->value)
			return 0;
		slow_ptr=slow_ptr->next;
	}


	
	return 1;

}




int main()
{

	printf("enter num of elements in linked list: ");
	int size;	
	scanf("%d", &size);

	if(size==0)		////empty list 
		return 0;

	int i=1;
	int num;
	
	
	struct node* head=NULL;
	head = (struct node*)malloc(sizeof(struct node));
	scanf("%d", &num);
	head->value=num;
	head->next=NULL;
	struct node* ptr=head;
	

	while(i<=size-1)
	{
		
		////creation of node

		struct node* temp=NULL;
		temp = (struct node*)malloc(sizeof(struct node));
		scanf("%d", &num);
		temp->value=num;
		temp->next=NULL;
		ptr->next=temp;
		ptr=temp;
		i++;

	}

	i=1;
	ptr=head;
	while(i<=size)
	{
		
		////print LL

		printf("%d ", ptr->value);
		ptr=ptr->next;
		i++;
		

	}

	int result=check_palindrome(head,size);
	if(result==0)
		printf("\nNOT A PALINDROME");
	else
		printf("\nIT IS A PALINDROME");
	return 0;
}
