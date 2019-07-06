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
void print(int **graph, int v, int* visited, int cv)   //This works for connected graph only.
{
	cout<<cv<<" ";
	visited[cv] = true;
	for(int i=0;i<v;i++)
	{
		if(graph[i][cv]==1 && !visited[i])
		{
			print(graph, v, visited, i);
		}
	}
	
}

void dfs(int **graph, int v, int e)
{
  queue<int> q;
  q.push(0);
  int *visited = new int[v]();
  print(graph, v, visited, 0);
}

    //For disconnected graph


void dfsDC(int **graph, int v)
{
  queue<int> q;
  q.push(0);
  int *visited = new int[v]();
  for(int i=0;i<v;i++)
  {
  	if(!visited[i])
  	print(graph, v, visited, i);
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
    int a, b;
    cin>>a>>b;
    graph[a][b] = 1;
    graph[b][a] = 1;
  }
  display_graph(v, graph);
  //dfs(graph, v, e);
  dfsDC(graph, v);
}

int main() {
    int V, E;
    cin >> V >> E;

  make_graph(V, E);

  return 0;
}

