#include<iostream>
#include<vector>
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

         void search(node *parent, int idx, int i)
         {
         	if(parent==NULL)
         	{
         		return ;
			}
			if(idx==i)
			{
				cout<<" "<<parent->data;
			}
			
		
				search(parent->left, idx, i-1);
				search(parent->right, idx, i+1);
			
		 }
		 
		 
         int extreme(node *parent, int idx, bool isright)
         {
         	if(parent==NULL)
         	{
         		return idx;
			 }
			 int r =0;
			 int l=0;
			 if(isright)
			 {
			 	 r= extreme(parent->right, idx+1, isright);
			     l = extreme(parent->left, idx-1, isright);
			     return l>r?l:r;
			 }
			 
			  r= extreme(parent->right, idx-1, isright);
			  l = extreme(parent->left, idx+1, isright);
			 return l>r?l:r;
		 }
         
         
         void verticalTraversal()
         {
         	if(this->root == NULL)
         	{
         		return ;
			}
			
			int left = extreme(this->root->left, 0, false)*-1;
			int right = extreme(this->root->right, 0, true);
			for(int i = left; i<right+1; i++)
			{
				cout<<"\nAt vertical level :"<<i<<"\n";
				search(this->root, i, 0);
			}
			
		 }

	};

int main()
{
	tree t;
	t.display();
	t.insert(12);
	t.insert(6);
	t.insert(18);
	t.insert(9);
	t.insert(15);
	t.insert(11);
	t.insert(13);
	t.insert(7);
	t.insert(5);
	t.insert(3);
	t.insert(4);
	
	t.insert(20);
	t.insert(19);
	
	t.display();
	t.verticalTraversal();
	return 0;
}



