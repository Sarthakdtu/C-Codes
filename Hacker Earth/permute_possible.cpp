#include<iostream>
#include<vector>
using namespace std;

void make_graph(int v, int e, int k)
{
    vector<vector<int>> graph(v);
    for(int i=0;i<e;i++)
    {
        int a, b;
        a--;
        b--;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    
}

int main()
{
    int n, m, k;
    cin>>n>>m>>k;
    make_graph(n, m, k);

}