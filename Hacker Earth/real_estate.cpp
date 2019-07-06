#include<iostream>
#include<vector>
#include<map>
using namespace std;

void dfs(int source, map<int, vector<int>>& graph, map<int, bool> &visited, vector<int> &component)
{
    vector<int> nbor = graph[source];
    component.push_back(source);

    
    visited[source]=true;
    for(int i=0;i<nbor.size();i++)
    {
        int nb = nbor[i];
        if(!visited[nb])
        dfs(nb, graph, visited, component);
    }
}

int connected_components(map<int, vector<int>> graph)
{
    //vector<int> components;
    map<int, vector<int>> ::iterator it = graph.begin();
    map<int, bool> visited;
    while(it!=graph.end())
    {
        int source = it->first;
        visited[source]=false;
        it++;
    }
    it = graph.begin();
    int num_comps=0;
    while(it!=graph.end())
    {
        int source = it->first;
        if(!visited[source])
        {
            vector<int> component;
            dfs(source, graph, visited, component);
          
            num_comps += component.size();
        }
        it++;
    }
    return num_comps;
}

void make_graph(int e)
{
    map<int, vector<int>> graph;
    for(int i=0;i<e;i++)
    {
        int a, b;
        cin>>a>>b;

        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    int num_comps = connected_components(graph);
    //cout<<num_comps<<endl;
}


int main()
{
    int t;
    cin>>t;
    while(t)
    {
        t--;
        int e;
        cin>>e;
        make_graph(e);
    }
    return 0;
}
