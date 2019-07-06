#include<iostream>
#include<math.h>
using namespace std;

class node
{
    public:
    node* one;
    node* zero;
};


void insert(int n, node* trie)
{
    node* curr = trie;
    for(int i=31;i>=0;i--)
    {
        int b = (n>>i)&1;
        if(b==0)
        {
            if(!curr->zero)
                curr->zero = new node(); 
            curr = curr->zero;         
        }
        else
        {
            if(!curr->one)
                curr->one = new node();
            curr = curr->one;     
        }
    }
}

int findMaxXorSubarray(int* arr, int n)
{
    int preXor = 0;
    node* trie = new node();
    for(int i=0;i<n;i++)
    {
        preXor = preXor ^ arr[i];
        insert(preXor, trie);
    }
    
    node* curr = trie;
    int maxXor = 0;
    for(int i=31;i>=0;i--)
    {
        int b=(preXor>>i)&1;
        if(b==0)
        {
            if(curr->one)
            {
                curr = curr->one;
                maxXor += pow(2, i);
            }
            else
            {
                curr = curr->zero;
            }            
        }
        else
        {
            if(curr->zero)
            {
                maxXor += pow(2, i);
                curr = curr->zero;
            }
            else
            {
                curr = curr->one;
            }          
        }
    }
    return maxXor;
}


void take_input(int n)
{
    //node *head = new node();
    int *arr = new int[n];
    for(int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    cout<<findMaxXorSubarray(arr, n);
}


int main()
{
    int n;
    cin>>n;
    take_input(n);
}

