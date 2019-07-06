#include<iostream>
using namespace std;


int main()
{
	int n= 10;
	int skip=0;
	//int *arr=new int[n];
	int arr[10] = {1,1,2,2,5,5,6,7,9,9};
	
	for(int i=0;i<n;i++)
	{
		cout<<" "<<arr[i];
	}
	cout<<endl;
	for(int i=0;i<n-1;i++)
	{
		if(arr[i]==arr[i+1])
		{
			arr[i]=INT_MIN;
			skip++;
		}
	}
	int k=0;
	int *a= new int[n-skip];
	for(int i=0;i<n;i++)
	{
		if(arr[i]!=INT_MIN)
		{
			a[k]=arr[i];
			k++;
		}
	}
	
	for(int i=0;i<n-skip;i++)
	{
		cout<<" "<<a[i];
	}
	return 0;
}

