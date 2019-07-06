#include<iostream>
using namespace std;

int board[5][5];

bool solve(float val, int i, int j,bool **visited)
{
	//cout<<"Value = "<<val<<endl;
	if(val==0.0)
	{
	//	cout<<"00000000000000000000"<<endl;
	}
	if(i>-1&&i<5&&j>-1&&j<5)
	{
		if(visited[i][j])
		{
		//	cout<<"Already Visited "<<i<<" "<<j<<endl;
			return false;
		}
		if(val==0.0&&i==4&&j==4)
		{
			//cout<<"****************Solution*****************"<<endl;
			return true;
		}
		if(i==4&&j==4)
		{
		//	cout<<"I have reached 4, 4 and value is "<<val<<endl;
			return false;
		}
		else
		{
			visited[i][j]=true;
		//	cout<<"Currently at "<<i<<" "<<j<<endl;
		//	cout<<"Move to right , Curr Value is "<<val<<endl;
			bool path=solve(val+2.0, i, j+1,visited);
			
			if(path)
			{
			//	cout<<"Follow Me"<<endl;
				return true;
			}
			//	cout<<"Currently at "<<i<<" "<<j<<endl;
			//cout<<"Move to left , Curr Value is "<<val<<endl;
			path=solve(val-2.0, i, j-1,visited);
			
			if(path)
			{
				//cout<<"Follow Me"<<endl;
				return true;
			}
			//	cout<<"Currently at "<<i<<" "<<j<<endl; 
			//cout<<"Move downwards , Curr Value is "<<val<<endl;
			path=solve(val*2.0, i+1, j,visited);
			
			if(path)
			{
				//cout<<"Follow Me"<<endl;
				return true;
			}
			
		//	cout<<"Currently at "<<i<<" "<<j<<endl;
		//	cout<<"Move to upwards , Curr Value is "<<val<<endl;
			path=solve(val/2.0, i-1, j,visited);
			
			if(path)
			{
				//cout<<"Follow Me"<<endl;
				return true;
			}
			
			visited[i][j]=false;
			return false;
		}
		
	}
	return false;
}

int main()
{
	bool **visited = new bool*[5];
	for(int i=0;i<5;i++)
	{
		visited[i] = new bool[5]();
	}
	visited[0][0]=true;
	visited[0][1]=true;
	cout<<endl;
	//cout<<"::::::::::::";

	cout<<solve(4.0, 0, 2, visited);
}
