/*
Monk and the Islands
Send Feedback
MONK AND THE ISLAND
Monk visits the land of Islands. There are a total of N islands numbered from 1 to N.
Some pairs of islands are connected to each other by Bidirectional bridges running over water.
Monk hates to cross these bridges as they require a lot of efforts. 
He is standing at Island #1 and wants to reach the Island #N. Find the minimum the number 
of bridges that he shall have to cross, if he takes the optimal route.
Input:
First line contains T. T testcases follow.
First line of each test case contains two space-separated integers N, M.
Each of the next M lines contains two space-separated integers X and Y , denoting 
that there is a bridge between Island X and Island Y.
Output:
Print the answer to each test case in a new line.
Constraints:
1 = T = 10
1 = N = 104
1 = M = 105
1 = X, Y = N
SAMPLE INPUT
2
3 2
1 2
2 3
4 4
1 2
2 3
3 4
4 2
SAMPLE OUTPUT
2
2
*/

#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int bfs(vector<vector<int>> graph)
{
	pair<int, int> p;
	queue<pair<int, int>> q;
	bool *visited = new bool[graph.size()];
	visited[0] = true;
	int dest = graph.size()-1;
	p.first=0;
	p.second=0;
	q.push(p);
	while(!q.empty())
	{
	   pair<int, int> u = q.front();
	   q.pop();
	   if(u.first==dest)
	   {
	   	return u.second;
	   }
	   else
	   {
	   	for(int i=0;i<graph[u.first].size();i++)
	   	{
	   		p.first = graph[u.first][i];
	   		p.second = u.second+1;
	   		//cout<<"\nInserting "<<p.first<<" with "<<p.second;
	   	  	q.push(p);
		}
	   }
	}
	return -1;
}

int bridgeCombos(vector<vector<int>> graph)
{
	return bfs(graph);
}


void make_graph(int v, int e)
{
	vector<vector<int>> graph= vector<vector<int>>(v);
	for(int i=0;i<e;i++)
	{
		int a, b;
		cin>>a>>b;
		graph[a-1].push_back(b-1);
		graph[b-1].push_back(a-1);
	}
	
	cout<<bridgeCombos(graph);
}


int main()
{
	int t;
	cin>>t;
	while(t)
	{
		t--;
		int n, m;
		cin>>n>>m;
		make_graph(n, m);
		cout<<endl;
	}
}























