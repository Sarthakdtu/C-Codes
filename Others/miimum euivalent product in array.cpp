#include <bits/stdc++.h>
using namespace std;
typedef double ll;

ll product(ll *arr, int n, ll x)
{
  ll pro=1;
  for(int i=0;i<n;i++)
  {
    pro=pro*arr[i];
    pro=pro/x;
  }
  cout<<"The product came out to be: "<<pro<<endl;
  return pro;
}

ll answer(ll *arr, int n, ll min, ll max)
{
  while(max>=min)
  {
    ll mid = min+(max-min)/2;
    cout<<"Currently I am at mid: "<<mid<<endl;
    cout<<"Max: "<<max<<"  Min:  "<<min<<endl;
    ll a = product(arr, n, (long long)mid);
    mid = (long long )mid;
    if(a==1)
    {
      return mid;
    }
    else if(a>1)
    {
      min = mid+1;
    }
    else
    {
      max = mid-1;
    }
  }
  if(product(arr, n, max)>1)
  return max+1;
  return max;
  
}



int main()
{
  int n;
  cin>>n;
  ll *arr = new ll[n];
  ll max;
  ll min;
  cin>>arr[0];
  min = arr[0];
  max = arr[0];
  for(int i =1;i<n;i++)
  {
    
    cin>>arr[i];
    if(arr[i]>max)
      max = arr[i];
    if(arr[i]<min)
      min = arr[i];
  }
  
  ll ans = answer(arr, n, min, max);
  
  cout<<(long long)ans;
  
  
    return 0;
}

