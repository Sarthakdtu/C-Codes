#include<iostream>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int preXor = 0;
    int *arr = new int[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
        preXor = preXor^arr[i];
    }
    cout<<"\n"<<preXor<<" damn! ";
    return 0;
}
