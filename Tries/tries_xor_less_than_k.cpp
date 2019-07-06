//BUGGY
#include<iostream>

using namespace std;

class node
{
    public:
    node* one;
    node* zero;
};
void insert(int n, node* trie)
{
    node *curr = trie;
    for(int i=31;i>=0;i--)
    {
        int b=(n>>i)&1;
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
int countLeaf(node *parent)
{
    if(parent==NULL)
    {
        return 0;
    }
    else
    {
        int left = countLeaf(parent->zero);
        int right = countLeaf(parent->one);
        int ans = left+right;
        if(ans == 0)
            return 1;
        return ans;    
    }
}
int findSubXor(int p, node* trie, int k)
{
    int count = 0;
    node *curr = trie;
    for(int i=31;i>=0;i--)
    {
        int bk= (k>>i)&1;
        int bp= (p>>i)&1;

        if(bp==0)
        {
            if(bk==0)
            {
                curr = curr->zero;
            }
            else
            {
                int leaf = countLeaf(curr->zero);
                //cout<<"Leaf at zero = "<<leaf<<endl;
                count += leaf;
                curr = curr->one;
                //cout<<"Nope"<<endl;
            }
        }
        else
        {
            if(bk==0)
            {
                curr = curr->one;
            }
            else
            {
                int leaf = countLeaf(curr->one);
                //cout<<"Leaf at one = "<<leaf<<endl;
                count += leaf;
                curr = curr->zero;
                //cout<<"Nope"<<endl;
            }
        }
        if(!curr)
        	break;
    }
    return count;
}

void take_input()
{
    int n, k;
    cin>>n>>k;
    int *arr = new int[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];

    node* trie = new node();
    int preXor = 0;
    for(int i=0;i<n;i++)
    {
        preXor = preXor^arr[i];
        insert(preXor, trie);
    }   
    int ans = findSubXor(preXor, trie, k);
    if(arr[0]<k)
        ans++;
    cout<<"Answer : ";
    cout<<ans<<endl;
}
int main()
{
    int t;
    cin>>t;
    while(t)
    {
        t--;
        take_input();
    }
    return 0;
}
