#include<iostream>
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
		
		void insert_k(int data, int idx)
		{
			if(idx<0)
			{
				cout<<"\nInvalid index Neg Num\n";
				return;
			}
			if(this->head==NULL&&idx>0)
			{
				cout<<"\nInvalid index head\n";
				return ;
			}
			if(idx==0)
			{
				this->insert_beg(data);
				return ;
			}
			else
			{
				int counter=0;
				node* temp = this->head;
				while(temp->next!=NULL&&counter!=idx-1)
				{
					temp=temp->next;
					counter++;
				}
				if(temp->next ==NULL&&counter != idx-1)
				{
					cout<<"\nInvalid Index Greater than size\n";
					return ;
				}
	
				if(counter == idx-1 && temp->next ==NULL)
				{
					this->insert(data);
					return ;
				}
				else
				{
				node *n = new node;
		     	n->data = data;
		    	n->next = NULL;
		    	node *save = temp->next;
				temp->next = n;
				n->next = save;
				
				}
				
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
		void chain_repairer()
		{
			node*slow =head ;
			node* fast =head->next;
			int counter =1;
			while(fast!= NULL&&fast->next!= NULL )
			{
				cout<<"\n"<<counter;
				slow=slow->next;
				fast = fast->next->next;
				cout<<"\nfast :"<<fast->data;
				cout<<"\nslow :"<<slow->data;
				
				counter++;
			}
			cout<<"\n out of loop and counter : "<<counter;
			node* start =head;
			node *prev = slow;
			//prev->next = NULL;
			slow= slow->next;
			node *left;
			node *sleft;
			cout<<"\n slow data : "<<slow->data;
			cout<<"\n prev data : "<<prev->data;
			cout<<"\n start data : "<<start->data;
			
			while(counter>0)
			{
				left  = start->next;
				sleft = slow->next;
				start->next = slow;
				slow->next = left;
				if(sleft == NULL)
				{
					slow->next = NULL;
					break;
				}
				slow = sleft;
				start = start->next->next;
				counter --;				
			}
			
			
		}
};

int main()
{
	list l;
	l.display();
	l.delete_beg();
	l.delete_end();
	l.insert_k(29, 1);
	l.insert(23);
	l.insert(2);
	l.insert(3);
	l.insert(423);
	l.insert(43);
	l.display();
	l.delete_beg();
	l.insert_k(29, 1);
	l.delete_end();
	l.display();
	l.insert_beg(234);
	l.insert_k(30, 8);
	l.insert_k(30, 3);
	l.display();
	
	list c;
	c.insert(1);
	c.insert(2);
	c.insert(3);
	c.insert(4);
	c.insert(5);
	c.insert(6);
	c.insert(-1);
	c.insert(-2);
	c.insert(-3);
	c.insert(-4);
	c.insert(-5);
	c.insert(-6);
	c.display();
	c.chain_repairer();
	c.display();
	return 0;
}



