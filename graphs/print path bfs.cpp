#include <iostream>
#include<vector>
#include<queue>
#include<map>
using namespace std;
//DFS way
//0 is always the source vertex
/*
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


void pathBfs(int **graph, int v)
{
	int a, b;
	cin>>a>>b;
	int *visited = new int[v]();
	vector<int> path;
	queue<int> q;
	q.push(a);
	map<int, int> parent;
	parent[a]=-1;
	parent[b]=-1;
	while(!q.empty())
	{
		int cv = q.front();
		q.pop();
		for(int i=0;i<v;i++)
		{
			if(!visited[i] && graph[i][cv]==1)
			{
				parent[i]=cv;
				if(i==b)
				{
					break;
				}
			}
		}
	}
	
	int cv=b; 
	while(parent[cv]!=-1)
	{
		path.push_back(cv);
		cv = parent[cv];
	}
	if(cv!=b)
	{
		path.push_back(cv);
	}
	for(int i=0;i<path.size();i++)
	{
		cout<<path[i];
		cout<<"here";
	}
}

*/
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
  //display_graph(v, graph);
  
  //pathBfs(graph, v);
}

int main() {
    int V, E;
    cin >> V >> E;

  make_graph(V, E);

  return 0;
}

