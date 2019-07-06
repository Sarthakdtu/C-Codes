#include<iostream>

using namespace std;

void add(long *d, int i, long t)
{
	d[i]   -= t; 
	d[i+1] -= t*2;
	d[i+2] -= t*3;
}


int magic()
{
	int n ;
	cin>>n;
	long *a = new long[n];
	long *b = new long[n];
	long *d = new long[n];
	
   	for(int i=0;i<n;i++)
	  cin>>a[i];
	
	for(int i=0;i<n;i++)
	  {
	  	cin>>b[i];
	  	d[i] = b[i] - a[i];
	  }
	  
	for(int i=0;i<n-2;i++)
	{
		if(d[i]<0)
		{
			return -1;
		}
		
		if(d[i]>0)
		{
			long t = d[i];
			add(d, i, t);
		}
	}
	  
	if(d[n-1]==0&&d[n-2]==0)
	{
	   return 1;	
	}  
	  
	return 0;  
}


int main()
{
    int t;
    cin>>t;
    while(t)
    {
    	t--;
    	if(magic()==1)
    	{
    		cout<<"TAK";
		}
		else
		{
			cout<<"NIE";
		}
		cout<<endl;
    	
	}
	return 0;	
}
