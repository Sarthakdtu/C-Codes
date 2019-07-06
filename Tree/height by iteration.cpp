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
	
	    node* make_complete_tree(node* parent, int data)
	    {
	    	if(parent==NULL)
	    	{
	    	node *n = new node;
			n->data = data;
			n->left = NULL;
			n->right = NULL;
			return n;
			}
			if(parent->left==NULL)
			{
				parent->left= make_complete_tree(parent->left);
			}
			else if(parent->right==NULL)
			{
				parent->right= make_complete_tree(parent->right);
			}
			
		}
		void inorder(node* parent)
		{
			if(parent == NULL)
			{
				return ;
			}
			else
			{
				inorder(parent->left);
				cout<<parent->data<<" ";
				inorder(parent->right);
			}
			
		}
		void preorder(node* parent)
		{
			if(parent == NULL)
			{
				return ;
			}
			else
			{
				cout<<parent->data<<" ";
				preorder(parent->left);
				preorder(parent->right);
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
		void inorder()
		{
			if(this->root==NULL)
			{
				cout<<"\n Tree is empty\n";
				return ;
			}
			inorder(this->root);
		}
		void preorder()
		{
			if(this->root==NULL)
			{
				cout<<"\n Tree is empty\n";
				return ;
			}
			preorder(this->root);
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
		
		int height_iter()
		{
			queue<node *> q;
			int h =-1;
			q.push(this->root);
			while(true)
			{
				int size = q.size();
				if(size==0)
				{
					return h;
				}
				h++;
				
				while(size>0)
				{
					node *n = q.front();
					q.pop();
					if(n->left!=NULL)
					{
						q.push(n->left);
					}
					if(n->right!=NULL)
					{
						q.push(n->right);
					}
					size--;		
				}
			
			}
			
		}
};

int main()
{
	tree t;
	int n =9;
	int arr[]= {6,7 ,8 ,9 ,11 ,12 ,14, 15, 18 };
	t.make_tree(arr, n);
	t.inorder();
	cout<<"\nHeight :"<<t.height();
	cout<<"\nHeight Iteration:"<<t.height_iter();
	t.preorder();
	return 0;
}



