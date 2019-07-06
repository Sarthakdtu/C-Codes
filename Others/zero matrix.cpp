#include<iostream>
#include<set>

using namespace std;

void display(int arr[4][5], int n, int m)
{
	for(int k =0; k<n;k++)
	{
		for(int j=0;j<m;j++)
		{
			cout<<"\t"<<arr[k][j];
		}
		cout<<"\n";
	}
		cout<<"\n\n\n";
}
void zero_matrix(int arr[4][5],int n, int m)
{
	set<int> r;
	set<int> c;
	for(int i =0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(arr[i][j]==0)
			{
				r.insert(i);
				c.insert(j);
			}
		}
	}
	
	set<int>:: iterator i;
	for(i =r.begin();i!=r.end();i++)
	{
		for(int j=0;j<m;j++)
		{
			arr[*i][j]=0;
		}
	}
	
	for(i =c.begin();i!=c.end();i++)
	{
		for(int j=0;j<n;j++)
		{
			arr[j][*i]=0;
		}
	}
	display(arr, n, m);
}



int main()
{
	int n = 4;
	int m=5;
	int arr[4][5];
	int counter=1;
	for(int k =0; k<n;k++)
	{
		for(int j=0;j<m;j++)
		{
			arr[k][j] = counter ;
			counter +=1;
		}
		
	}
	
	arr[2][4] = 0;
	arr[1][3] = 0;
	arr[0][1] = 0;
	display(arr, n, m);
	zero_matrix(arr,n, m);
	
	return 0;
}
