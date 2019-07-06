#include<iostream>
#include<math.h>
using namespace std;

class node
{
    public:
    node* one;
    node* zero;
};

void insert(int n, node* head)
{
    node* curr = head;
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

int findMaxXorPair(int *arr, int n, node*head)
{
    int maxXor = INT32_MIN;
    int currXor;
    for(int i=0;i<n;i++)
    {
       node* curr = head;
       currXor = 0;
        int num = arr[i];
        for(int j = 31;j>=0;j--)
        {
            int b = (num>>i)&1;
            if(b==0)
            {
                if(curr->one)
                {
                    currXor += pow(2, j); 
                    curr = curr->one;
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
                    currXor += pow(2, j);
                    curr = curr->zero;
                }
                else
                {
                    curr = curr->one;
                }                
            }
         }
         if(currXor>maxXor)
         {
             maxXor = currXor;
         }
    }
    return maxXor;
}


void take_input(int n)
{
    int *arr = new int[n];
    node* head = new node(); 
    for(int i=0;i<n;i++)
    {
       cin>>arr[i]; 
       insert(arr[i], head);
    }    
    int ans = findMaxXorPair(arr, n, head);
    cout<<ans<<endl;
}

int main()
{
    int n;
    cin>>n;
    take_input(n);
}





