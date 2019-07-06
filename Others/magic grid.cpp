#include <bits/stdc++.h>
using namespace std;


//sarthak??????????


int solve(int **dp, int **points, int m, int n)
{
  for (int i = m-2; i >= 0; i--) 
         dp[i][n-1] = max(dp[i+1][n-1] - points[i][n-1], 1); 
  
    for (int j = n-2; j >= 0; j--) 
         dp[m-1][j] = max(dp[m-1][j+1] - points[m-1][j], 1); 
  
    
    for (int i=m-2; i>=0; i--) 
    { 
        for (int j=n-2; j>=0; j--) 
        { 
            int min_points = min(dp[i+1][j], dp[i][j+1]); 
            dp[i][j] = max(min_points - points[i][j], 1); 
        } 
     } 
  
  
    return dp[0][0];
  
  
}

int matrix(int **mat, int r, int c)
{
  int **arr = new int*[r];
  
  for(int i=0;i<r;i++)
    arr[i] = new int[c]();
  
  
  arr[r-1][c-1]=1;
  return solve(arr, mat, r, c);
  
}


int main()
{
  
  int t ;
  cin>>t;
  while(t)
  {
    t--;
    int r, c;
    cin>>r>>c;
    int **arr = new int*[r];
    for(int i=0;i<r;i++)
    {
      arr[i] = new int[c];
      for(int j=0;j<c;j++)
      {
        cin>>arr[i][j];
      }
    }
    cout<<matrix(arr, r, c)<<endl;
  }
    return 0;
}

