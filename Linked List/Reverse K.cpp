#include<iostream>
#include<set>
using namespace std;

struct node
{
	int data;
	node* next;
};

class list
{
	node *head;
	int size;
	public:
		list()
		{
			this->size =0;
			this->head=NULL;
		}
		
		node* ret_head()
		{
			return this->head;
		}
		void insert(int data)
		{
			node *n = new node;
			n->data = data;
			n->next = NULL;
			if(head == NULL)
			{
				this->head = n;
			}
			else
			{
				node *temp = this->head;
				while(temp->next!=NULL)
				{
					temp=temp->next;
				}
				temp->next=n;
			}
			this->size++;
		}
	
	
		void display()
		{
			if(head == NULL)
			{
				cout<<"\n List is empty\n";
				return ;
			}
			else
			{
				node *temp = head;
				while(temp!=NULL)
				{
					cout<<temp->data<<" -> ";
					temp=temp->next;
				}
			}
			cout<<"\n";
		}
		
		
		void delete_end()
		{
			if(this->head==NULL)
			{
				cout<<"\nList is empty\n";
				return ;
			}
			else if(head->next == NULL)
			{
				delete this->head;
				this->size--;
			}
			else
			{
				node *temp = this->head;
				while(temp->next->next!=NULL)
				{
					temp=temp->next;
				}
				node *del = temp->next;
				temp->next = NULL;
				delete del; 
				this->size--;				
			}
		}
		int ret_size()
		{
			node *temp = this->head;
			int s=0;
			while(temp!=NULL)
			{
				s++;
				temp = temp->next;
			}
			return s;
		}
		node* jump(int k)
		{
			node *temp = this->head;
			int i=0;
			while(i<k&&temp!= NULL)
			{
				i++;
				temp = temp->next;
			}
			return temp;
		}
		void reverseK(int k)
		{
			node* temp =this->head;
			node *prev =NULL;
			node* prepreI= NULL;
			int iter=1;
			node* fwd;
			bool isF=true;
			node* preI= this->head;
			int i =0;
			while(temp!=NULL)
			{
			i = k;
			preI = temp;
			
			
			while(temp!=NULL&&i>0)
			{
				//
				fwd =temp->next;
				//
				temp->next=prev;
				prev =temp;
				//
				temp = fwd;
				i--;
			}
			
			if(isF)
			{
			   isF= false;
			   this->head = prev;
			   			   
			   prev = preI;	
			   //
			} 
	        else
			{
			   prepreI->next = prev;
			   
			}
			prepreI =preI;
			
		   }		
		
		preI->next =NULL;
		
}
};

int main()
{
	list c;
	c.insert(1);
	c.insert(2);
	c.insert(3);
	c.insert(4);
	c.insert(5);
	c.insert(6);
	c.insert(7);
	c.insert(8);
	c.insert(9);
	c.insert(10);
	c.insert(11);
	//c.insert(12);
	c.display();
    c.reverseK(4);
	c.display();
	return 0;
}



