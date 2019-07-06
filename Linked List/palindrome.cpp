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
		
		node* isPH(node* h, node *n)
		{
			if(n==NULL)
			{
				cout<<"\nn is NULL";
				return h;
			}
			node* tbc = isPH(h, n->next);
			if(tbc == NULL)
			{
				cout<<"\nTBC is NULL";
				return NULL;
			}
			else
			{
				if(tbc->data==n->data)
				{
					cout<<"\nMAtched"<<tbc->data<<" "<<n->data;
					if(tbc->next == NULL)
					{
						return tbc;
					}
					return tbc->next;
				}
				else
				{
				cout<<"\nnot MAtched"<<tbc->data<<" "<<n->data;	
					return NULL;
				}
				
			}
		}
		bool isPalindrome()
		{
			if(isPH(this->head, this->head)!=NULL)
			{
				cout<<"\nPAlindrome";
				return true;
			}
			cout<<"\nNOPE";
			return false;
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
	c.insert(5);
	c.insert(4);
	c.insert(3);
	c.insert(2);
	c.insert(1);
	//c.insert(5);
	c.insert(6);
	//c.display();
    c.isPalindrome();
	c.display();
	return 0;
}



