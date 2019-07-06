/*
Kingdom Of Monkeys
Send Feedback
This is the story in Zimbo, the kingdom officially made for monkeys. Our Code Monk 
visited Zimbo and declared open a challenge in the kingdom, thus spoke to all the monkeys :

You all have to make teams and go on a hunt for Bananas. The team that returns with the 
highest number of Bananas will be rewarded with as many gold coins as the number of Bananas
 with them. May the force be with you!
Given there are N monkeys in the kingdom. Each monkey who wants to team up with another monkey
 has to perform a ritual. Given total M rituals are performed. Each ritual teams up two monkeys. 
 If Monkeys A and B teamed up and Monkeys B and C teamed up, then Monkeys A and C are also in the 
 same team.

You are given an array A where Ai is the number of bananas i'th monkey gathers.

Find out the number of gold coins that our Monk should set aside for the prize.
Input:
First line contains an integer T. T test cases follow. First line of each test case contains two space-separated N and M. M lines follow. Each of the M lines contains two integers Xi and Yi, the indexes of monkeys that perform the i'th ritual. Last line of the testcase contains N space-separated integer constituting the array A.
Output:
Print the answer to each test case in a new line.
Constraints:
1 = T = 10
1 = N = 105
0 = M = 105
0 = Ai = 1012
SAMPLE INPUT
1
4 3
1 2
2 3
3 1
1 2 3 5
SAMPLE OUTPUT
6
Explanation
Monkeys 1,2 ,3 are in the same team. They gather 1+2+3=6 bananas.
Monkey 4 is a team. It gathers 5 bananas.
Therefore, number of gold coins (highest number of bananas by a team) = 6.
*/

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


int connectedComponents(vector<vector<int>> graph, int v, vector<vector<int>> &comps)
{
	bool *visited = new bool[v]();
	//cout<<"here";
	//vector<vector<int>> comps;
	int max =-1;
	int idx=-1;
	for(int i=0;i<v;i++)
	{
		vector<int> component;
		if(!visited[i])
		{
			dfs(graph, v, i, visited, component);
			int cs = component.size();
			//cout<<"cs : "<<component.size()<<endl;
			if(max<cs)
			{
				max = component.size();
				idx = i;
			}
			//cout<<"ms : "<<max<<endl;
			comps.push_back(component);
		}
	}
	return idx;
}

void takeInput(int n, int m)
{
	vector<vector<int>> team = vector<vector<int>>(n);
	for(int i=0;i<m;i++)
	{
		int a, b;
		cin>>a>>b;
		team[a-1].push_back(b-1);
		team[b-1].push_back(a-1);
	}
	long long *gold = new long long[n];
	for(int i=0;i<n;i++)
	{
		cin>>gold[i];
	}
	//display(team);
	vector<vector<int>> components;
	int idx = connectedComponents(team, n, components);
	//cout<<"index Found "<<idx<<endl;
	long long totalGold = 0;
	for(int i=0;i<components[idx].size();i++)
	{
		long long g = components[idx][i];
		//cout<<"Adding gold : "<<gold[g]<<endl;
		totalGold += gold[g];
	}
	
	cout<<totalGold<<endl;	
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
		takeInput(n, m);
	}
	return 0;
}





