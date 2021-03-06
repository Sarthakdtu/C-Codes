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
		void insert_beg(int data)
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
				this->head= n;
				n->next=temp;
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
		void delete_beg()
		{
			if(this->head==NULL)
			{
				cout<<"\nList is empty\n";
				return ;
			}
			else
			{
				node *temp = this->head;
				this->head = this->head->next;
				delete temp;
				this->size--;
			}
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
		
		int delete_mid(node *n)
		{
			if(n==NULL)
			{
				return -1;
			}
			else
			{
				//n->data=n->next->data;
				//n->next=n->next->next;
				cout<<"\nn's data : "<<n->data;
				cout<<"\nn's next data : "<<n->next->data;
				n= n->next;
				cout<<"\nn's data : "<<n->data;
				cout<<"\nn's next data : "<<n->next->data;
				return this->size--;
			}
		}
		
		void node_selector(int i)
		{
			if(this->head==NULL)
			{
				return ;
			}
			else
			{
				int k=0;
				node* temp=this->head;
				while(k!=i)
				{
					temp = temp->next;
					k++;
				}
				if(this->delete_mid(temp)>-1)
				{
					cout<<"\nMission accomplished\n";
				}
				else
				{
					cout<<"\nMission failed\n";
				}
			}
		}
};

int main()
{
	list c;
	c.insert(1);
	c.insert(2);
	c.insert(3);
	c.insert(4);
	c.insert(1);
	c.insert(6);
	c.insert(1);
	c.insert(2);
	c.insert(-3);
	c.insert(-4);
	c.insert(5);
	c.insert(6);
	c.display();
	c.node_selector(5);
   	c.display();
	return 0;
}



