#include<iostream>
using namespace std;



void merge(int *arr, int start, int end, int mid)
{
	int l =mid-start +1;
	int r =end-mid;
	int *left = new int[l];
	int *right = new int[r];
	
	
	
	for(int i =0;i<l;i++)
	left[i] = arr[start+i];
	
	for(int i =0;i<r;i++)
	right[i] = arr[i+mid+1];
	

	int i = 0;
	int j = 0;
	int k = start;
	
	while(i<l&&j<r)
	{
		if(left[i]<right[j])
		{
			arr[k]=left[i];
			i++;
		}
		else
		{
			arr[k]= right[j];
			j++;
		}
		k++;
	}
	
	while(i<l)
	{
		arr[k] = left[i];
		i++;
		k++;
	}
	while(j<r)
	{
		arr[k] = right[j];
		j++;
		k++;
	}
	
}
void mergesort(int *arr,int start, int end)
{
	if(start >= end)
	{
		return ;
	}
	else
	{
	int mid=(start+end)/2;
	
		mergesort(arr, start, mid);
		mergesort(arr,mid+1,end);
		merge(arr, start, end , mid);
		
	}
	
}

int main()
{
	int arr[] = {12,11,10,9,8,7,23,322,333,111,6,5,4,3,2,1,0};
	int *a = arr;
	
	int n =sizeof(arr)/sizeof(arr[0]);
	for(int i =0;i<n;i++)
	cout<<a[i]<<" ";
	cout<<"\n";
	mergesort(arr,0, n-1);
	for(int i =0;i<n;i++)
	cout<<a[i]<<" ";
	return 0;
}











