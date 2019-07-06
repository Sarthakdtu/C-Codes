/*
You are given a sequence A[1], A[2], ..., A[N] . ( |A[i]| = 15007 , 1 = N = 50000 ).
 A query is defined as follows:
Query(x,y) = Max { a[i]+a[i+1]+...+a[j] ; x = i = j = y }.
Given M queries, your program must output the results of these queries.
Input
The first line of the input file contains the integer N.
In the second line, N numbers follow.
The third line contains the integer M.
M lines follow, where line i contains 2 numbers xi and yi.
Output
Your program should output the results of the M queries, one 
query per line.
Sample Input:
3 
-1 2 3 
1
1 2
Sample Output:
2

*/
#include<iostream>

using namespace std;
typedef long long ll;

struct node
{
	ll maxSum;
	ll bps;
	ll bss;
	ll sum;
};

node retNode(node left, node right)
{
	node ret;
	ll ans = left.sum + right.bps;
	ans = max(ans, left.bss+right.sum);
	ans = max(ans, left.bss + right.bps);
	ans = max(ans, left.sum);
	
	ret.maxSum = ans;
	ret.sum = left.sum+right.sum;
	ret.bss = max(right.bss,right.sum+left.bss);
	ret.bps = max(left.sum+right.bps, left.bps);
	return ret;
}

void display(node *tree, int n)
{
   for(int i = 1;i<2*n;i++)
   {
   	node nod = tree[i];
   	cout<<"Index :"<<i<<endl;
   	cout<<"Sum : "<<nod.sum<<endl;
   	cout<<"bps : "<<nod.bps<<endl;
   	cout<<"bss : "<<nod.bss<<endl;
   	cout<<"MaxSum : "<<nod.maxSum<<endl;
   	cout<<endl;
   }
}

void buildTree(ll *arr, node* tree, ll start, ll end, ll t)
{
	if(start==end)
	{
//		cout<<"At If"<<start<<" "<<endl;
		node nod;
	   ll val = arr[start];
	   	
	   nod.maxSum = nod.bps = nod.bss = nod.sum = val;	
	   tree[t] = nod;
	   return ; 
	}
//	cout<<"At "<<start<<" "<<endl;
	ll mid = (start+end)/2;
//	cout<<"Mid "<<mid<<endl;
	buildTree(arr, tree, start, mid, 2*t);
	buildTree(arr, tree, mid+1, end, 2*t+1);
	
	node left = tree[2*t];
	node right = tree[2*t+1];
	
	tree[t] = retNode(left,right);
}

node query(node* tree, ll start, ll end, ll t, ll l, ll r)
{
	if(start>r||end<l)
	{
		return {0, 0, 0, 0};
	}
	if(start>=l&&end<=r)
	{
		return tree[t];		
	}
	
	ll mid = (start+end)/2;
	node a1 = query(tree, start, mid, 2*t, l, r);
	node a2 = query(tree, mid+1, end, 2*t+1, l, r);
	return  retNode(a1, a2);
}

int main()
{
	ll n,q;
	cin>>n;
	ll *arr = new ll[n+1];
	for(int i=1;i<n+1;i++)
	   cin>>arr[i];
	cin>>q;
	//cout<<"Here";
	node *tree = new node[4*n];
	buildTree(arr, tree, 1, n, 1);
	display(tree, n);
	for(int i=0;i<q;i++)
	{
		//cout<<"loop";
		ll l, r;
		cin>>l>>r;
		cout<<query(tree,1, n, 1, l, r).maxSum<<endl;	
	}
	return 0;
}
