#include <iostream>

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

bool hasPath(int **graph, int v, int a, int b, int* visited)
{
	if(graph[a][b]==1 || a==b)
	{
		return true;
	}
	else
	{
		for(int i=0;i<v;i++)
		{
			if(!visited[i] && graph[i][a]==1)
			{
				visited[i]=1;
				bool ans = hasPath(graph, v,  i, b, visited);
				if(ans)
				{
					return true;
				}
			}
		}
	}
	return false;
}

void hasPath(int **graph, int v)
{
	int a, b;
	cin>>a>>b;
	int *visited = new int[v]();
	bool ans =hasPath(graph, v, a, b, visited);
  if(ans)
    cout<<"true";
  else
    cout<<"false";
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
  
  hasPath(graph, v);
}

int main() {
    int V, E;
    cin >> V >> E;

  make_graph(V, E);

  return 0;
}

