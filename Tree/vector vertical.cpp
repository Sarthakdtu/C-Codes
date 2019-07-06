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
		
		

 
 int extreme(node* A, int idx, bool isLeft)
 {
     if(A==NULL)
     {   
         return idx;
     }
     int r =0;
	 int l=0;
     if(isLeft)
     {
     //	cout<<"\nAt Left";
     	
         l = extreme(A->left, idx+1, isLeft);
        r = extreme(A->right, idx-1, isLeft);
         return l>r?l:r;
     }
     else
     {
          l = extreme(A->left, idx-1, isLeft);
          r = extreme(A->right, idx+1, isLeft);
         return l>r?l:r;
     }
 }
 
 void search(node *A, int idx, int curr, vector<int> &v)
 {
     if(!A)
     {
         return ;
     }
    
     if(idx == curr)
     {
     	cout<<A->data<<" ";
        v.push_back(A->data);
     }
     
     search(A->left, idx, curr-1, v);
     search(A->right, idx, curr+1, v);
     
 }
 
 
vector<vector<int> > verticalOrderTraversal(node* A) {
    if(!A)
    {
        return {{}};
    }
    
    int l = extreme(A, 0, true)*(-1);
    
    int r = extreme(A, 0, false);
    vector<vector<int>> v;

    
    for(int i = l+1;i<r;i++)
    {
    	cout<<"\nAt Level "<<i<<": ";
        vector<int> vi={};
        search(A, i, 0, vi);
        
        v.push_back(vi);
    }
    return v;
}

		
		
	};

void show(vector<int> vi)
{
	vector<int> :: iterator it;
       // cout<<"vi size: "<<vi.size();
        for(it = vi.begin(); it!= vi.end(); it++)
        {
        	cout<<*it<<" " ;
		}
}

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
	
	t.insert(20);
	t.insert(19);
	
	t.display();
	vector<vector<int>> v = t.verticalOrderTraversal(t.retRoot());
	vector<vector<int>> :: iterator it;
	for(it = v.begin(); it!= v.end();it++)
	{
		cout<<"\n";
	  show(*it) ;
	}
	return 0;
}



