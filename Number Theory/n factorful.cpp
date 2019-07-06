#include<iostream>

using namespace std;

void multiples(int *arr, int b, int p)
{
	for(int i= p;i<=b;i+=p)
	{
		arr[i]+=1;
	}
}


void findFactors(int b, int *arr)
{
	arr[0]= 0;
	arr[1]= 0;
	
	for(int i=2;i<=b;i++)
	{
		if(arr[i]==0)	
		   multiples(arr, b, i);
	}
}



int findFactors2(int a, int n, int b, int *arr)
{
	arr[0]= 0;
	arr[1]= 0;
	int count=0;
	if(a==1&&n==0)
    count++;
	for(int i=2;i<=b;i++)
	{
	   if(arr[i]==0)	
		   multiples(arr, b, i);
      
       if(i>=a&&i<=b)
       {
         if(arr[i]==n)
           count++;
           cout<<"From 2 "<<i<<" : "<<arr[i]<<endl;
       }
	}
  return count;
}

void showNFactors(int *arr, int n, int a, int b)
{
	int count =0;
	for(int i=a;i<=b;i++)
	{
		cout<<i<<" : "<<arr[i]<<endl;
		if(arr[i]==n)
		  count+= 1;
	}
	cout<<count<<endl;
}

int main()
{
	int n = 3;
	int a=1, b =100;
	int *arr = new int[b+1]();
	findFactors(b, arr);
	showNFactors(arr, n, a, b);
	cout<<findFactors2(a, n, b, arr);
	return 0;
}
