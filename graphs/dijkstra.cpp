#include<iostream>
#include<climits>
using namespace std;
#define inf INT_MAX

void display_graph(int v, int **graph)
{
	for(int i=0;i<v;i++)
	{
		for(int j=0;j<v;j++)
		{
			cout<<graph[i][j]<<" ";
		}
		cout<<endl;
	}
}

int findMinDistVertex(int v, int *distance, bool *visited)
{
	int minVertex = -1;
	for(int i=0;i<v;i++)
	{
		if(!visited[i] &&(minVertex==-1||distance[i]<distance[minVertex]))
		{
			minVertex=i;
		}
	}
	return minVertex;
}

void dijkstra(int **graph, int v)
{
	//display_graph(v, graph);
	cout<<endl;
	//int *parent = new int[v];
	int *distance = new int[v]();
	bool *visited = new bool[v]();
	
	for(int i=0;i<v;i++)
	{
		//parent[i]=i;
		distance[i]=inf;
	}
//	parent[0]=-1;
	distance[0]=0;
	
	for(int i=0;i<v;i++)
	{
		int minVertex = findMinDistVertex(v, distance, visited);
		
		visited[minVertex]=true;
		//cout<<"omae"<<graph[1][minVertex];
		for(int j=0;j<v;j++)
		{
		//	cout<<graph[j][minVertex];
			if(graph[j][minVertex]>0)
			{
				//cout<<"here";
				if(graph[j][minVertex]+distance[minVertex]<distance[j] && !visited[j])
				{
					
					distance[j]=graph[j][minVertex]+distance[minVertex];
					//parent[j]=minVertex;
				}
			}
		}
	}
	   
	for(int i=0;i<v;i++)
	{
			//cout<<parent[i]<<" ";
			cout<<i<<" ";
			cout<<distance[i];
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
	
	
//	display_graph(v, graph);
	cout<<endl;
	dijkstra(graph,  v);
	
}

int main()
{
	int v, e;
	cin>>v>>e;
	make_graph(v, e);	
	return 0;
}
