#include<bits/stdc++.h>
using namespace std;
int main() {
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++)
	{
	    cin>>arr[i];
	}
	sort(arr,arr+n);
	vector<int> v;
	int count=0;
	for(int i=0;i<n-1;i++)
	{
	    if(arr[i]!=arr[i+1])
	    {
	        count++;
	    }
	    else
	    {
	        v.push_back(arr[i]);
	    }
	}
	
	
	sort(v.begin(), v.end());
	while(v.size()>1)
	{
		vector<int> v2;
		for(int i=0;i<v.size()-1;i++)
		{
			if(v[i]!=v[i+1])
			{
				count++;
			}
			else
			{
				v2.push_back(v[i]);
			}
		}
		v.clear();
		v= v2;
	}
	cout<<count;
	return 0;
}



