#include<iostream>
using namespace std;
typedef long long ll;

bool card(ll *arr, long n)
{
	long idx=-1;
	if(arr[0]<arr[n-1])
	{
		return false;
	}
	for(int i=0;i<n-1;i++)
	{
		if(arr[i]>arr[i+1])
		{
			idx=i;
			break;
		}
	} 
	
	//if(idx!=-1)
	for(int i=idx+1;i<n-1;i++)
	{
		if(arr[i]>arr[i+1])
		{
			return false;
		}
	}
	
	/*if(idx==-1)
	{
		return false;
	}*/
	
	return true;
}


void func()
{
	long n;
	cin>>n;
	ll *arr = new ll[n];
	for(long i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	bool ans = card(arr, n);
	if(ans)
	{
		cout<<"YES"<<endl;
	}
	else
	{
		cout<<"NO"<<endl;
	}
}

int main()
{
	int t;
	cin>>t;
	while(t){
		t--;
	func();}
	return 0;
}
