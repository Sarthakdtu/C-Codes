#include<iostream>
#include<string.h>
using namespace std;


int findMod(string s, int m)
{
	if(s.size()==0)
	{
		return 0;
	}
	
	string sub = s.substr(0, s.size()-1);
	int last = (int)s[s.size()-1] -'0';
	int ans = (((findMod(sub, m)) * (10%m))%m + last%m)%m;
	cout<<s<<" "<<sub<<" "<<last<<" "<<ans<<" "<<endl;
	return ans;
}

int gcdAdv(int a, int b)
{
	if(a<b)
	{
	 return gcdAdv(a, b%a);	
	}
	if(b==0)
	{
		return a;
	}
	return gcdAdv(b, a%b);
}

int gcd(string s, int b)
{
	int a = findMod(s, b);
	if(a==0)
	return b;
	return gcdAdv(a, b);
}


int main()
{
	string s="6888888888888888888888";
	int b = 2;
	cout<<gcd(s, b);
	return 0;
}

