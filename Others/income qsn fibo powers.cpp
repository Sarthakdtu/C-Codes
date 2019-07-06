//f(n) = f(n-1) +f(n-2) +f(n-1)*f(n-2)

#include<iostream>
using namespace std;
typedef long long l;
ll mod = 1000000007;

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



void multiply(ll A[2][2], ll M[2][2])
{
	int fvalue = A[0][0]*M[0][0]%mod + A[0][1]*M[1][0]%mod;
	int svalue = A[0][0]*M[0][1]%mod + A[0][1]*M[1][1]%mod;
	int tvalue = A[1][0]*M[0][0]%mod + A[1][1]*M[1][0]%mod;
	int lvalue = A[1][0]*M[0][1]%mod + A[1][1]*M[1][1]%mod;
	
	A[0][0] = fvalue%mod;
	A[0][1] = svalue%mod;
	A[1][0] = tvalue%mod;
	A[1][1] = lvalue%mod;
}

void power(ll A[2][2], ll n)
{
    
	if(n==0||n==1)
	{
		return ;
	}
	
	power(A, n/2);
  
    A[0][0] %= mod;
	A[0][1] %= mod;
	A[1][0] %= mod;
	A[1][1] %= mod;
  
	multiply(A, A);
	if(n%2==1)
	{
	ll M[2][2] = {{1, 1}, {1, 0}};
    A[0][0] %= mod;
	A[0][1] %= mod;
	A[1][0] %= mod;
	A[1][1] %= mod;
		multiply(A, M);
	}
 
}

ll fib(ll n)
{
    
	ll A[2][2] = {{1, 1}, {1, 0}};
	power(A, n-1);
    
	return A[0][0];
}



ll findGn(ll a, ll b, ll n)
{
	ll afib = power(a, fib(n-1)%mod, mod);
	ll bfib = power(b, fib(n)%mod, mod);
	
	return ((afib%m)*(bfib%m))%m;
}

ll findFn()
{
	ll a, b, n;
	cin>>a>>b>>n;
	ll Fn = findGn(a+1, b+1, n)-1;
	cout<<Fn<<endl;
}

int main()
{
	int t;
	cin>>t;
	while(t)
	{
		t--;
		findFn();
	}
	return 0;
}
