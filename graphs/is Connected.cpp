#include <iostream>
#include<queue>
using namespace std;

//0 is always the source vertex

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
void dfs(int **graph, int v, int* visited, int cv)   
{
	//cout<<cv<<" ";
	visited[cv] = true;
	for(int i=0;i<v;i++)
	{
		if(graph[i][cv]==1 && !visited[i])
		{
			dfs(graph, v, visited, i);
		}
	}
	
}

void isConnected(int **graph, int v)
{
  int *visited = new int[v]();
  dfs(graph, v, visited, 0);
  for(int i=0;i<v;i++)
  {
  	if(visited[i]!=1)
  	{
  		cout<<"false";
  		break;
	}
  }
  cout<<"true";
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
    int a, b;
    cin>>a>>b;
    graph[a][b] = 1;
    graph[b][a] = 1;
  }
  display_graph(v, graph);
  isConnected(graph, v);
  
}

int main() {
    int V, E;
    cin >> V >> E;

  make_graph(V, E);

  return 0;
}

