#include <iostream>
#include<vector>
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
void dfs(int **graph, int v, int* visited, int cv, vector<int> &path)   
{
	
	visited[cv] = true;
	//cout<<"At cv\n "<<cv<<endl;
	path.push_back(cv);
	for(int i=0;i<v;i++)
	{
		if(graph[i][cv]==1 && !visited[i])
		{
			dfs(graph, v, visited, i, path);
		}
	}
	
}

void connectedComponents(int **graph, int v)
{
  int *visited = new int[v]();
  vector<vector<int>> components;
  
  for(int i=0;i<v;i++)
  {
  	if(!visited[i])
	{
  	vector<int> path;
  	dfs(graph, v, visited, i, path);
  	
  	components.push_back(path);
    }
  }
  for(int i=0;i<components.size();i++)
  {
  	for(int j=0;j<components[i].size();j++)
  	{
  		cout<<components[i][j]<<" ";
	  }
	  cout<<endl;
  }
  //cout<<"true";
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
  connectedComponents(graph, v);
  
}

int main() {
    int V, E;
    cin >> V >> E;

  make_graph(V, E);

  return 0;
}

