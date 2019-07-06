/*
Once detective Saikat was solving a murder case.
 While going to the crime scene he took the stairs and 
 saw that a number is written on every stair. He found 
 it suspicious and decides to remember all the numbers 
 that he has seen till now. While remembering the numbers
  he found that he can find some pattern in those numbers.
   So he decides that for each number on the stairs he will
    note down the sum of all the numbers previously seen on the stairs which are 
	smaller than the present number. Calculate the sum of all the numbers written on his notes diary.
Answer may not fit in integer . You have to take long.
Input
First line gives T, number of test cases.

2T lines follow.

First line gives you the number of stairs N

Next line gives you N numbers written on the stairs.
Output
For each test case output one line giving the final sum for each test case.
Constraints
T<=10

1<=N<=10^5

All numbers will be between 0 and 10^6.
Sample Input:
1
5
1 5 3 6 4
Sample Output:
15
Explanation:
For the first number, the contribution to the sum is 0.
For the second number, the contribution to the sum is 1.
For the third number, the contribution to the sum is 1.
For the fourth number, the contribution to the sum is 9 (1+5+3).
For the fifth number, the contribution to the sum is 4 (1+3).
Hence the sum is 15 (0+1+1+9+4).

*/



#include <bits/stdc++.h>
 using namespace std; 
  #define ll long long
  
   ll minihelper(int*arr1,int size1,int*arr2,int size2)
   { int curmaxindex=size1; 
   ll curans=0,finalans=0; 
   for(int i=0;i<size1;i++)
   { if(arr1[i]>=arr2[0])
      { curmaxindex=i; break; } 
	  else{ curans+=arr1[i]; }
    }
	 finalans=curans; 
	 for(int i=1;i<size2;i++){ 
	   ll localcurans=curans;
	    while(arr2[i]>arr1[curmaxindex]&&curmaxindex<size1)
		{ localcurans+=arr1[curmaxindex]; curmaxindex++; }
		 curans=localcurans; finalans+=localcurans; }
		  return finalans;
	 }
ll helper(int* arr,int si,int ei)
{ 
  if(si>=ei)
  { return 0; }
   int mid=(si+ei)/2; 
   int*arr1=new int [mid-si+1];
    int*arr2=new int [ei-mid];
	 for(int i=si,k=0;i<=mid;i++,k++)
	 { arr1[k]=arr[i]; } 
	 
	 for(int i=mid+1,k=0;i<=ei;i++,k++)
	 { arr2[k]=arr[i]; }
  sort(arr1,arr1+mid-si+1);
   sort(arr2,arr2+ei-mid); 
   ll ans=minihelper(arr1,mid-si+1,arr2,ei-mid);
    delete [] arr1; 
	delete [] arr2;
	 ans+=helper(arr,si,mid) + helper(arr,mid+1,ei); 
	 return ans; }
 int main(){
  int T; 
  cin>>T; 
  while(T--)
  { int n; 
  cin>>n;
   int*arr=new int [n]; 
   for(int i=0;i<n;i++)
   { cin>>arr[i]; } 
   cout<<helper(arr,0,n-1)<<endl; 
   }
    }
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
