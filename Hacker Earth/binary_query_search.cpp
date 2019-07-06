/*
Monk and his friend Micro are on a quest to find the answer of Life, Universe and Everything. In order to complete it they need to answer Q queries on an array A having N integers. The queries can be of following two types:
0x: Find the number of numbers in A which are not less than x.
1x: Find the number of numbers in A which are greater than x.
Help them complete the quest and be back in time for the next Code Monk Challenge.

Input Format:
First line consists of a single integer denoting N.
Second line consists of N space separated integers denoting the array A.
Third line consists of a single integer denoting Q.
Each of the following Q lines consists of a query of one of the given two types.

Output Format: 
For each query print the required answer in new line.

Constraints:

n<10^5
q<3x10^5
A[i], x <10^9
 
SAMPLE INPUT 
4
1 2 3 4
3
0 5
1 3
0 3
SAMPLE OUTPUT 
0
1
2

*/

#include<iostream>
#include<algorithm>

using namespace std;
typedef long long ll;

void query0(ll *arr, int n, ll x)
{
	int start = 0;
	int end = n;
	while(start<end)
	{
		int mid = (end-start)/2 +start;
		if(arr[mid]>=x)
			end = mid;
		else
			start = mid+1;				
	}
	ll ans = n-start;
	cout<<ans<<endl;
	//cout<<"done0"<<endl;
}

void query1(ll *arr, int n, ll x)
{
	int start = 0;
	int end = n;
	while(start<end)
	{
		int mid = (end-start)/2 +start;
		if(arr[mid]<=x)
			start = mid+1;
		else
			end = mid;				
	}
	ll ans = n-start;
	cout<<ans<<endl;
	//cout<<"done1"<<endl;
}


void solve_query(ll *arr, int q, int n)
{
	for(int i=0;i<q;i++)
	{
		ll x, type;
		cin>>type>>x;
		//cout<<"At query "<<i<<endl;
		if(type)
			query1(arr, n, x);
		else
			query0(arr, n, x);	
	}
}

int main()
{
	int n;
	cin>>n;
	ll * arr = new ll[n];
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	sort(arr, arr+n);
	int q;
	cin>>q;
	solve_query(arr, q, n);
	return 0;
}
