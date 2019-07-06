#include<iostream>
//SEGMENT TREE FOR SUM	
using namespace std;

void display(int *tree, int n)
{
	for(int i=1;i<2*n;i++)
	{
		cout<<tree[i]<<endl;
	}
}


void buildTree(int *arr, int *tree, int start, int end, int treeNode)
{
	if(start==end)
	{
		tree[treeNode]=arr[start];
		//cout<<arr[start];
		return ;
	}
	
	int mid = (end + start)/2;
	//cout<<mid<<endl;
	buildTree(arr, tree, start, mid, 2*treeNode);
	buildTree(arr, tree, mid+1, end, 2*treeNode+1);
	
	tree[treeNode] = tree[2*treeNode] + tree[2*treeNode+1];
	return ;
}

void updateTree(int *arr, int *tree, int start, int end, int treeNode, int idx, int value)
{
	if(start==end)
	{
		arr[idx] = value;
		tree[treeNode]=value;
		return ;
	}
	
	int mid = (end + start)/2;
	
	if(mid>=idx)
	updateTree(arr, tree, start, mid, 2*treeNode, idx, value);
	else
	updateTree(arr, tree, mid+1, end, 2*treeNode+1, idx, value);
	
	tree[treeNode] = tree[2*treeNode] + tree[2*treeNode+1];
	return ;
}

int query(int* tree, int start, int end, int treeNode, int left, int right)
{
	
	//Completely outside given range
	if(start>right||end<left)
	{
		return 0;
	}
	//Completely inside given range
	if(start>=left&&end<=right)
	{
		return tree[treeNode];
	}
	//Partially inside given range
	int mid = (end+start)/2;
    int ans1 = query(tree, start, mid, 2*treeNode, left, right);	
    int ans2 = query(tree, mid+1, end, 2*treeNode+1, left, right);
    
    return ans1+ans2;

}

int main()
{
	int n=9;
	int arr[]={1, 2, 3, 4, 5, 6, 7, 8, 9};
	int *tree = new int[2*n];
	buildTree(arr, tree, 0, n-1, 1);
	
	int idx = 3;
	int value = 10;
	display(tree, n);
	cout<<"Updated tree\n";
	updateTree(arr, tree, 0, n-1, 1, idx, value);
	display(tree, n);
	cout<<query(tree, 0, n-1, 1, 2, 6);
	return 0;
}
