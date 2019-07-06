#include<bits/stdc++.h>
using namespace std;
/*
Farmer John has built a new long barn, with N (2 <= N <= 100,000) stalls. 
The stalls are located along a straight line at positions x1,...,xN (0 <= xi <= 1,000,000,000).
His C (2 <= C <= N) cows don't like this barn layout and become 
aggressive towards each other once put into a stall. To prevent the cows from hurting each other,
 FJ wants to assign the cows to the stalls, such that the minimum
 distance between any two of them is as large as possible. What is the largest minimum distance?
 
 IT IS NECESSARY TO PUT THE FIRST COW AT POSITION[0].
 IP
 
1
5 3
1
2
8
4
9


op 3
*/


//SARTHAK


bool can_arrange(int c, long long stalls[], long long d, int n)
{
  long long currPos = stalls[0];
  c--;
  for(int i=1;i<n;i++)
  {
    if(stalls[i] - currPos>=d)
    {
      currPos = stalls[i];
      c--;
    }
    if(c == 0)
    {
    	cout<<"Distance passed "<<d<<endl;
	    return true;
    }
  }
  
  return false;
}


int findMinMax(long long stalls[], long start, long end, int cows, int n)
{
  long long mid = -1;
  long long ans = -1;
  while(start<=end)
  {
    mid = start+(end-start)/2 ;
    cout<<"Mid is "<<mid<<endl;
    if(can_arrange(cows, stalls, mid, n))
    {
      ans = mid;
      start = mid+1;
    }
    else
    {
      end = mid-1;
    }
  }
  return ans;
}

int main() {

	// Write your code here
  
  int t;
  cin>>t;
  while(t)
  {
    t--;
    int n, c;
    cin>>n>>c;
    
    long long stalls[n];
    for(int i=0;i<n;i++)
    {
      cin>>stalls[i];    
    }
    sort(stalls, stalls+n);
    
    long long start = 0;
    long long end = stalls[n-1] - stalls[0];
    int ans = findMinMax(stalls, start, end, c, n);
    cout<<ans<<endl;
    
    
  }
}
