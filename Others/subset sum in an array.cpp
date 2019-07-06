#include<iostream>
using namespace std;
int count=0;
int subset(int *arr, int **dp, int n, int sum)
{
	if(n==0)
	return 0;
	
	if(sum==0)
	{
		cout<<"Found one at "<<arr[0]<<endl;
		count++;
		return 1;
	}
	if(dp[sum][n]>0)
	{
		return dp[sum][n];
	}
	else
	{
		int op1 =0, op2=0;
		if(sum-arr[0]>-1)
		{
			cout<<"Calculating Sum : "<<sum<<" at size :"<<n<<" arr[0] "<<arr[0]<<endl;
			op1 = subset(arr+1, dp, n-1, sum-arr[0]);
		}
		
		cout<<"Calculating Sum : "<<sum<<" at size :"<<n<<" without arr[0] "<<endl;
		op2 = subset(arr+1, dp, n-1, sum);
		dp[sum][n]=op1+op2;
		return op1+op2;
	}
}

void findSS(int *arr, int n, int sum)
{
	int **dp = new int*[sum+1];
	for(int i=0;i<sum+1;i++)
	{
		dp[i] = new int[n+1]();
	}
	
	for(int i=0;i<n+1;i++)
	{
		dp[0][i] = 1;
	}
	cout<<subset(arr, dp, n, sum);
	cout<<"\n"<<count;
}


int main()
{
    int n;
	cin>>n;
	int *arr = new int[n];
	for(int i=0;i<n;i++)
	cin>>arr[i];
	cout<<endl;
	int sum;
	cin>>sum;
	findSS(arr, n, sum);
	return 0;
}
