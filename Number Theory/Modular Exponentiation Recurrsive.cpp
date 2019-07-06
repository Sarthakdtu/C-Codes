#include<iostream>
using namespace std;
typedef long long ll;

ll modularExpo(ll a, ll b, ll c)
{
	if(b==0)
	{
		return 1;
	}
	if(b%2==0)
	{
		return modularExpo((a*a)%c, b/2, c);
	}
	else
	{
		return (modularExpo((a*a)%c, (b-1)/2, c)%c * a%c);
	}
	
	
}

int main()
{
	cout<<modularExpo(12,6 ,10000000007 );
}
