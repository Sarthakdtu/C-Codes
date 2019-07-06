#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

struct edge{
	int s;
	int d;
	int weight;
}; 

bool compareWeights(edge one, edge two)
{
	return (one.weight < two.weight);
}

bool sameParent(int s, int d, int *parent)
{
	if(s==d)
	{
		return true;
	}
	else if(parent[s]==s && parent[d]==d && s!=d)
	{
		parent[s]=parent[d];
		return false;
	}
	return sameParent(parent[s], parent[d], parent);
}

void updateParents(int s, int d,int *parent)
{
	if(s==parent[s] && d==parent[d])
	{
		parent[d]=s;
		return ;
	}
	else if(s==parent[s] && d!=parent[d])
	{
		parent[s]=parent[d];
		return ;
	}
	else if(d==parent[d] && s!=parent[s])
	{
		parent[d]=parent[s];
		return ;
	}
	else
	{
	    updateParents(parent[s], parent[d], parent);
	}
}

bool addEdge(edge e, vector<edge> graph, int *parent)
{
	if(e.s==e.d)
	  return false;
	else if(sameParent(e.s, e.d, parent))
	  return false;
	
	//updateParents(e.s, e.d, parent);
	return true;    
}

vector<edge> kruskal(vector<edge> graph, int v)
{
	vector<edge> mst;
	
	int *parent = new int[v];
	for(int i=0;i<v;i++)
	  parent[i]=i;
	  
	int count=0;
    for(int i=0;count<v-1&&i<graph.size();i++)
    {
    	edge e = graph[i];
    	if(addEdge(e, graph, parent))
    	{
    		mst.push_back(e);
    		count++;
		}
	}
	return mst;
}

void make_graph(int v, int e)
{
	vector<edge> graph;
	for(int i=0;i<e;i++)
	{
		edge ed;
		cin>>ed.s>>ed.d>>ed.weight;
		graph.push_back(ed);
	}
	sort(graph.begin(), graph.end(), compareWeights);
	
	vector<edge> mst;
	mst = kruskal(graph, v);
	for(int i=0;i<mst.size();i++)
	{
		cout<<mst[i].s<<" ";
		cout<<mst[i].d<<" ";
		cout<<mst[i].weight<<" "<<endl;
	}
}

int main()
{
	int v, e;
	cin>>v>>e;
	make_graph(v, e);
	return 0;
}
