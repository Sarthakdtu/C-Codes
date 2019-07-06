#include<iostream>
using namespace std;

int kadane(int *dp, int r)
{
	int curr=0, max=INT_MIN;
	for(int i=0;i<r;i++)
	{
		curr = dp[i]+curr;
		if(curr>max)
		{
			max=curr;
		}
		if(curr<0)
		{
			curr=0;
		}
	}
	return max;
}

int maxSumRectangle(int **arr, int r, int c)
{
	//int *dp=new int[(c*(c+1))/2];
	
	int k, curr, max;
	k=0;
	curr=0;
	max=INT_MIN;
	for(int i=0;i<c;i++)
	{
		k=0;
		int *dp= new int[r]();
		for(int j=i;j<c;j++)
		{
			for(int row=0;row<r;row++)
			{
				dp[row]+=arr[row][j];
			}
			curr=kadane(dp, r);
			if(max<curr)
			{
				max=curr;
			}
		}
	}
	return max;
}

int find(int **arr, int r, int c)
{
	int **sum=new int*[r];
	for(int i=0;i<c;i++)
	  sum[i] = new int[c]();
	  
	for(int xi=0;xi<r;xi++)
	{
		for(int yi=0;yi<c;yi++)
		{
			int s =0;
			for(int x=xi;x<r;x++)
			{
				for(int y=yi;y<c;y++)
				{
					s+=arr[x][y];
				}
			}
			sum[xi][yi] = s;
		}
	}  
	
	for(int i=0;i<r;i++)
	{
		for(int j=0;j<c;j++)
		{
			cout<<"Sum at "<<i<<" , "<<j<<" is "<<sum[i][j]<<endl;
		}
	}
	
	int max=0;
	for(int xi=0;xi<r;xi++)
	{
		for(int yi=0;yi<c;yi++)
		{
			int curr =0;
			for(int x=xi;x<r;x++)
			{
				for(int y=yi;y<c;y++)
				{
					curr=sum[xi][yi];
					if(x+1!=r && y+1!=c)
					    curr=curr+sum[x+1][y+1];
					if(x+1!=r)
					    curr=curr-sum[x+1][yi];
					if(y+1!=c)
					    curr=curr-sum[xi][y+1];	 
						
					cout<<"Sum from "<<xi<<" , "<<yi<<" to "<<x<<" , "<<y<<" is "<<curr<<endl;
				 if(curr>max)
				{
					cout<<"Changing MAX "<<endl;
					max=curr;
				}
				}
				
			}
		}
	}  

	return max;
}


int main()
{
	//int t = INT_MIN;
	//cout<<t;
	int r=4;
	int c=5 ;
	int **arr = new int*[r];
	for(int i=0;i<r;i++)
	{
		arr[i]= new int[c];
		for(int j=0;j<c;j++)
		{
			cin>>arr[i][j];
		}
	}
	
	cout<<find(arr, r, c)<<endl;
	cout<<"Using kadane \n";
	cout<<maxSumRectangle(arr, r, c);
	return 0;
}

















