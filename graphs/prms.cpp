#include<iostream>
#include<climits>
using namespace std;
#define inf INT_MAX


int findMinVertex(int v, int *weight, bool *visited)
{
	int minVertex = -1;
	for(int i=0;i<v;i++)
	{
		if(!visited[i] &&(minVertex==-1||weight[i]<weight[minVertex]))
		{
			minVertex=i;
		}
	}
	return minVertex;
}

void prims(int **graph, int v)
{
	//display_graph(v, graph);
	cout<<endl;
	int *parent = new int[v];
	int *weight = new int[v]();
	bool *visited = new bool[v]();
	
	for(int i=0;i<v;i++)
	{
		parent[i]=i;
		weight[i]=inf;
	}
	parent[0]=-1;
	weight[0]=0;
	
	for(int i=0;i<v;i++)
	{
		int minVertex = findMinVertex(v, weight, visited);
		//cout<<minVertex<<endl;
		//display_graph(v, graph);
		visited[minVertex]=true;
		//cout<<"omae"<<graph[1][minVertex];
		for(int j=0;j<v;j++)
		{
		//	cout<<graph[j][minVertex];
			if(graph[j][minVertex]>0)
			{
				//cout<<"here";
				if(graph[j][minVertex]<weight[j] && !visited[j])
				{
					//cout<<"\nchanging w "<<j<<" : "<<weight[j]<<" to "<<graph[j][minVertex];
					//cout<<"\nchanging p "<<j<<" : "<<parent[j]<<" to "<<minVertex<<endl;
					weight[j]=graph[j][minVertex];
					
					//mst[j][parent[j]]=0;
					//mst[parent[j]][j]=0;
					
					parent[j]=minVertex;
					
					//mst[j][parent[j]]=weight[j];
					//mst[parent[j]][j]=weight[j];
				}
			}
		}
	}
	   
	for(int i=1;i<v;i++)
	{
		if(parent[i]<i)
		{
			cout<<parent[i]<<" ";
			cout<<i<<" ";
			cout<<weight[i];
		}
		else
		{
		    cout<<i<<" ";
			cout<<parent[i]<<" ";
			cout<<weight[i];	
		}
		cout<<endl;
	}
}


void make_graph(int v, int e)
{
	int **graph = new int*[v];
	for(int i=0;i<v;i++)
	{
		graph[i] = new int[v]();
	}
	for(int i=0;i<e;i++)
	{
		int a, b, w;
		cin>>a>>b>>w;
		graph[a][b]=w;
		graph[b][a]=w;
	}
	
//	cout<<endl;
	prims(graph,  v);
	
}

int main()
{
	int v, e;
	cin>>v>>e;
	make_graph(v, e);	
	return 0;
}
