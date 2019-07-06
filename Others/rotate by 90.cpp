#include<iostream>
using namespace std;

void display(int arr[4][4], int n)
{
	for(int k =0; k<n;k++)
	{
		for(int j=0;j<n;j++)
		{
			cout<<"\t"<<arr[k][j];
		}
		cout<<"\n";
	}
		cout<<"\n\n\n";
}
void rotate_matrix(int arr[4][4],int n)
{
	
	int cd, cu, rl, rr;
	int i =n-2;
	int till = n+1;
	int ul=n-1;
	int ll=0;
	while(i>0)
	{
		cd=ll;
		cu=ul;
		rr=ll;
		rl=ul;
		int till_i =till-2;
		while(till_i>0)
		{
			int prev = arr[cd][ll];
			arr[cd][ll] = arr[ll][rl];
			arr[ll][rl] = arr[cu][ul];
			arr[cu][ul] = arr[ul][rr];
			arr[ul][rr] = prev;
			cd++;
			cu--;
			rl--;
			rr++;
			till_i--;
			display(arr, n);
		}
		ll++;
		ul--;
		i--;
		till-=2;
		
	}
	cout<<"\n\n\n";

	for(int k =0; k<n;k++)
	{
		for(int j=0;j<n;j++)
		{
			cout<<"\t"<<arr[k][j];
		}
		cout<<"\n";
	}
}









int main()
{
	int n = 4;
	int arr[4][4];
	int counter=1;
	for(int k =0; k<n;k++)
	{
		for(int j=0;j<n;j++)
		{
			arr[k][j] = counter ;
			counter +=1;
		}
		
	}
	display(arr, n);
	rotate_matrix(arr,n);
	return 0;
}










