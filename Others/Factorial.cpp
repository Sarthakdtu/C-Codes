
//sarthak


#include<bits/stdc++.h>
using namespace std;

typedef unsigned long long ll;

ll power(ll a, ll b, ll c)
{
	if(b==0)
	{
		return 1;
	}
	else
	{
		if(b%2==0)
		{
			return power((a*a)%c, b/2, c);
		}
		else
		{
			return (a%c * power((a*a)%c, b/2, c)%c);
		}
	}
	
}

ll modP(ll a, ll m)
{
	return power(a, m-2, m)%m;
}


ll factorial(ll n, ll p)
{
	ll ans = 1;
	for(ll i=n+1;i<p;i++)
	{
		ans = (ans%p)*(modP(i, p)%p);
        ans = ans%p;
	}
	//ans= ans%p;
	return p-ans;
}


int main()
{
  int t;
  cin>>t;
  while(t)
  {
    t--;
    ll n, p;
	cin>>n>>p;
    if(n<p)
	cout<<factorial(n, p)<<endl;
    else
      cout<<0<<endl;
  }
	
}
