#include<iostream>
using namespace std;
typedef long long ll;


void multiples(ll *arr, ll a, ll n)
{
	ll a3 = a*a*a;
	for(ll i= a3;i<=n;i+=a3)
	{
	
		arr[i]=-1;
	}
}


void findCube(ll n, ll *arr)
{
	arr[0]= 0;
	arr[1]= 1;
	int pos = 1;
	for(ll i=2;i<=n;i++)
	{
		if(arr[i]==0)
		{
			pos++;
		 	multiples(arr, i, n);	 
		 	arr[i] = pos;
		}
	}
//	return arr[n];
}


void cubeFree(ll n, ll* arr)
{	
	findCube(n, arr);	
}
  



void answer(ll *arr, ll n)
{
    if(arr[n]==-1)
    {
      cout<<"Not Cube Free";
    }
    else
    {
       cout<<arr[n];
    }
    cout<<endl;
  }
	



int main()
{
	int n=86;
	ll *arr = new ll[1000000]();
	cubeFree(100000, arr);
	
	answer(arr, n);
	
	
}





