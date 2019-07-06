/*
Connected horses
Send Feedback
You all must be familiar with the chess-board having 
8*8 squares of alternate black and white cells. Well, here 
we have for you a similar 
N*M size board with similar arrangement of black and white 
cells.
A few of these cells have Horses placed over them. 
Each horse is unique. Now these horses are not the 
usual horses which could jump to any of the 
8 positions they usually jump in. They can move only if there is another horse on one of the 
8-positions that it can     go to usually and then both the horses will swap their positions. 
This swapping can happen infinitely times.
A photographer was assigned to take a picture of all the different ways that the horses occupy
 the board! Given the state of the board, calculate answer. Sincethis answer may be quite large,
  calculate in modulo 
10^9+7
Input:
First line contains 
T which is the number of test cases.
T test cases follow first line of each containing three integers 
N, M and Q where 
N,M is the size of the board and 
Q is the number of horses on it.

Q lines follow each containing the 2 integers 
X and Y which are the coordinates of the Horses.
Output:
For each test case, output the number of photographs taken by photographer.
Constraints:
 1<=T<=10
 1<=N,M<=1000
 1<=Q<=N*M
SAMPLE INPUT
2
4 4 4
1 1
1 2
3 1
3 2
4 4 4
1 1
1 2
3 1
4 4
SAMPLE OUTPUT
4
2
*/

#include<iostream>
#include<vector>

long long mod = 1000000007;
using namespace std;

void connectHorse(int h, vector<vector<int>> &horse,int **board, int n, int m, int x, int y)
{
	if(x+1<n)
	{
		if(y+2<m)
		{
			if(board[x+1][y+2]>0)
			{
				horse[h].push_back(board[x+1][y+2]-1);
			}
		}
		if(y-2>-1)
		{
			if(board[x+1][y+1]>0)
			{
				horse[h].push_back(board[x+1][y-2]-1);
			}
		}
	}
	if(x+2<n)
	{
		if(y-1>-1)
		{
			if(board[x+2][y-1]>0)
			{
				horse[h].push_back(board[x+2][y-1]-1);
			}
		}
		if(y+1<m)
		{
			if(board[x+2][y+1]>0)
			{
				horse[h].push_back(board[x+2][y+1]-1);
			}
		}
	}
	if(x-1>-1)
	{
		if(y+2<m)
		{
			if(board[x-1][y+2]>0)
			{
				horse[h].push_back(board[x-1][y+2]-1);
			}
		}
		if(y-2>-1)
		{
			if(board[x-1][y-2]>0)
			{
				horse[h].push_back(board[x-1][y-2]-1);
			}
		}
	}
	if(x-2>-1)
	{
		if(y+1<m)
		{
			if(board[x-2][y+1]>0)
			{
				horse[h].push_back(board[x-2][y+1]-1);
			}
		}
		if(y-1>-1)
		{
			if(board[x-2][y-1]>0)
			{
				//cout<<"Connecting "<<h<<"to"<<board[x-2][y-1];
				horse[h].push_back(board[x-2][y-1]-1);
			}
		}
	}
}

long long factorial(int n)
{
	long long fact=1;
	for(int i=1;i<n+1;i++)
	{
		fact = (fact%mod)*(i);
	}
	return fact;
}

void dfs(vector<vector<int>> graph, int v, int source, bool *visited,  vector<int> &component)
{
	component.push_back(source);
	//cout<<"\nAt "<<source<<endl;
	visited[source]=true;
	for(int i=0;i<graph[source].size();i++)
	{
		if(!visited[graph[source][i]])
		{
			dfs(graph, v, graph[source][i], visited, component);
		}
	}
}

long long components(vector<vector<int>> graph, int v)
{
	bool *visited = new bool[v]();
	//vector<vector<int>> comps;
	long long comps=1;
	for(int i=0;i<v;i++)
	{
		vector<int> component;
		if(!visited[i]&&graph[i].size()>0)
		{
			dfs(graph, v, i, visited, component);
			//cout<<"Size of con comp : "<<component.size()<<endl;
			long long add = factorial(component.size());
			comps=((comps%mod)*(add%mod))%mod;
		}
	}
	return comps;
}


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

void takeInput(int n, int m, int q)
{
	int**board= new int*[n];
	vector<vector<int>> horse = vector<vector<int>>(q);
	for(int i=0;i<n;i++)
	   board[i] = new int[m]();
	//enter knights
	for(int i=0;i<q;i++)
	{
	  int a, b;
	  cin>>a>>b;
	  board[a-1][b-1]=i+1;
	  connectHorse(i, horse, board, n, m, a-1, b-1);	
	} 	
	//display(horse);
	long long answer = components(horse, q);	
	cout<<answer<<endl;
}

int main()
{
	
	int t;
	cin>>t;
	while(t)
	{
		t--;
		int n, m, q;
		cin>>n>>m>>q;
		takeInput(n, m, q);
	}
	return 0;
}
