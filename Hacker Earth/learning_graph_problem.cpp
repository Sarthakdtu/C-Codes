/*
Monk once went to the graph city to learn graphs, and meets an undirected graph having N nodes, where each node have value where . Each node of the graph is very curious and wants to know something about the nodes which are directly connected to the current node.

For each node, if we sort the nodes (according to their values), which are directly connected to it, in descending order (in case of equal values, sort it according to their indices in ascending order), then what will be the number of the node at  position, if positions are given starting from 1.

Now Graph gave this task to Monk. Help Monk for the same.

Input Format :

The first line will consist of 3 space separated integers N,M, k denoting the number of nodes, number of edges and value of k respectively.
In next line, there will be N space separated integers,  , where , denoting the value of  node.
In next M lines, each line contains 2 integers X and Y, representing an edge between X and Y.

Output Format
Print N lines, where  line contains the required node for the  node. If there is no such node, print -1.

Constraints: :
n 10^3
m 10^6
1<k<m
val[i]<10^41, X, Y<n




SAMPLE INPUT 
3 3 2
2 4 3
1 3
1 2
2 3
SAMPLE OUTPUT 
3
1
1
Explanation
enter image description here

The node with  largest value from all of the adjacent nodes of node 1 is node 3.
The node with  largest value from all of the adjacent nodes of node 2 is node 1.
The node with  largest value from all of the adjacent nodes of node 3 is node 1.

Time Limit:	1.0 sec(s) for each input file.
*/

/*
5 8 2
7 4 8 8 4
1 2
2 4
1 5
1 3
1 4
3 4
4 5
2 3
*/

#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;

int findKNode(vector<int> nbors, vector<int> val, int k)
{
    map<int, vector<int>, greater <int>> nodeVal;
    for(int i=0;i<nbors.size();i++)
    {
    	int source = nbors[i];
    	int va = val[source];
        nodeVal[va].push_back(source+1);
    }
    //k--;
    map<int, vector<int>> ::iterator it = nodeVal.begin();
    int count=1;
    int ans = -1;
    while(it!=nodeVal.end()&&count<=k+1)
    {
    	cout<<endl;
    	vector<int> nodes = it->second;
    	//cout<<"For Val : "<<it->first<<endl;
		sort(nodes.begin(), nodes.end(), greater<int>());
		for(int i =0;i<nodes.size();i++)
		{
			//cout<<"At Node : "<<nodes[i]<<" with count : "<<count<<endl;
			if(count==k)
			{
				ans=nodes[i];
				return ans;
			}
			//cout<<"{"<<nodes[i]<<" , "<<count<<"}";
			count++;
		}
		it++;
	}
    //cout<<ans<<endl;
    return -1;
}


void findPosition(vector<vector<int>>graph,vector<int> val, int k)
{
    for(int i=0;i<graph.size();i++)
    {
    	//cout<<"For actual node"<<i+1<<endl;
        cout<<findKNode(graph[i], val, k);
        cout<<endl;
    }
}

void make_graph(int v, int e, int k)
{
    vector<int> val;
    for(int i=0;i<v;i++)
    {
        int a;
        cin>>a;
        val.push_back(a);
    }
    vector<vector<int>> graph(v);
    for(int i=0;i<e;i++)
    {
        int a, b;
        cin>>a>>b;
        a--;
        b--;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    findPosition(graph, val, k);
}

int main()
{
    int n, m, k;
    cin>>n>>m>>k;
    make_graph(n, m, k);

}
