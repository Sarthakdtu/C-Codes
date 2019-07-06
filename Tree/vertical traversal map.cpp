#include<iostream>
#include<vector>
#include<map>
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
		
		

 
 
 
vector<vector<int> > verticalOrderTraversal(node* A) {
    cout<<"HEre";
    if(A==NULL) return {{}};
	
	map<int, vector<int>> m;
	queue<pair<int, node*>> q;
	q.push({0, A});
	while(!q.empty())
	{
		pair<int, node*> p =q.front();
		q.pop();
		int currD = p.first;
		m[currD].push_back(p.second->data);
		if(p.second->left!= NULL)
		{
			q.push(make_pair(p.first-1, p.second->left));
		}
		if(p.second->right)
		{
			q.push(make_pair(p.first+1, p.second->right));
		}
		
	}
	vector<vector<int>> result;
 	  for (map<int,vector<int> > :: iterator it = m.begin(); it != m.end(); it++) {
        result.push_back(it -> second);
    }
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
	cout<<"hereeee";
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
	vector<vector<int>> v = t.verticalOrderTraversal(t.retRoot());
	vector<vector<int>> :: iterator it;
	for(it = v.begin(); it!= v.end();it++)
	{
		cout<<"\n";
	  show(*it) ;
	}
	return 0;
}



