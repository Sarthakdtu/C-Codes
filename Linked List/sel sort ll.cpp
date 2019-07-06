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
    void swap(node* pre1, node* pre2)
	{
		if(!pre1||!pre2)
		{
			return ;
		}
		node* n1= pre1->next;
		if(pre1==this->head)
		{
			n1 = pre1;
		}
		node* n2= pre2->next;
		if(n2==NULL)
		{
			n2 = pre2;
		}
		if(n2==this->head)
		{
			node* temp = n1;
			n1 = n2;
			n2 = temp;
			temp =NULL;
			delete temp;
		}
		
		if(n1==this->head)
		{
			cout<<"\n head";
			node* temp = n1->next;
			this->head = n2;
			n1->next =n2->next ;
			pre2->next =n1;
			n2->next = temp;
			temp =NULL;
			delete temp;
			return ;
		}
		node* temp = n1->next;
		pre1->next = n2;
		n1->next=n2->next;
		n2->next = temp;
		pre2->next = n1;
		temp =NULL;
		delete temp;
	}		
	
	void sort()
	{
		if(this->head==NULL)
		{
			return ;
		}
		else
		{
			node* i = this->head;
			node* j = this->head;
			
			while(i!=NULL)
			{
				node* min = i;
				cout<<"\n i :"<<i->data;
				cout<<"\n min :"<<min->data;
				
				while(j->next!=NULL)
				{
					cout<<"\n j out of if:"<<j->data;
					if(min->data=j->next->data)
					{
						min = j;
						cout<<"\n min at if :"<<min->data;
						cout<<"\n j :"<<j->data;
					}
					j= j->next;
				}
				swap(min, j);
				
				i= i->next;
				j= i;
				
			}
		}
	
	
	}
		
		
};

int main()
{
	list c;
	
	c.insert(7);
	c.insert(6);
	c.insert(5);
	c.insert(4);
	c.insert(4);
	c.insert(3);
	c.insert(3);
	c.insert(2);
	c.insert(2);
	c.insert(1);
	c.display();
	c.sort();
   	c.display();
	return 0;
}



