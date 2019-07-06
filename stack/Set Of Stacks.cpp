#include<iostream>
#include<set>
using namespace std;

#define Max 5
struct node
{
	int data;
	node* next;
};

class stack
{
	node *top;
	int size;
	public:
		stack()
		{
			this->size =0;
			this->top=NULL;
		}
		
		void push(int data)
		{
			node *n = new node;
			n->data = data;
			n->next = this->top;
			this->top = n;  
			this->size++;
		}
	    bool isEmpty()
	    {
	    	return (this->top == NULL);
		}
		
		bool isFull()
	    {
	    	return (this->size== Max);
		}
	
		void display()
		{
			node *temp = this->top;
			
			while(temp!= NULL)
			{
				cout<<temp->data<<" -> ";
				temp = temp->next;
			}
		}
		
		
		void pop()
		{
			if(this->top==NULL)
			{
				cout<<"\nStack is empty\n";
				return ;
			}
				node *temp = this->top;
                this->top = this->top->next;
				temp->next = NULL;
				cout<<"\nDeleted node : "<<temp->data;
				delete temp; 
				this->size--;				
		}
		
		
};


struct stacks
{
	stack s;
	stacks* next;
};

class SetOfStacks
{
	stacks *head;
	public:
		SetOfStacks();
		void push(int);
		void pop();
		void display();
				
};

SetOfStacks::SetOfStacks()
{
	this->head=NULL;
}

void SetOfStacks::push(int data)
{
	if(this->head==NULL)
	{
		stacks *stk = new stacks;
		stk->s = stack();
		stk->s.push(data);
		stk->next=NULL;
		this->head=stk;
		return ;
	}
	stacks *sk=this->head;
	if(sk->s.isFull())
	{
		cout<<"\nNew Stack is being made";
	    stacks *stk = new stacks;
	    stk->s = stack();
		stk->s.push(data);
		stk->next=sk;
		this->head=stk;
		return ;
	}
	sk->s.push(data);
	return ;
}

void SetOfStacks::pop()
{
	if(this->head==NULL)
	{
		cout<<"\nStack is Empty";
		return ;
	}
	
	stacks *sk=this->head;
	sk->s.pop();
	
	if(sk->s.isEmpty())
	{
		cout<<"\nStack is being deleted";
		
		this->head= sk->next;
		delete sk;
	}
	
}

void SetOfStacks::display()
{
	cout<<"\n";
	stacks *stk = this->head;
	if(stk==NULL)
	{
		cout<<"\nStacks are empty";
		return ;
	}
	while(stk!= NULL&&!stk->s.isEmpty())
	{
		stk->s.display();
		stk= stk->next;
	}
}



int main()
{
	SetOfStacks stk;
	stk.display();
	for(int i =1;i<16;i++)
	{
		stk.push(i);
		
		stk.display();
	}
	stk.display();
	for(int i =0;i<11;i++)
	{
		stk.pop();
	}
	stk.display();
	return 0;
}



