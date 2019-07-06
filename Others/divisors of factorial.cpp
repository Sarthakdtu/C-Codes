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
			 //There is no need to check for prime as 
			 //all those numbers which are composite will 
			 //already be marked true by their factors.
			 	multiples(arr, i, n);	 
		}
	}
	
}


int max_power(ll n, ll a)
{
	int count=0;
	while(n>=a)
	{
		n=n/a;
		count++;
	}
	return count;
}

ll calcDiv(bool *arr, ll *pow, ll n)
{
	ll p =1;
   	for(ll i =2;i<n+1;i++)
   	{
   	  if(!arr[i])
		 {
		 	//p = (p%m * (pow[i]+1)%m)  %m; 
		 	p = ((p) * ((pow[i]+1)));
		 	cout<<p<<" ";
		 }	
    }
    return p;
}


ll pow(ll a, ll k)
{
	ll p =1;
	for(ll i =0;i<k;i++)
	{
		p*=a;
	}
	//cout<<p<<" Power"<<endl;
	return p;
}

ll sumUpToK(ll p, ll k, ll n)                 //something's wron with this function
{
	ll pk = pow(p, k);
	cout<<pk<<" "<<k<<" "<<n<<" "<<p<<endl;
	ll ans = (((1-pk)/(1-p))*n)/pk;
	cout<<p<<" "<<ans<<endl;
	return ans;
}

ll sumUpToK2(ll p, ll k, ll n)
{
	ll ans = 0;
	ll f = p;
	for(int i=1;i<k+1;i++)
	{
		ans= ans+ (n/f);
		f*=p;
	}
	return ans;
}



void divisors(ll n)
{
	bool *arr = new bool[n+1]();
	ll *pow  = new ll[n+1]();
	findPrime(n, arr);
	//int sum = 0;
	for(ll i=1;i<n+1;i++)
	{
		if(!arr[i])                   //prime
		{
			ll k = max_power(n, i);
			//if(k!=0)
			k = sumUpToK2(i, k, n);
			cout<<i<<" "<<k<<endl;
			pow[i] = k;
		}
	}
    cout<<calcDiv(arr, pow, n);
}


int main()
{
	ll n=46;
	divisors(n);
	return 0;
}
