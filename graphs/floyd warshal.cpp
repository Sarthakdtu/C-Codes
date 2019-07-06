#include<iostream>
using namespace std;

void display(int **path, int m)
{

	for(int i=0;i<m;i++)
	{
		cout<<"\n";
		for(int j=0;j<m;j++)
		{
			cout<<path[i][j]<<" ";
		}
	}
	cout<<endl;
}



void floydWarshal(int **path, int arr[][4], int m)
{
	for(int k =0;k<m;k++)
	{
		for(int i=0;i<m;i++)
		{
			for(int j = 0;j<m;j++)
			{
				if(path[i][j]>path[i][k]+path[k][j])
				{
					if(i!=k)
					cout<<"\nNode "<<j+1<<" can be reached by node "<<i+1<<" through node "<<k+1;
					path[i][j] = path[i][k]+path[k][j];
				}
			}
		}
	}
	
}

int main(){
	int m, n;
	m= 4;
	n= 4;
	int INF = 10000;
	int arr[][4] ={ {0,   5,  INF, 10},
                    {INF,  0,  3,  INF},
                    {INF, INF, 0,   1},
                    {INF, INF, INF, 0}
                };
    cout<<"Old path\n"   ;         
	
	int **path = new int*[m];
	for(int i=0;i<m;i++)
	{
		path[i] = new int[n]();
		for(int j=0;j<n;j++)
		{
			path[i][j] = arr[i][j];
		}
	}
	floydWarshal(path, arr, m);
		cout<<"new path cost "<<endl;
	display(path, m);
	
	return 0;
	
}






