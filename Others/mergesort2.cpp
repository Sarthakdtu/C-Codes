#include<iostream>
using namespace std;

//sarthak

void merge(int arr[], int start, int end, int mid)
{
  std::cout<<"here";
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



void mergesort(int input[], int start, int end)
{
  
  if(start>=end)
  {
    return ;
  }
  cout<<"here and here";
  int mid = start+(end - start)/2;
  mergesort(input, start, mid-1);
  mergesort(input, mid+1, end);
  merge(input, start, end, mid);
  
}

void mergeSort(int input[], int size){
	// Write your code here
  
  mergesort(input, 0, size-1);
}



int main()
{
	int arr[] = {12,11,10,9,8,7,23,322,333,111,6,5,4,3,2,1,0};
	int *a = arr;
	
	int n =sizeof(arr)/sizeof(arr[0]);
	for(int i =0;i<n;i++)
	cout<<a[i]<<" ";
	cout<<"\n";
	mergeSort(arr,n-1);
	for(int i =0;i<n;i++)
	cout<<a[i]<<" ";
	return 0;
}








