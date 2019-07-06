#include<iostream>
#include<vector>
#include<set>
using namespace std;

bool isSafe(int i, int j, vector<string> g)
{
    int n = g.size();
    if(i<n&&i>-1&&j<n&&j>-1&&g[i][j]=='1')
    {
        return true;
    }
    return false;
}

void dfs(vector<string> g,bool** v, int i,int  j,set<int> &c,int **arr)
{
    int n = g.size();
    c.insert(arr[i][j]);
    v[i][j] = true;

    if(isSafe(i+1, j, g)&&!v[i+1][j])
        dfs(g, v, i+1, j, c, arr);
    if(isSafe(i, j+1, g)&&!v[i][j+1])
        dfs(g, v, i, j+1, c, arr);
    if(isSafe(i-1, j, g)&&!v[i-1][j])
        dfs(g, v, i-1, j, c, arr);
    if(isSafe(i, j-1, g)&&!v[i][j-1])
        dfs(g, v, i, j-1, c, arr);            
}

void make_graph(vector<string> g1, vector<string> g2)
{
    int n = g1.size();
    bool **v1 = new bool*[n];
    bool **v2 = new bool*[n];
    int **arr = new int*[n];
    for(int i=0;i<n;i++)
    {
        v1[i] = new bool[n]();
        v2[i] = new bool[n]();
    }

    int num = 1;
    for(int i=0;i<n;i++)
    {
        arr[i] = new int[n];
        for(int j=0;j<n;j++)
        {
            arr[i][j]=num;
            num++;
        }
    }

    vector<set<int>> c1;
    vector<set<int>> c2;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(g1[i][j]=='1'&&!v1[i][j])
            {
                set<int> c;
                dfs(g1, v1, i, j, c, arr);
                c1.push_back(c);
            }
            if(g2[i][j]=='1'&&!v2[i][j])
            {
                set<int> c;
                dfs(g2, v2, i, j, c, arr);
                c2.push_back(c);
            }
        }
    }
    /*
    cout<<"\n---1---";
    for(int i=0;i<c1.size();i++){
        set<int> a = c1[i];
        cout<<endl;
    set<int>::iterator it = a.begin();
    while(it!=a.end())
    {
        cout<<*it<<" , ";
        it++;
    }
    }   
    cout<<"\n----2---";
    for(int i=0;i<c2.size();i++){
        set<int> a = c2[i];
        cout<<endl;
    set<int>::iterator it = a.begin();
    while(it!=a.end())
    {
        cout<<*it<<" , ";
        it++;
    }
    }   
    */
    /*
4
0100
1001
0011
0011
0101
1001
0011
0011
    */
    
    //bool *diff = new bool[c1.size()]();
    int count=0;
    for(int i=0;i<c1.size();i++)
	{
        set<int> a = c1[i];
        for(int j=0;j<c2.size();j++)
        {
        	set<int> b = c2[j];
        	if(a==b)
        	{
        		j=c2.size();
        		//diff[i]=true;
        		count++;
			}
		}
    }   
    cout<<"\nmodi ji\n";
    cout<<count;
}

int main()
{
    int n;
    cin>>n;
    vector<string> g1, g2;
    for(int i=0;i<n;i++)
    {
        string s;
        cin>>s;
        g1.push_back(s);
    }

    for(int i=0;i<n;i++)
    {
        string s;
        cin>>s;
        g2.push_back(s);
    }

    make_graph(g1, g2);
}
