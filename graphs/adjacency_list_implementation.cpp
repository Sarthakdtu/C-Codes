#include<iostream>
#include<vector>
using namespace std;

void display(vector<vector<int>> graph)
{
	for(int i=0;i<graph.size();i++)
	{
		vector<int> edges = graph[i];
		cout<<"\nVertex "<<i<<" : ";
		for(int j = 0;j<edges.size();j++)
		{
			cout<<edges[j]<<" ";
		}
	}
}


void dfs(vector<vector<int>> graph, int v, int source, bool *visited,  vector<int> &component)
{
	component.push_back(source);
	cout<<"\nAt "<<source<<endl;
	visited[source]=true;
	for(int i=0;i<graph[source].size();i++)
	{
		if(!visited[graph[source][i]])
		{
			dfs(graph, v, graph[source][i], visited, component);
		}
	}
}


vector<vector<int>> components(vector<vector<int>> graph, int v)
{
	bool *visited = new bool[v]();
	vector<vector<int>> comps;
	
	for(int i=0;i<v;i++)
	{
		vector<int> component;
		if(!visited[i])
		{
			dfs(graph, v, i, visited, component);
			comps.push_back(component);
		}
	}
	return comps;
}

void make_graph(int v, int e)
{
	vector<vector<int>> graph= vector<vector<int>>(v+1);
	for(int i=0;i<e;i++)
	{
		int a, b;
		cin>>a>>b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	display(graph);
	vector<vector<int>> comps = components(graph, v);
}

int main()
{
	int v, e;
	cin>>v>>e;
	make_graph(v, e);
	return 0;
}
