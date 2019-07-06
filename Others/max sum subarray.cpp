#include<iostream>
using namespace std;

int maxSumSubarray(int *arr, int n)
{
	int current_sum = 0;
	int best_sum = INT_MIN;
	
	for(int i =0;i<n;i++)
	{
		current_sum += arr[i];
		if(current_sum>best_sum) 
		{
			best_sum  = current_sum;
		}
		if(current_sum<0)
		{
			current_sum =0;
		}
	}
	
	
	cout<<best_sum;

}


int main()
{
	int arr[] = {1,2, -2 , 3, 4, -1, -9, -8, 1, -2, 3, 1};
	int n=12;
	maxSumSubarray(arr, n);
	return 0;
}
