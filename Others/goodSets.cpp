#include<iostream>

using namespace std;


void findGoodSets(int *arr, int n)
{
	arr[0]= 0;
	//arr[1]= 1;
	int sum =0;
	for(int i=1;i<=n;i++)
	{
		if(arr[i]>0)	
		   {
		   	cout<<i<<" is "<<arr[i]<<endl;
		   	 for(int j=2*i; j<=n;j+=i)
		   	 {
		   	 	cout<<j<<" is "<<arr[j]<<endl;
		   	    	if(arr[j]>0)
		   	    	{
		   	    		cout<<"Here at "<<j<<endl;
		   	    	  	arr[j] = arr[j] + arr[i];
					}
			 }
		   }
		   sum = arr[i]+sum;
	}
	
	cout<<"Sum is "<<sum;
}

int main()
{
	int n = 2;
	int * arr2 = new int[n];
	int max =0;
	for(int i=0;i<n;i++)
	{
	  int a;
	  cin>>a;
	  arr2[i] = a;
	  if(a>max)
	  {
	  	max = a;
	  }
	}
	int * arr = new int[max+1]();
	for(int i=0; i<n; i++)
	{
	  arr[arr2[i]] = 1;
	  //cout<<arr2[i]<<" is "<<1<<endl;
	}
	
	findGoodSets(arr, max);
	
	return 0;
}
