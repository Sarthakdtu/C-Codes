#include<bits/stdc++.h>
using namespace std;
/*
Shaky has N (1<=N<=50000) candy boxes each of them contains a non-zero number of candies (between 1 and 1000000000).
Shakey want to distibute these candies among his K (1<=K<=1000000000) IIIT-Delhi students. 
He want to distibute them in a way such that:
1. All students get equal number of candies.
2. All the candies which a student get must be from a single box only.
As he want to make all of them happy so he want to give as many candies as possible.
Help Shaky in finding out what is the maximum number of candies which a student can get.


ip

2
3 21 
3 50 41
5 2
32 34 55 1 1


op

4
34
*/
bool check(int mid, int n, int k, int* arr)
{
	if(mid == 0)
	{
		return true;
	}
  cout<<"No. of candies to be distributed is "<<mid<<" and no. of students are "<<k<<endl;
  for(int i=0;i<n;i++)
  {
    if(arr[i]-mid>=0)
    {
    	cout<<"Number of candies in this bag is "<<arr[i]<<endl;
      int ps = arr[i]/mid;
      k = k-ps;
      cout<<"Students remaining "<<k<<endl;
    }
    if(k<=0)
    {
      return true;
    }
  }
  return false;
}

int distribute(int n, int k, int* arr, int sum)
{
  int ans = -1;
  int start=0;
  int end = sum/k;
  while(start<=end)
  {
    int mid = start+(end-start)/2;
    //cout<<"Mid is "<<mid<<endl;
    if(check(mid, n, k, arr))
    {
      ans = mid;
      cout<<"Posiible candies "<<ans<<endl;
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
    int n;
    int k;
    cin>>n>>k;
    int sum=0;
    int *arr = new int[n];
    for(int i=0;i<n;i++)
    {
      cin>>arr[i];
      sum+=arr[i];
    }
    sort(arr, arr+n);
    int ans = distribute(n, k, arr, sum);    
    cout<<ans<<endl;
  }
  
  return 0;
  
}
