/*
Himani got the idea to make excellent money in the 
stock market. She knows that at the i-th of n days 
she can buy or sell a stock “Envy”, if she wants. 
The price for buying or selling the stock at the i-th day equals to ci.
Unfortunately, Himani is not allowed to have more 
than one stock at some moment of time according to
 stock rules. She firstly has to sell the stock in hand and then may buy the new one.
She has infinite amount of buying power (through loan sharks! Scary!).
Find the maximal amount of profit she can make if array c is determined as follows:
x(0)=0
x(i)=( (x(i-1)) mod M) · a + b ) mod 2^32
c(i)=?x(i)/2^8?
Input format
The first line contains two integers: n and M.
The second line contains two integers: a and b.
Output format
In a single line output the maximum profit Benny can get.
Constraints
2 = n = 107
1 = M = 2^30
1 = a, b = 10^9
Sample Input
5 100500
1 1024
Sample Output
16
*/
#include<iostream>
#include<math>
using namespace std;
typedef long long ll;

ll two30 = pow(2, 32);
ll two8 = 256;

ll func(ll x, ll, m, ll a, ll b)
{
	x = x%m;
	x = x.a+b;
	return x;
}

void findProfit(ll n,ll m,ll a,ll b)
{
	ll *x = new ll[n+1];
	x[0]=0;
	ll *c = new ll[n+1];
	c[0]=0;
	
	for(int i=1;i<n+1;i++)
	{
		x[i]=func(x[i-1], m, a, b);
		c[i]=x[i]/two8;
	}
	
	
}

int main()
{
	ll n, m, a, b;
	cin>>n>>m;
	cin>>a>>b;
	findProfit(n, m, a, b); 
}








