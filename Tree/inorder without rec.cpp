#include<iostream>
#include<vector>
#include<stack>
//#include<queue>
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
		node *retRoot()
		{
			return this->root;
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
		
		

     void inorderWithoutRec()
     {
     	if(! this->root) return ;
     	
     	stack<node*> s;
     //	s.push(A);
     	node* curr = this->root;
     	while(curr||!s.empty())
     	{
     		while(curr)
     		{
     			s.push(curr);
     			curr= curr->left;
     			
			 }
     		curr = s.top();
     		s.pop();
     		cout<<" "<<curr->data;
     		curr = curr->right;
		 }
	 }
 
  		
		
	};



int main()
{
	tree t;
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
	
	t.insert(23);
	t.insert(19);
	
	t.display();
	
	t.inorderWithoutRec();
	return 0;
}



