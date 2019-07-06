/*
Given an integer array A of size N, find and return the minimum
 absolute difference between any two elements in the array.
We define the absolute difference between two elements ai, 
and aj (where i != j ) is |ai - aj|.
*/
#include<iostream>

#include<climits>
using namespace std;

void swap(int *arr, int i, int j)
{
	int temp = arr[i];
	arr[i]=arr[j];
	arr[j] = temp;
}

int partition(int *arr, int start, int end)
{
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

void quicksort(int *arr, int start, int end)
{
	if(start>=end)
	{
		return ;
	}
	int p= partition(arr, start,  end);
	quicksort(arr, start, p);
	quicksort(arr, p+1, end);
}

int abs(int a)
{
	if(a<0)
	{
		return -a;
	}
	return a;
}

int main()
{
	int n;
	cin>>n;
	int *arr = new int[n];
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	quicksort(arr, 0, n);
	int min = INT_MAX;
	for(int i=0;i<n-1;i++)
	{
		int curr = abs(arr[i+1]-arr[i]);
		if(min>curr)
		{
			min = curr;
	    }
	}
	cout<<min;
}
