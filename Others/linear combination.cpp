#include<iostream>
using namespace std;
typedef long long ll;
class Triplet
{
	public:
		ll x;
		ll y;
		ll g;
};


ll gcd(ll a, ll b)
{
	if(b>a)
	{
		return gcd(a, b%a);
	}
  if(b==0)
  {
    return a;
  }
  return gcd(b, a%b);
}


Triplet gcdExtended(ll a, ll b)
{
	if(b==0)
	{
		Triplet myans;
		myans.g = a;
		myans.x = 1;
		myans.y = 0;
		return myans;
	}
	Triplet sans = gcdExtended(b, a%b);
	Triplet myans;
	myans.x = sans.y;
	myans.y = sans.x - sans.y*(a/b);
	myans.g = sans.g;
	return myans;
	
}


ll findModInv(ll a, ll m)
{
	ll ans = gcdExtended(a, m).x;

    ans = ( (ans%m) + m)%m;
	return ans;
}


ll findLinearCombo(ll a, ll b, ll d)
{
   ll g = gcd(a,b);
   if(d%g>0)
    {
     return 0;
    }
    
    a= a/g;
    b= b/g;
    d= d/g;
	ll mi = findModInv(b,a);
	
	ll y1 = ((d%a) * mi ) % a;
	
	if(d<b*y1)
	{
		return 0;
	}
	ll n = (d/b - y1)/a;
	return n+1;
}

int main()
{
   	int a, b, d;
   	a=6, b=5, d=37;
   	
   	cout<<findLinearCombo(a,b,d);
   	
	return 0;
}



