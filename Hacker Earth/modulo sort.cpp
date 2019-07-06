#include<iostream>
#include<vector>
#include<map>
#include<set>
//#define longlong ll
using namespace std;

void input(int n, long long k)
{
	int *arr = new int[n];
	map<long long, vector<int>> mod;
	set<int> index;
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
		long long idx = arr[i]%k;
		mod[idx].push_back(arr[i]);
		index.insert(idx);
	}
	//cout<<endl;
	set<int>:: iterator it;
	int j=0;
	for(it=index.begin();it!=index.end();it++)
	{
		long long idx = *it;
		for(int i=0;i<mod[idx].size();i++)
		{
			arr[j]=mod[idx][i];
			j++;
		}
	}
	
	for(int i=0;i<n;i++)
	{
		cout<<arr[i]<<" ";
	}
	    
}

int main()
{
	int n;
	long long k;
	cin>>n>>k;
	input(n, k);
	return 0;
}

