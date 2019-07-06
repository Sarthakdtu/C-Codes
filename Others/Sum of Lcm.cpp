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

ll* EulerTotientFn()
{
	ll n = 1000000;
	
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
	
return arr;
}


void findSum(ll *arr)
{
	ll n;
	cin>>n;
	ll sum = 1;
	for(ll i=1;i<=n;i++)
	{
		if(n%i==0)
		sum+= arr[i]*i;
	}
	sum = (sum*n)/2;
	cout<<sum<<endl;
}

int main()
{
	ll *arr = EulerTotientFn();
	findSum(arr);
	
}
