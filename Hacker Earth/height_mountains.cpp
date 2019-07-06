#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

struct num{
    ll l;
    ll r;
    ll bw;
    ll tn;
};

ll findElt(vector<num> arr, ll n)
{
    ll elt;
    num point;
    ll start =0;
    ll end = arr[arr.size()-1].tn;
    while(start<end)
    {
    	 mid  = (end - start)/2 + (start/2);
    	if(mid==)
	}

    ll pos = point.tn-n;
    elt = point.l + (pos-1);
    return elt;
}

void take_input(ll n, ll q)
{
    vector<num> arr(n);
    ll prev=0;
    for(int i=0;i<n;i++)
    {
        ll a, b;
        cin>>a>>b;
        prev += b-a+1;
        arr.push_back({a, b, b-a+1, prev});
    }
    for(int i=0;i<q;i++)
    {
        ll k;
        cin>>k;
        cout<<findElt(arr, k)<<endl;
    }
}   

int main()
{
    ll n, q;
    cin>>n>>q;
    take_input(n, q);
}
