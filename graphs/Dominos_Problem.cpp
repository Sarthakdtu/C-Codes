/*
Domino
Dominos are lots of fun. Children like to stand the tiles on their side in long lines. 
When one domino falls, it knocks down the next one, which knocks down the one after that, 
all the way down the line.
However, sometimes a domino fails to knock the next one down. In that case, we have to knock 
it down by hand to get the dominos falling again.
Your task is to determine, given the layout of some domino tiles, the minimum number of dominos 
that must be knocked down by hand in order for all of the dominos to fall.
Input
The first line of input contains one integer specifying the number of test cases to follow.Each 
test case begins with a line containing two integers,each no larger than 100 000. The first integer 
n is the number of domino tiles and the second integer m is the number of lines to follow in the test case. The domino tiles are numbered from 1 to n.
Each of the following lines contains two integers x and y indicating that if domino number x falls, 
it will cause domino number y to fall as well.
Output
For each test case, output a line containing one integer, the minimum number of dominos that must be knocked over by hand in order for all the dominos to fall.
Sample Input
1
3 2
1 2
2 3
Sample Output
1
*/

//Simple Connected Components Problem

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
		graph[a-1].push_back(b-1);
		//graph[b].push_back(a);
	}
	//display(graph);
	vector<vector<int>> comps = components(graph, v);
	cout<<comps.size()<<endl;
}

int main()
{
	int t;
	cin>>t;
	while(t)
	{
		t--;
	 int v, e;
	cin>>v>>e;
	make_graph(v, e);	
	}
	return 0;
}












