#include<iostream>
using namespace std;

void shiftZero(int *a, int n)
{
	int z=0;
	int p =0;
	while(p<n&&z<n)
	{
		while(z<n&&a[z]!=0)
		{
			z++;
		}
		p=z+1;
		while(p<n&&a[p]==0)
		{
			p++;
		}
		if(p<n&&z<n)
		{
		int temp = a[z];
		a[z]=a[p];
		a[p] =temp;
    	}
	}
	cout<<"\n";
}

int main()
{
	int arr[] = {1,2,3,0,4,0,0,0,0,0,5,6,7,8,0,0,0,9};
	int *a = arr;
	
	int n =sizeof(arr)/sizeof(arr[0]);
	for(int i =0;i<n;i++)
	cout<<a[i]<<" ";
	shiftZero(arr, 18);
	for(int i =0;i<n;i++)
	cout<<a[i]<<" ";
	return 0;
}











