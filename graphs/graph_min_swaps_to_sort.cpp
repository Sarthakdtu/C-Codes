#include<bits/stdc++.h>
using namespace std;


void minswaps(int *arr, int n)
{
	pair<int, int> arrPos[n];
	for(int i=0;i<n;i++)
	{
		arrPos[i].first = arr[i];
		arrPos[i].second = i;
	}
	sort(arrPos, arrPos+n);
	vector<bool> vis(n, false);
	int ans =0;
	for(int i =0;i<n;i++)
	{
		if(vis[i]||arrPos[i].second==i)
			continue;
		else
		{
			int cycle=0;
			int j =i;
			while(!vis[j])
			{
				vis[j]=true;
				j = arrPos[j].second;
				cycle++;		
			}
			if(cycle>0)
				ans += (cycle-1);		
		}		
	} 
	cout<<ans;
}


int main()
{
	int n;
	cin>>n;
	int * arr = new int[n];
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	minswaps(arr, n);
	return 0;
}
