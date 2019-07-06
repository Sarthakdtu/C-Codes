#include<iostream>
using namespace std;
typedef long long ll;
ll m = 1000000007; 
void multiples(bool *arr, ll a, ll n)
{
	for(ll i= a;i<=n;i+=a)
	{
		arr[i]=true;
	}
	arr[a] = false;
}


void findPrime(ll n, bool*arr)
{
	arr[0]= true;
	arr[1]= true;
	
	for(ll i=2;i*i<=n;i++)
	{
		if(!arr[i])
		{
		  multiples(arr, i, n);	 
		}
	}
	
}


int max_power(ll n, ll a)
{
	int count=0;
	while(n%a==0)
	{
		n=n/a;
		count++;
	}
	return count;
}

ll calcDiv(bool *arr, ll *pow, ll n)
{
	ll p =1;
   	for(ll i =0;i<n+1;i++)
   	{
   	  if(!arr[i])
		 {
		 	p = (p%m * (pow[i]+1)%m)  %m; 
		 }	
    }
    return p;
}

void divisors(ll n)
{
	bool *arr = new bool[n+1]();
	ll *pow  = new ll[n+1]();
	findPrime(n, arr);
	//int sum = 0;
	for(ll i=1;i<n+1;i++)
	{
		if(!arr[i])
		{
			ll k = max_power(n, i);
			//cout<<i<<" "<<k<<endl;
			pow[i] = k;
		}
	}
    cout<<calcDiv(arr, pow, n);
}


int main()
{
	ll n=342;
	divisors(n);
	return 0;
}
