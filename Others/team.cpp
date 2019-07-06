#include<iostream>
#include<map>
#include<algorithm>
using namespace std;
typedef long long ll;
ll m = 1000000007;
int main()
{
	int t;
	cin>>t;
	while(t){
		t--;
	int n;
	cin>>n;
	map<ll, ll> m;
	ll *arr = new ll[n];
	
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
		if(m.count(arr[i])==0)
		{
			m[arr[i]] =1;
		}
		m[arr[i]]++;
	}
	sort(arr, arr+n);
	ll pro =1;
	for(int i=0;i<n-1;i+=2)
	{
		if(arr[i]!=arr[i+1])
		{
			if(m[arr[i]]>=2)
			{
				pro = (pro * m[arr[i]] ) % m;
				m[arr[i]]=1;
			}
		    if(m[arr[i+1]]>=2)
			{
				pro = (pro*m[arr[i+1]]) %m;
				m[arr[i+1]]=1;
			}
		}
	}
	
	cout<<pro<<endl;
}
return 0;
}
