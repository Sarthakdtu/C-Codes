#include<iostream>

using namespace std;

void take_input()
{
	int n;
	long long b;
	cin>>n>>b;
	long long *p = new long long[n];
	long long *w = new long long[n];
	long long *h = new long long[n];
	for(int i=0;i<n;i++)
	{
		cin>>w[i]>>h[i]>>p[i];
	}
	
	long long max=0;
	for(int i=0;i<n;i++)
	{
		long long area =w[i]*h[i];
		
		//cout<<area<<endl;
		if(area>max&&b>=p[i])
		{
		//	cout<<"Going in\n";
			max=area;	
		} 
	}
	if(max==0)
	{
		cout<<"no tablet\n";
		return ;
	}
	cout<<max<<endl;
	return;
}

int main()
{
	int t;
	cin>>t;
	while(t)
	{
		t--;
		take_input();
	}
	return 0;
}

