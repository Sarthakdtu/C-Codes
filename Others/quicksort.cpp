#include<iostream>
using namespace std;

void swap(int *arr, int i, int j)
{
	int temp = arr[i];
	arr[i]=arr[j];
	arr[j] = temp;
}

int partition(int *arr, int start, int end)
{
	
	cout<<"\nArray : ";
   for(int i =start;i<end;i++)
	cout<<arr[i]<<" ";
	cout<<"\n";	
	int key = arr[end-1];
	int i= start-1;
	for(int j = start;j<end;j++)
	{
		if(arr[j]<key)
		{
			i++;
			swap(arr,i, j);
		}
	}
	swap(arr, i+1, end-1);
	return i+1;
}
void quicksort(int *arr,int start, int end)
{
	if(start >= end)
	{
		return ;
	}
	else
	{
		int p = partition(arr, start, end);
		quicksort(arr, start, p);
		quicksort(arr, p+1, end);
	}
	
}

int main()
{
	int arr[] = {1,2,3,0,4,10,50,20,30,70,5,6,7,78,101,100,220,9};
	int *a = arr;
	
	int n =sizeof(arr)/sizeof(arr[0]);
	for(int i =0;i<n;i++)
	cout<<a[i]<<" ";
	quicksort(arr,0, 18);
	for(int i =0;i<n;i++)
	cout<<a[i]<<" ";
	return 0;
}











