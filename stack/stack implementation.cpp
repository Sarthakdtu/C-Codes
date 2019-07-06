#include<iostream>
#include<set>
using namespace std;

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
		
		node* ret_top()
		{
			return this->top;
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

int main()
{
	stack s;
	s.pop();
	cout<<s.isEmpty()<<"\n";
	s.push(1);
	s.pop();
	s.push(1);
	s.push(2);
	s.push(3);
	s.push(4);
	s.push(5);
	
	s.display();
	return 0;
}



