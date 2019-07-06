#include<bits/stdc++.h>
using namespace std;

void update_tree(int *arr, int *tree, int start, int end, int left, int right, int treeNode, int k, int add)
{
	cout<<start<<" , "<<end<<endl;
	if(start>left||end<right)
	{
		cout<<"Returing"<<endl;
		//arr[start]++;
		return ;
	}
	if(start==end&&start>=left&&start<=right)
	{
		arr[start] += add;
		//tree[treeNode]=1;
		if(arr[start]==k)
			{
				tree[treeNode]=1;
				cout<<"Changing Height"<<endl;
			}	
		else
			tree[treeNode]=0;	
		return ;		
	}
	
		int mid =(start+end)/2;
		cout<<"Mid : "<<mid<<endl;
		cout<<"Callin ut for "<<start<<" "<<mid<<endl;
		update_tree(arr, tree, start, mid, left, right, 2*treeNode, k, add);
		cout<<"Callin ut for "<<mid+1<<" "<<end<<endl;
		update_tree(arr, tree, mid+1, end, left, right, 2*treeNode+1, k, add);
		
		tree[treeNode] = tree[2*treeNode] + tree[2*treeNode+1];
		return ;	
}

void take_input()
{
	int n,op,k;
	cin>>op>>k;
	n=1000000;
	int *arr = new int[n]();
	int *tree = new int[2*n];
	//cout<<"n is "<<n;
	//build_tree(arr, tree, 0, n, 1);
	int *l = new int[n];
	int *r = new int[n];
	for(int i=0;i<op;i++)
	{
		cin>>l[i]>>r[i];
		cout<<"Inc Height from "<<l[i]<<" to "<<r[i]<<endl;
		update_tree(arr, tree, 0, n-1, l[i], r[i], 1, k, 1);
	}
	int max=0;
	for(int i=0;i<op;i++)
	{
		int *arr2 = arr;
		//update(arr2, tree, l[i]-1, r[i]-1, 1, k);	
		update_tree(arr2, tree, 0, n-1, l[i], r[i], 1, k, -1);
		int curr = tree[1];
		if(max <curr)
		{
			max=curr;
		}
	}
	cout<<max<<endl;
}


int main()
{
	int t;
	cin>>t;
	while(t)
	{
		t--;
		take_input();
	}
	return 0;
}
