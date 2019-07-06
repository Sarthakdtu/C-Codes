#include<iostream>
#include<string>
using namespace std;

struct node
{
	char data;
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
		char top_elt()
		{
			if(this->top==NULL)
			{
				return '\0';
			}
			return this->top->data;
		}
		void push(char data)
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
			cout<<"\n";
			node *temp = this->top;
			while(temp!= NULL)
			{
				cout<<temp->data<<" -> ";
				temp = temp->next;
			}
			cout<<"\n";
		}
		
		
		char pop()
		{
			if(this->top==NULL)
			{
				//cout<<"\nStack is empty\n";
				return '\0';
			}
			    char ret;
				node *temp = this->top;
                this->top = this->top->next;
				temp->next = NULL;
				ret = temp->data;
				cout<<"\nDeleted node : "<<temp->data;
				delete temp; 
				this->size--;	
				return ret;			
		}
		
		
};

int get_opp(char c)
{
	if(c=='}')
	{
		return '{';
	}
	else if(c==']')
	{
		return '[';
	}
	return '(';	
}

bool isBalanced(string exp)
{
	stack s;
	
	for(int i = 0;i<exp.length();i++)
	{
		s.display();
		char ch = exp[i];
		if(ch=='['||ch=='{'||ch=='(')
		{
			s.push(ch);
		}
		else if(!s.isEmpty())
		{
			char top = s.pop();
			if(top!=get_opp(ch))
			   return false;
		}
		else if(s.isEmpty())
		{
			return false;
		}
		
	}
	if(!s.isEmpty())
	{
		s.display();
		return false;
	}
	return true;
	
}

int main()
{
    
	string exp = "[({(})]";
	cout<<isBalanced(exp);
	
	
	return 0;
}
