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
		 
	
};

struct pairp
{
 list li1;
 list li2;	
};
pairp alternate(list l)
{
	pairp p;
	node *l1=l.ret_head();
	node *l2;
	l2 = l1->next;
	p.li1.insert(l1->data);
	while(l1&&l2)
	{
	  l1=l2->next;
	  p.li2.insert(l2->data);
	  if(l1)
	    {
		  p.li1.insert((l1->data));
		  l2= l1->next;
	 }
	}

	return p;
}


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
	pairp p;
	
     p =alternate(c);
     p.li1.display();
     p.li2.display();
	c.display();
	return 0;
}



