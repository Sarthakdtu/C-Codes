#include<iostream>

using namespace std;
struct node
{
	int data;
	node *left;
	node *right;
};

node* insert(int val, node *root)
{
	if(root==NULL)
	{
		//cout<<"Creating new node\n";
		root = new node;
		root->data = val;
		root->left =NULL;
		root->right=NULL;
		return root;		
	}
	else
	{
		if(val>root->data)
		{
			//cout<<"Right\n";
			root->right = insert(val, root->right);
		}
		else
		{
			//cout<<"Left\n";
			root->left = insert(val, root->left);
		}
	}
	return root;
}

int height(node *root)
{
	if(root==NULL)
	{
		return 0;
	}
	int lh = height(root->left);
	int rh = height(root->right);
	return max(lh+1, rh+1);
}


int main()
{
	int n;
	cin>>n;
	node *root=NULL;
	for(int i=0;i<n;i++)
	{
		int val;
		cin>>val;
		root = insert(val, root);
		//cout<<"Done"<<endl;
	}
	//cout<<"Done";
	cout<<height(root);
	return 0; 
}

