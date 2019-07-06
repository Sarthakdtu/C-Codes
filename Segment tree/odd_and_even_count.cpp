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



void buildTreeOdd(int *arr, int *tree, int start, int end, int treeNode)
{
	if(start==end)
	{
		tree[treeNode]=0;
		if(arr[start]%2 !=0)
		tree[treeNode]=1;
		//cout<<"Entering "<<arr[start]<<" at "<<treeNode<<endl;
		return ;
	}
	
	int mid = (end + start)/2;
	//cout<<mid<<endl;
	buildTreeOdd(arr, tree, start, mid, 2*treeNode);
	buildTreeOdd(arr, tree, mid+1, end, 2*treeNode+1);
	
	tree[treeNode] = tree[2*treeNode]+tree[2*treeNode+1];
	return ;
}

void updateTreeOdd(int *arr, int *tree, int start, int end, int treeNode, int idx, int value)
{
	if(start==end)
	{
		//cout<<"Changing "<<arr[idx]<<" to "<<value;
		arr[idx] = value;
		tree[treeNode]=0;
        if(value%2!=0) 
		tree[treeNode]=1;
		return ;
	}
	
	int mid = (end + start)/2;
	
	if(mid>=idx)
	updateTreeOdd(arr, tree, start, mid, 2*treeNode, idx, value);
	else
	updateTreeOdd(arr, tree, mid+1, end, 2*treeNode+1, idx, value);
	
	tree[treeNode] = tree[2*treeNode]+tree[2*treeNode+1];
	return ;
}



void buildTreeEven(int *arr, int *tree, int start, int end, int treeNode)
{
	if(start==end)
	{
		tree[treeNode]=0;
		if(arr[start]%2==0)
		tree[treeNode]=1;
		//cout<<"Entering "<<arr[start]<<" at "<<treeNode<<endl;
		return ;
	}
	
	int mid = (end + start)/2;
	//cout<<mid<<endl;
	buildTreeEven(arr, tree, start, mid, 2*treeNode);
	buildTreeEven(arr, tree, mid+1, end, 2*treeNode+1);
	
	tree[treeNode] = tree[2*treeNode]+tree[2*treeNode+1];
	return ;
}

void updateTreeEven(int *arr, int *tree, int start, int end, int treeNode, int idx, int value)
{
	if(start==end)
	{
		//cout<<"Changing "<<arr[idx]<<" to "<<value;
		arr[idx] = value;
		tree[treeNode]=0;
        if(value%2==0) 
		tree[treeNode]=1;
		return ;
	}
	
	int mid = (end + start)/2;
	
	if(mid>=idx)
	updateTreeEven(arr, tree, start, mid, 2*treeNode, idx, value);
	else
	updateTreeEven(arr, tree, mid+1, end, 2*treeNode+1, idx, value);
	
	tree[treeNode] = tree[2*treeNode]+tree[2*treeNode+1];
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
	int n, q;
	cin>>n;
	int *arr = new int[n];
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	cin>>q;
	int *evenTree = new int[4*n];
	int *oddTree = new int[4*n];
	buildTreeEven(arr, evenTree, 0, n-1, 1);
	buildTreeOdd(arr, oddTree, 0, n-1, 1);
	//display(tree, n);
	int qoru;
	int left, right, idx, value;
	for(int i=0;i<q;i++)
	{
		cin>>qoru;
		if(qoru==1)
		{
			cin>>left>>right;//cout<<"Q";
			cout<<query(evenTree, 0, n-1, 1, left-1, right-1)<<endl;
		}
		else if(qoru==2)
		{
			cin>>left>>right;//cout<<"Q";
			cout<<query(oddTree, 0, n-1, 1, left-1, right-1)<<endl;
		}
		else
		{
			cin>>idx>>value;
			updateTreeEven(arr, evenTree, 0, n-1, 1, idx-1, value);
			updateTreeOdd(arr, oddTree, 0, n-1, 1, idx-1, value);
		}
		//cout<<endl;
		//display(tree, n);
	}
	return 0;
}
