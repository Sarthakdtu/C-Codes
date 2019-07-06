#include<bits/stdc++.h>

using namespace std;

int knapsackRec(int *v, int *w, int maxW, int n)
{
    if(n<=0)
        return 0;
    else if (maxW<=0)
    {
        return 0;
    }
    else
    {
    	//cout<<"At n = "<<n<<endl;
        int a1=0;
        if(w[0]<=maxW)
		  a1 = knapsackRec(v+1, w+1, maxW-w[0], n-1)+v[0];
        int a2 = knapsackRec(v+1, w+1, maxW, n-1);
        return max(a1, a2);
    }
}

int knapsackDp(int *v, int *w, int maxW, int n)
{
    int dp[n+1][maxW+1];

    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=maxW;j++)
        {
            if(i==0||j==0)
                dp[i][j]=0;
            else
            {
                int a1=0;
                if(w[i-1]<=j)
                    a1 = dp[i-1][j-w[i-1]]+v[i-1];
                int a2 = dp[i-1][j];   
                dp[i][j]=max(a1, a2); 
            }   
        }
    }
    return dp[n][maxW];
}

int KnapSack(int val[], int wt[], int n, int W) 
{ 
    // array to store final result 
    //dp[i] stores the profit with KnapSack capacity "i" 
    int dp[W+1]; 
      
    //initially profit with 0 to W KnapSack capacity is 0 
    memset(dp, 0, sizeof(dp)); 
  
    // iterate through all items 
    for(int i=0; i < n; i++)  
        //traverse dp array from right to left 
        for(int j=W; j>=wt[i]; j--) 
            dp[j] = max(dp[j] , val[i] + dp[j-wt[i]]); 
    /*above line finds out maximum of dp[j](excluding ith element value) 
      and val[i] + dp[j-wt[i]] (including ith element value and the 
      profit with "KnapSack capacity - ith element weight") */    
    return dp[W]; 
} 

int main()
{
    int n;
    cin>>n;
    int *value = new int[n];
    int * weight = new int[n];
    for(int i=0;i<n;i++)
        cin>>weight[i];
    for(int i=0;i<n;i++)
        cin>>value[i];    
    int maxW;
    cin>>maxW;
    cout<<knapsackRec(value, weight, maxW, n);  
    cout<<knapsackDp(value, weight, maxW, n);  
}
