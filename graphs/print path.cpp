#include <iostream>
#include<vector>
using namespace std;
//DFS way
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

vector<int> findPath(int **graph, int v, int a, int b, int* visited)
{
	vector<int> path;
	if(a==b)
	{
		path.push_back(b);
		//path.push_back(a);
		return path;
	}
	else
	{
		for(int i=0;i<v;i++)
		{
			if(!visited[i] && graph[i][a]==1)
			{
				visited[i]=1;
				vector<int> ans = findPath(graph, v,  i, b, visited);
				if(!ans.empty())
				{
				    path = ans;
				    path.push_back(a);
				    return path;
				}
			}
		}
	}
	
	return path;
}

void path(int **graph, int v)
{
	int a, b;
	cin>>a>>b;
	int *visited = new int[v]();
	visited[a]=1;
	vector<int> path;
	path = findPath(graph, v, a, b, visited);
    for(int i=0;i<path.size();i++)
    {
    	cout<<path[i]<<" ";
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
  
  path(graph, v);
}

int main() {
    int V, E;
    cin >> V >> E;

  make_graph(V, E);

  return 0;
}

