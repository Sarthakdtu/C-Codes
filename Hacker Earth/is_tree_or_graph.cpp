#include<iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int total_degree = 0;
    for(int i=0;i<n;i++)
    {
        int deg;
        cin>>deg;
        total_degree += deg; 
        //   istree = false; 
    }
    if(2*(n-1)==total_degree)
        cout<<"Yes";
    else    
    cout<<"No";
    return 0;
}