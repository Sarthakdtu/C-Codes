#include<iostream>
#include<math.h>
#include<iomanip>
using namespace std;

void multiples(bool *arr, int a, int n)
{
	for(int i= a;i<=n;i+=a)
	{
		arr[i]=true;
	}
	arr[a] = false;
}

bool checkPrime(int n)
{
	int count =0;
	for(int i=2;i*i<=n;i++)
	{
		if(n%i==0)
		{
			count++;
			if(i*i!=n)
			{
				count++;
			}
		}
		if(count>1)
		{
			return false;
		}
	}
	return true;
}

void findPrime(int n, bool*arr)
{
	arr[0]= true;
	arr[1]= true;
	
	for(int i=2;i*i<=n;i++)
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

void showPrime(bool *arr, int n)
{
	for(int i=0;i<=n;i++)
	{
		if(!arr[i])
		{
			cout<<setw(5)<<i<<" , ";
		}
	}
	cout<<endl;
}

int main()
{
	int n = 68;
	bool *arr = new bool[n+1]();
	findPrime(n, arr);
	showPrime(arr, n);
	
	return 0;
}
