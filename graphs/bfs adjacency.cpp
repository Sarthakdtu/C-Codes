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
void bfs(int **graph, int v, int e)     //For disconnectd graph
{
  queue<int> q;
  q.push(0);
  int *visited = new int[v]();
  visited[0] = true;
  
  while(!q.empty())
  {
  	int cv = q.front();
  	q.pop();
  	//visited[cv] = true;
  	cout<<cv<<" ";
  	for(int i=0;i<v;i++)
  	{
  		if(!visited[i] && graph[i][cv]==1)
  		{
  			visited[i]=true;
  			q.push(i);
		}
	}
  }
}

void printBFS(int **graph, int v, int sv, int *visited)     //For disconnectd graph
{
  queue<int> q;
  q.push(sv);
  visited[sv] = true;
  while(!q.empty())
  {
  	int cv = q.front();
  	q.pop();
  	//visited[cv] = true;
  	cout<<cv<<" ";
  	for(int i=0;i<v;i++)
  	{
  		if(!visited[i] && graph[i][cv]==1)
  		{
  			visited[i]=true;
  			q.push(i);
		}
	}
  }
}

void bfsDisconnected(int **graph, int v)
{
	int *visited = new int[v]();
	for(int i=0;i<v;i++)
	{
		if(!visited[i])
		{
			printBFS(graph, v, i, visited);
		}
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
  //bfs(graph, v, e);
  
  bfsDisconnected(graph, v);
  
}

int main() {
    int V, E;
    cin >> V >> E;

  make_graph(V, E);

  return 0;
}

