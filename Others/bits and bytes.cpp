
#include<iostream>
using namespace std;
typedef long long ll;
void func(ll *b, ll *n, ll *by, int s)
{
	b[0]=1;
	n[0] =0;
	by[0]=0;
	int tb=0, tby=0, tn=0;
	bool isb=true, isby = false;
	bool isn =false;
	for(int i=1;i<s;i++)
	{	
	
		
		if(isb)
		{
			tb++;
			b[i] = b[i-1];
		}
		if(isn)
		{
			tn++;
			n[i] = n[i-1];
		}
		if(isby)
		{
			tby++;
			by[i] = by[i-1];
		}
		
		if(tb==2)
		{
			n[i]=b[i-1];
			tn=0;
			tb=0;
			b[i] =0;
			isb=!isb;
			isn=!isn;
		}
		if(tby==16)
		{
			b[i]=2*by[i-1];
			tb=0;
			tby=0;
			by[i]=0;
			isby=!isby;
			isb=!isb;
		}
		if(tn==8)
		{
			by[i]=n[i-1];
			tn=0;
			tby=0;
			n[i]=0;
			isby=!isby;
			isn=!isn;
		}
		
		cout<<"At time : "<<i<<endl;
	cout<<b[i]<<" : "<<n[i]<<" : "<<by[i]<<endl;
	}

}

int main()
{
	int n=1300;
	ll *arr  = new ll[1601]();
	ll *arr1 = new ll[1601]();
	ll *arr2 = new ll[1601]();
	func(arr, arr1, arr2, 1601);
	cout<<"Final Answer"<<endl;
	cout<<arr[n-1]<<" : "<<arr1[n-1]<<" : "<<arr2[n-1];
}

/*

#include<iostream>
using namespace std;
typedef long long ll;
void func(ll *b, ll *n, ll *by, ll s)
{
	b[0]=1;
	n[0] =0;
	by[0]=0;
	int tb=0, tby=0, tn=0;
	bool isb=true, isby = false;
	bool isn =false;
	for(int i=1;i<s;i++)
	{	
		if(isb)
		{
			tb++;
			b[i] = b[i-1];
		}
		if(isn)
		{
			tn++;
			n[i] = n[i-1];
		}
		if(isby)
		{
			tby++;
			by[i] = by[i-1];
		}
		
		if(tb==2)
		{
			n[i]=b[i-1];
			tn=0;
			tb=0;
			b[i] =0;
			isb=!isb;
			isn=!isn;
		}
		if(tby==16)
		{
			b[i]=2*by[i-1];
			tb=0;
			tby=0;
			by[i]=0;
			isby=!isby;
			isb=!isb;
		}
		if(tn==8)
		{
			by[i]=n[i-1];
			tn=0;
			tby=0;
			n[i]=0;
			isby=!isby;
			isn=!isn;
		}
	
	}

}

int main()
{
	int t;
	cin>>t;
	ll *arr  = new ll[1601]();
	ll *arr1 = new ll[1601]();
	ll *arr2 = new ll[1601]();
	func(arr, arr1, arr2, 1601);
	while(t)
	{
	t--;
	int n;
	cin>>n;
	//cout<<"Final Answer"<<endl;
	cout<<arr[n-1]<<" "<<arr1[n-1]<<" "<<arr2[n-1];
	cout<<endl;
	}
	return 0;
}
*/
