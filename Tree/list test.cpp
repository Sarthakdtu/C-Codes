#include<iostream>
#include<list>

using namespace std;
struct node
{
	int data;
	node* left;
	node* right;
};
int main()
{
	list<node*> l;
	node* n;
	n->data=1;
	n->left=NULL;
	n->right=NULL;
	l.push_back(n);
	return 0;
}
