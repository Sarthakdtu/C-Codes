#include<iostream>
#include<string>
#include<ctype.h>
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
			node *temp = this->top;
			while(temp!= NULL)
			{
				cout<<temp->data<<" -> ";
				temp = temp->next;
			}
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
				//cout<<"\nDeleted node : "<<temp->data;
				delete temp; 
				this->size--;	
				return ret;			
		}
		
		
};

int scan_symbol(char c)
{
	if(isalpha(c))
	{
		return 1;
	}
	else
	{
		if(c=='('||c==')')
		{
			return 3;
		}
	}
	return 2;	
}

string get_exp()
{
	string str;
	cin>>str;
	return str;
}
int get_priority(char c)
{
    if(c == '-' || c =='+')
	{
		return 0;
	}
	else if(c == '*' )
	{
		return 1;
	}
	else if(c == '/' )
	{
		return 2;
	}
	else if(c == '^' )
	{
		return 3;
	}
	else if(c == ')'||c=='(')
	{
		return -1;
	}
	return -2;
}

string postfix(string exp)
{
	stack s;
	int i=0;
	string pf;
	while(i<exp.length())
	{
		char c = exp[i];
		
		i++;
		int l = sizeof(char);
		int tbd = scan_symbol(c);
		switch(tbd)
		{
			case 1:{
				pf+=c;
				break;
			}
			case 2:{
				   int j = get_priority(s.top_elt());
                   int pr =get_priority(c);
	               while(!s.isEmpty() && j>=pr)
                	{
	            	 char top = s.pop();
	            	 pf+=top;
	            	 j = get_priority(s.top_elt());
                	}
                	s.push(c);
				break;
			}
			case 3:
				if(c == '(')
				{
				  s.push(c);  	
				}
				else 
				{
				  while(s.top_elt()!= '('&&!s.isEmpty() )
				  {
				  	char top = s.pop();
				  	pf+=top;
				  }
				  char top = s.pop();
				  if(top!='(')
					{
						return "Invalid Expression";
					}
				}

		}
		
		
	}
	
	while(!s.isEmpty())
	{
		char c =s.pop();
		if(c == '(')
		{
			return "Invalid Expression";
		}
		pf+=c;
	} 
	return pf;
}

int main()
{
    
	string exp = "a+b*c/d+e-f";
	cout<<postfix(exp);
	
	
	return 0;
}



