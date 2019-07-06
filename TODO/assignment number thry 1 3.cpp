/*
Vova again tries to play some computer card game.
The rules of deck creation in this game are simple. 
Vova is given an existing deck of n cards and a magic number k.The order of the cards in the deck is fixed. 
Each card has a number written on it; number ai is written on the i-th card in the deck.
After receiving the deck and the magic number, Vova removes x (possibly x?=?0) cards from 
the top of the deck, y (possibly y?=?0) cards from the bottom of the deck, and the rest of 
the deck is his new deck (Vova has to leave at least one card in the deck after removing cards). 
So Vova's new deck actually contains cards x?+?1, x?+?2, ... n?-?y?-?1, n?-?y from the original deck.
Vova's new deck is considered valid iff the product of all numbers written on the cards 
in his new deck is divisible by k. So Vova received a deck (possibly not a valid one) 
and a number k, and now he wonders, how many ways are there to choose x and y so 
the deck he will get after removing x cards from the top and y cards from the bottom is valid?

*/

#include<iostream>
#include<map.h>
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


map<ll> divisors(ll n, map<int> &m)
{
	bool *arr = new bool[n+1]();

	findPrime(n, arr);
	//int sum = 0;
	for(ll i=1;i<n+1;i++)
	{
		if(!arr[i])
		{
			ll k = max_power(n, i);
			m[i] = k;
			//cout<<i<<" "<<k<<endl;
		}
	}
    
}


ll goPointers(map<ll> m, ll k, ll *arr, ll n)
{
	int i=0, j=0;
	while(i<= n)
	{
		if(arr[i])
		{
		  
		}
	}
	
	
	
}

void findDeck(ll k,int* arr, int n)
{
	map<ll> m;
	divisors(k, m);
	goPointers(m, k, arr, n);
	
}


int main()
{
	
	
	
	
	return 0;
}









