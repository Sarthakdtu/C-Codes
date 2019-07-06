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
		void del_k_fromLast(int k)
		{
			if(k>this->size)
			{
				cout<<"\n OK! what?";
				return ;
			}
			node* slow= this->head;
			node *fast = this->head;
			
			while(k--)
			{
				fast= fast->next;
			}
			
			while(fast->next!= NULL)
			{
				slow = slow->next;
				fast = fast->next;
			}
			node *temp = slow->next;
			slow->next = slow->next->next;
			temp->next=NULL;
			delete temp;
			this->size--;
			
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
	c.insert(-5);
	c.insert(-4);
	c.insert(-3);
	c.insert(-2);
	c.insert(-1);
	//c.insert(5);
	
	c.display();
    c.del_k_fromLast(3);
	c.display();
	return 0;
}



