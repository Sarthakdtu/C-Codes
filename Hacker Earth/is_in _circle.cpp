#include<bits/stdc++.h>

using namespace std;

typedef long long ll;


ll inCircle(double* coord, double r, int n)
{
	ll ans=0;
	ll start =0;
	//cout<<"Size = "<<coord.size()<<"n = "<<n;
	ll end =n-1;
	int count = 0;
	while(start<=end)
	{
		count++;
		ll mid = (end-start)/2 +start;
		
		if(coord[mid]<=r)
			start = mid+1;
		else
			end = mid-1;	
	}
	//cout<<"\nCount "<<count<<endl;
	ans = end;
	return ans+1;
}

void take_query(double* coord,int n)
{
	ll q;
	cin>>q;
	for(int i=0;i<q;i++)
	{
		double r;
		cin>>r;
		cout<<inCircle(coord, r, n)<<endl;
	}
}

int main()
{
	int n;
	cin>>n;
	double* coord = new double[n];
	for(int i=0;i<n;i++)
	{
		ll a, b;
		cin>>a>>b;
		coord[i] =sqrt((a*a) + (b*b));
	}
	sort(coord, coord+n);
	/*for(int i=0; i<coord.size(); i++){
		cout<<coord[i].sqr<<" ";
	}*/
	//cout<<endl;
	take_query(coord, n);
	return 0;
}

