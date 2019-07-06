#include<iostream>

using namespace std;

void make_graph(int v, int e)
{
    int **graph = new int*[v];
    for(int i=0;i<v;i++)
        graph[i] = new int[v]();

    for(int i=0;i<e;i++)
    {
        int a, b;
        cin>>a>>b;
        graph[a][b] = 1;
        graph[b][a] = 1;
    }    

    int q;
    cin>>q;
    for(int i=0;i<q;i++)
    {
        int a, b;
        cin>>a>>b;
        if(graph[a][b]==1)
        {
            cout<<"YES"<<endl;
        }
        else
        {
            cout<<"NO"<<endl;
        }
        
    }
    
}


int main()
{
    int n, m;
    cin>>n>>m;
    make_graph(n, m);
    return 0;
}
