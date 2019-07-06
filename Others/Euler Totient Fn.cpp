#include<iostream>
using namespace std;
typedef long long ll;

void multiples(ll *arr, ll p, ll n)
{
	for(ll i=2*p;i<n+1;i+=p)
	{
		arr[i] = arr[i]*(p-1);
		arr[i] = arr[i]/p;
	}
}

void EulerTotientFn()
{
	ll n;
	cin>>n;
	ll *arr = new ll[n+1];
	for(ll i=0;i<n+1;i++)
	{
		arr[i] = i;
	}
	
	for(ll i =2;i<n+1;i++)
	{
		if(arr[i]==i)
		{
			arr[i] = i-1;
			multiples(arr, i, n);
		}
	}
	
	for(ll i=1;i<n+1;i++)
	{
		cout<<i<<" : "<<arr[i]<<endl;
	}
}


int main()
{
	EulerTotientFn();
}
