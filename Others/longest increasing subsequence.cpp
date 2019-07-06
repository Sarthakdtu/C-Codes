#include<iostream>
using  namespace std;

int lis(int *arr, int n, int *dp)
{
	int max =0;
	for(int i = 0;i<n;i++)
	{
		int original = dp[i];
		for(int j=i-1;j>-1;j--)
		{
			if(arr[j] < arr[i])
			{
				int possible = original + dp[j];
				if(possible>dp[i])
				{
					dp[i] = possible;
				}
			}
		}
		if(dp[i]> max)
		{
			max = dp[i];
		}
	}
	return max;
}


int lis(int *arr, int n)
{
	int *dp = new int[n];
	for(int i=0;i<n;i++)
	{
		dp[i] = 1;
	}
	
	return lis(arr, n, dp);
}


int lds(int *arr, int n, int *dp)
{
	int max =0;
	for(int i = 0;i<n;i++)
	{
		int original = dp[i];
		for(int j=i-1;j>-1;j--)
		{
			if(arr[j] > arr[i])
			{
				int possible = original + dp[j];
				if(possible>dp[i])
				{
					dp[i] = possible;
				}
			}
		}
		if(dp[i]> max)
		{
			max = dp[i];
		}
	}
	return max;
}


int lds(int *arr, int n)
{
	int *dp = new int[n];
	for(int i=0;i<n;i++)
	{
		dp[i] = 1;
	}
	
	return lds(arr, n, dp);
}


int main()
{
	
	int n =10;
	int *arr = new int[n];
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	
	cout<<"LIS is "<<lis(arr, n);
	cout<<"\nLDS is "<<lds(arr, n);
	return 0;
}
