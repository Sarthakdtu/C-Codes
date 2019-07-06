#include<iostream>
#include<climits>
//SEGMENT TREE FOR MINIMUM VALUE
//Query Indexing is in natural numbers	
using namespace std;
void display(int *tree, int n)
{
	for(int i=1;i<2*n;i++)
	{
		cout<<i<<" : "<<tree[i]<<endl;
	}
	cout<<endl;
}


void buildTree(int *arr, int *tree, int start, int end, int treeNode)
{
	if(start==end)
	{
		tree[treeNode]=arr[start];
		//cout<<"Entering "<<arr[start]<<" at "<<treeNode<<endl;
		return ;
	}
	
	int mid = (end + start)/2;
	//cout<<mid<<endl;
	buildTree(arr, tree, start, mid, 2*treeNode);
	buildTree(arr, tree, mid+1, end, 2*treeNode+1);
	
	tree[treeNode] = min(tree[2*treeNode],tree[2*treeNode+1]);
	return ;
}

void updateTree(int *arr, int *tree, int start, int end, int treeNode, int idx, int value)
{
	if(start==end)
	{
		//cout<<"Changing "<<arr[idx]<<" to "<<value;
		arr[idx] = value;
		tree[treeNode]=value;
		return ;
	}
	
	int mid = (end + start)/2;
	
	if(mid>=idx)
	updateTree(arr, tree, start, mid, 2*treeNode, idx, value);
	else
	updateTree(arr, tree, mid+1, end, 2*treeNode+1, idx, value);
	
	tree[treeNode] = min(tree[2*treeNode],tree[2*treeNode+1]);
	return ;
}

int query(int* tree, int start, int end, int treeNode, int left, int right)
{
	
	//Completely outside given range
	if(start>right||end<left)
	{
		return INT_MAX;
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
    
    return min(ans1,ans2);

}

int main()
{
	int n, q;
	cin>>n>>q;
	int *arr = new int[n];
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	
	int *tree = new int[2*n];
	buildTree(arr, tree, 0, n-1, 1);
	display(tree, n);
	char qoru;
	int left, right, idx, value;
	for(int i=0;i<q;i++)
	{
		cin>>qoru;
		if(qoru=='q')
		{
			cin>>left>>right;//cout<<"Q";
			cout<<query(tree, 0, n-1, 1, left-1, right-1)<<endl;
		}
		else
		{
			cin>>idx>>value;
			updateTree(arr, tree, 0, n-1, 1, idx, value);
		}
		cout<<endl;
		display(tree, n);
	}
	return 0;
}
