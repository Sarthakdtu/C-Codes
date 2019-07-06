#include<iostream>
#include<queue>
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
		
		int cousinSum(int k)
		{
			
			if(this->root==NULL)
			{
				return -1;
			}
			
			int sum= 0;
			pair<node*, int> p;
			queue<pair<node*, int>> q;
			p.first = this->root;
			p.second= 0;
			int lvl=INT_MAX;
			q.push(p);
			
			while(!q.empty())
			{
				p = q.front();
				q.pop();
				if(p.first->left&&p.first->left->data==k)
				{
					lvl = p.second+1;
				}
				else if(p.first->right&&p.first->right->data==k)
				{
					lvl = p.second+1;
				} 
				else if(p.second==lvl)
				{	
					sum = sum+ p.first->data;
					cout<<"summing up "<<sum<<"\n";
				}
				else if(p.second<lvl)
				{			
				if(p.first->left!=NULL)
				{
				pair<node*, int> pl;
			
				pl.first= p.first->left;
				pl.second = p.second+1;
				q.push(pl);
				}
				if(p.first->right!=NULL)
				{
				pair<node*, int> pr;
				
				pr.first= p.first->right;
				pr.second = p.second+1;
				q.push(pr);
				}
			}
			}
			return sum;
		}
		
		node* immed(int B)
		{
			
	    node* just = new node;
	    just->data = INT_MAX;
	    
	    node* temp = this->root;
		while(temp)
        {
        	
        if(temp->data>B)
        {
        	if(just->data>=temp->data)
        	{
           // cout<<"just "<<just->data;		
            just = temp;
            }
            temp = temp->left;
			
        }
        else
        {
            temp = temp->right;
        }
    }
    return just;
   }
};

int main()
{
	tree t;
	int n =9;
	int arr[]= {6,7 ,8 ,9 ,11 ,12 ,14, 15, 18 };
	t.make_tree(arr, n);
	t.display();
	cout<<"\n";
	t.insert(23);

	cout<<"\n";
//	cout<<t.cousinSum(8);
	cout<<t.immed(11.3)->data;
	return 0;
}



