#include<iostream>
#include<vector.h>
using namespace std;



bool findPair(vector<int> v, int s)
{
	bool *dp = new bool[s+1]();
	for(int i=0;v[i]<s;i++)
	{
		if(2*v[i]==s)
		{
			return true;
		}
		int temp = s- v[i];
		if(dp[temp]){
			//cout<<temp<<" "<<v[i];
			return true;
		}
		   
		dp[v[i]] = true;   
	}
	return false;
}

void multiples(int *arr, int a, int n, int s)
{
	for(int i=a;i<n+1;i+=a)
	{
		//cout<<"Adding "<<s<<" to "<<i<<endl;
		arr[i]+=s; 
	}
}

void findSemiPrime(int *arr, int n)
{
	for(int i=2;i<(n+1);i++)
	{
		
		if(arr[i]==0)
		{
			//arr[i] = 1;
			multiples(arr, i, n, 1);
		}
		else if(arr[i]==2)
		{
			arr[i] -=3; 
			multiples(arr, i, n, 3);
		}
	}
}



int main()
{
	int t;
	cin>>t;
	
	int *arr = new int[200]();
	findSemiPrime(arr, 199);
	vector<int> v;
	for(int i=2;i<200;i++)
	{	
		if(arr[i]==2)
		   v.push_back(i);
	}
	
	while(t)
	{
		t--;
		int n;
		cin>>n;
		bool exist = findPair(v, n);
		if(exist)
		{
			cout<<"YES";
		}
		else
		{
			cout<<"NO";
		}
		cout<<endl;
	}
		
	return 0;
}


