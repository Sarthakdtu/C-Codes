#include<iostream>
#include<list>
#include<array>

using namespace std;

struct node
{
	int data;
	node* left;
	node* right;
};

class tree
{
	private:
	    node *root;
	    
		node* insert(node* parent,int data)
		{
			if(parent==NULL)
			{
			node *n = new node;
			n->data = data;
			n->left = NULL;
			n->right = NULL;
			return n;
			}
			if(data>parent->data)
			{
				parent->right=insert(parent->right, data);
			}
			else{
				parent->left=insert(parent->left, data);
			}
			
		
			return parent;
		}
	
		void display(node* parent)
		{
			if(parent == NULL)
			{
				return ;
			}
			else
			{
				display(parent->left);
				cout<<parent->data<<" ";
				display(parent->right);
			}
			
		}
		
		int height(node* parent)
		{
			if(parent ==NULL)
			{
				return -1;
			}
			int left_height = this->height(parent->left);
			int right_height = this->height(parent->right);
			
			if(left_height>right_height)
			{
				return (1+left_height);
			}
			else
			{
				return (1+right_height);
			}
		}
		
	   node* make_tree(node* parent,int arr[], int end, int start)
	   {
	   	if(start>end)
	   	{
	   		//cout<<"\n In here";
	   		return NULL;	
		}
		
		int mid =(start+end)/2;
		
		parent = new node;
		parent->data = arr[mid];
			
		parent->left =make_tree(parent->left, arr, mid-1, start);
		parent->right =make_tree(parent->right, arr, end, mid+1);
		
		return parent;
	   }
		
		void levelOrderHelper(node* parent, int level, int index, list<node*> *l[] )
		{
			if(parent==NULL)
			{
				return ;
			}
			if(level==0)
			{
				*(l[index])
				return ;
			}
			this->levelOrderHelper(parent->left, level-1,index, l);
			this->levelOrderHelper(parent->right, level-1,index, l);
		} 
		public:
		tree()
		{
		  this->root=NULL;
		}
		void display()
		{
			if(this->root==NULL)
			{
				cout<<"\n Tree is empty\n";
				return ;
			}
			display(this->root);
		}
		void insert(int data)
		{
			this->root = insert(this->root, data);
		}
		void make_tree(int arr[], int n)
		{
			this->root = make_tree(this->root,arr, n-1, 0);
		}
		
		int height()
		{
			if(this->root==NULL)
			{
				return -1;
			}
			else
			{
				return this->height(this->root);
			}
		}
		list<node*>* levelOrderList()
		{
			
			int h = this->height();
			if(h==-1)
			{
				return (NULL);
			}
				list<node*> *l[]=new list<node*>[10];
			for(int i =0; i<h+1;i++)
			{
				this->levelOrderHelper(this->root, i,i, l);
			}
			return l;
		}
};

void displayList(list<node*> *l[], int h)
{
	for(int i =0; i<h+1;i++)
	{
		cout<<l[i];
	}
}


int main()
{
	tree t;
	int n =9;
	int arr[]= {6,7 ,8 ,9 ,11 ,12 ,14, 15, 18 };
	t.make_tree(arr, n);
	list<node*>* l[]= t.levelOrderList();
	t.display();
	displayList(l, t.height());
	
	//cout<<"\nHeight :"<<t.height();
	
	return 0;
}



