
#include<iostream>
using namespace std;
//sarthak

//sarthak

typedef unsigned long long ll;
ll mod = 1000000007;

void multiply(ll A[2][2], ll M[2][2])
{
    ll fvalue = ((A[0][0]%mod)*(M[0][0]%mod))%mod + ((A[0][1]%mod)*(M[1][0]%mod))%mod;
	ll svalue = ((A[0][0]%mod)*(M[0][1]%mod))%mod + ((A[0][1]%mod)*(M[1][1]%mod))%mod;
    ll tvalue = ((A[1][0]%mod)*(M[0][0]%mod))%mod + ((A[1][1]%mod)*(M[1][0]%mod))%mod;
    ll lvalue = ((A[1][0]%mod)*(M[0][1]%mod))%mod + ((A[1][1]%mod)*(M[1][1]%mod))%mod; 
	
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




unsigned long long fiboSum(unsigned long long n,unsigned long long m)
{
	// Write your code here
 ll Fm= fib(m+2)%mod;
 ll Fn= fib(n+1)%mod;
 
 ll sum = Fm-Fn+mod;
  
  return sum%mod;
  
}



int main()
{
	cout<<fiboSum(19, 10)%mod;
	cout<<10857%mod;
}



