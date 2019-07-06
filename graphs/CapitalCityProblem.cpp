/*
CAPCITY - Capital City
There are N cities in Flatland connected with M unidirectional roads. The cities are numbered from 1 to N. The Flat Circle of Flatland (FCF) wants to set up a new capital city for his kingdom. For security reasons, the capital must be reachable from all other cities of Flatland. FCF needs the list of all candidate cities. You are the chief programmer at FACM (Flat Association for Computing Machinery) responsible for providing the list to FCF as soon as possible.
Input
The first line of the input file contains two integers: 1=N=100,000 and 1=M=200,000. Each of the following M lines contains two integers 1=A, B=N denoting a road from A to B.
Output
The output file contains an integer denoting the number of candidate cities followed by the list of candidate cities in increasing order.
Sample Input:
4 4
1 2
3 2
4 3
2 1
Sample Output:
2
1 2
*/

//Kasaraju's algorithm

#include<iostream>
#include<vector>
#include<vector>
#include<stack>

using namespace std;

void display(vector<vector<int>> components)
{
	cout<<endl;	
	for(int i=0;i<components.size();i++)
	{
		cout<<components[i].size()<<endl;
		for(int j=0;j<components[i].size();j++)
		{
			cout<<components[i][j]+1<<" ";
		}
		cout<<endl;
	}
}

void dfs(vector<int>* graph, int source, bool* visited, stack<int> &stk)
{
	visited[source]=true;
	for(int i=0;i<graph[source].size();i++)
	{
		if(!visited[graph[source][i]])
		{
			dfs(graph, graph[source][i], visited, stk);
		}
	}
	stk.push(source);
}


void dfs2(vector<int>* graphT, int source, bool* visited, vector<int> &component)
{
	visited[source]=true;
	component.push_back(source);
	for(int i=0;i<graphT[source].size();i++)
	{
		if(!visited[graphT[source][i]])
		{
			dfs2(graphT, graphT[source][i], visited, component);
		}
	}
}

vector<vector<int>> stronglyConnectedComponents(vector<int>* graph, vector<int> *graphT, int v)
{
	vector<vector<int>> components;
	stack<int> finishedVertex;
	bool *visited = new bool[v]();
	
	for(int i=0;i<v;i++)
	{
		if(!visited[i])
		{
		  dfs(graph, i, visited, finishedVertex);
		}
	}
	
	visited = new bool[v]();
	while(!finishedVertex.empty())
	{
		int element = finishedVertex.top();
		finishedVertex.pop();
		vector<int> component;
		if(!visited[element])
		{
		   dfs2(graphT, element, visited, component);
		   components.push_back(component);	
		   return components;
		}
	}
	
 return components;
}

void make_graph(int v, int e)
{
	vector<int> *graph = new vector<int>[v];
	vector<int> *graphT= new vector<int>[v];
	for(int i=0;i<e;i++)
	{
		int a, b;
		cin>>a>>b;
		graphT[a-1].push_back(b-1);
		graph[b-1].push_back(a-1);
		//cout<<"\ndone\n";
	}
	vector<vector<int>> strongComponents = stronglyConnectedComponents(graph, graphT, v);
	display(strongComponents);
}

int main()
{
	int v, e;
	cin>>v>>e;
	make_graph(v, e);
}
/*
Input:
9 10
//Add 1 to all these indices
0 2
0 4
1 0
2 3
3 1
4 5
4 6
6 7
7 8
5 6

Answer:
0 1 3 2
4
5
6
7
8
*/





