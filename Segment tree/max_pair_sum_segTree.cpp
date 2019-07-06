/*
You are given a sequence A[1], A[2], ..., A[N],
 ( 0 = A[i] = 10^8 , 2 = N = 10^5 ). 
 There are two types of operations and they are defined as follows:
Update:
This will be indicated in the input by a 'U' followed by space and then two integers i and x.
U i x, 1 = i = N, and x, 0 = x = 10^8.
This operation sets the value of A[i] to x.
Query:
This will be indicated in the input by a 'Q' followed by a single space and then two integers i and j.
Q x y, 1 = x < y = N.
You must find i and j such that x = i, j = y
 and i != j, such that the sum A[i]+A[j] is maximized. Print the sum A[i]+A[j].
Input
The first line of input consists of an integer N 
representing the length of the sequence. 
Next line consists of N space separated integers A[i]. 
Next line contains an integer Q, Q = 10^5, representing the number of operations.
 Next Q lines contain the operations.
Output
 Output the maximum sum mentioned above, in a separate line, for each Query.
Input:
5
1 2 3 4 5
6
Q 2 4
Q 2 5
U 1 6
Q 1 5
U 1 7
Q 1 5
Output:
7
9
11
12

*/
#include<iostream>

using namespace std;
typedef long long ll;

struct node
{
	ll max;
	ll smax;
};

node maxNode(node n1, node n2)
{
	node n3;
	ll maxM = max(n1.max, n2.max);
	ll minM = min(n1.max, n2.max);
	n3.max = maxM;
	ll maxS = max(n1.smax, n2.smax);
	 maxS = max(minM, maxS);
	n3.smax = maxS;
	return n3;
}

void display(node *tree, int n)
{
	cout<<endl;
	for(int i=1;i<2*n+1;i++)
	{
		cout<<tree[i].max<<" "<<tree[i].smax<<endl;
	}
}

void buildTree(ll *arr, node* tree, ll start, ll end, ll t)
{
	if(start==end)
	{
		node nod;
		nod.max=arr[start];
		nod.smax=0;
		tree[t]=nod;
		return ;		
	}
	
	ll mid = (start+end)/2;
	buildTree(arr, tree, start, mid, 2*t);
	buildTree(arr, tree, mid+1, end, 2*t+1);
	tree[t] = maxNode(tree[2*t], tree[2*t+1]);
}

void updateTree(ll *arr, node* tree, ll start, ll end, ll t, ll idx, ll value)
{
	if(start==end)
	{
		arr[idx]=value;
		node nod;
		nod.max=arr[idx];
		nod.smax=0;
		tree[t]=nod;
		return ;		
	}
	ll mid = (start+end)/2;
	
	if(mid>=idx)
	updateTree(arr, tree, start, mid, 2*t, idx, value);
	else
	updateTree(arr, tree, mid+1, end, 2*t+1, idx, value);
	
	tree[t] = maxNode(tree[2*t], tree[2*t+1]);
}

node query(node* tree, ll start, ll end, ll t, ll l, ll r)
{
	if(start>r||end<l)
	{
		node na;
		na.max = na.smax = 0;
		return na;
	}
	if(start>=l&&end<=r)
	{
		return tree[t];		
	}
	
	ll mid = (start+end)/2;
	node a1 = query(tree, start, mid, 2*t, l, r);
	node a2 = query(tree, mid+1, end, 2*t+1, l, r);
	return  maxNode(a1, a2);
}

int main()
{
	ll n,q;
	cin>>n;
	ll *arr = new ll[n+1];
	for(int i=1;i<n+1;i++)
	   cin>>arr[i];
	cin>>q;
	node *tree = new node[4*n];
	buildTree(arr, tree, 1, n, 1);
	
	for(int i=0;i<q;i++)
	{
		//display(tree, n);
		char qoru;
		cin>>qoru;
		if(qoru=='U')
		{
			ll idx, value;
			cin>>idx>>value;
			updateTree(arr, tree, 1, n, 1, idx, value);
		}
		else
		{
			ll l, r;
			cin>>l>>r;
			node a = query(tree, 1, n, 1, l, r);
			ll ans = a.max+a.smax;
			cout<<ans<<endl;
		}
	}
	return 0;
}
