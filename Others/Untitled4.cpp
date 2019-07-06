#include <bits/stdc++.h>
using namespace std;

//sarthak ????????????????

void displayA(int *arr, int n)
{
	for(int i=0;i<n;i++)
	cout<<arr[i]<<" ";
	cout<<endl;
}

int nor2(string s)
{
  if(s.size()==0)
  {
    return 0;
  }
  
  int *arr =  new int[s.size()]();
  arr[0] = 1;
  bool isR = false;
  int r=1, rb = 0;
  int n = s.size();
  cout<<"Initially "<<endl;
  	cout<<"r = "<<r<<endl;
  	displayA(arr, n);
  for(int i =1;i<s.size();i++)
  {
  	cout<<"At "<<s[i]<<endl;
  	cout<<"r = "<<r<<endl;
  	displayA(arr, n);
    if(s[i]=='K' && isR)
    {
      isR = false;
      arr[i] = r;
      r =  0; 
      
    }
    else if(s[i]=='K' && !isR)
    {
      r++;
      arr[i] = arr[i-1] + 1;
    }
    else
    {
      r++;
      arr[i] = arr[i-1]+1;
      isR = true;
    }
  }
  cout<<"At the End "<<endl;
  	cout<<"r = "<<r<<endl;
  	displayA(arr, n);
  int max =0;
  for(int i=0;i<s.size();i++)
  {
    if(max<arr[i])
    {
      max = arr[i];
    }
  }
  return max;
  
  
  
}
 

void display(int i,int bi, int j, int bj, int r, int br)
{
	cout<<"i  : "<<i<<endl;
	cout<<"j  : "<<j<<endl;
	cout<<"r  : "<<r<<endl;
	cout<<"bi : "<<bi<<endl;
	cout<<"bj : "<<bj<<endl;
	cout<<"br : "<<br<<endl<<endl;
}

int nor(string s)
{
  
  int i, bi, j, bj, r, rb;
  i=0;j=0;bi =-1;
  bj=-1;j=0;
  r = 0;rb =-1;
  
  while(j<s.size())
  {
  	cout<<"At iteration "<<j<<endl;
  	display(i, bi, j, bi, r, rb);
    if(s[j]=='K')
    {
      //j++;
      r++;
    }
    else
    {
      //r++;
      if(r > rb)
      {
        bi = i;
        bj = j;
        rb = r+1;
        r  = 0;
      }
      r++;
      i = j+1;
    }
    j++;
    display(i, bi, j, bi, r, rb);
  }
  
  if(bi==0&&bj==s.size()-1)
  {
    return 0;
  }
  return rb;
  
}
 



int main()
{   
   string s = "KRKKRKRR";
    cout<<nor2(s);
    return 0;
}

