/*
// Sample code to perform I/O:

cin >> name;                            // Reading input from STDIN
cout << "Hi, " << name << ".\n";        // Writing output to STDOUT

// Warning: Printing unwanted or ill-formatted data to output will cause the test cases to fail
*/

// Write your code here
#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

ll ans[100005]={0};

ll findSpecialInt(ll *a, ll n, ll x)
{
    ll start = 0;
    ll end = n;
    int mid1, mid2=-1;
    while(start!=end)
    {
    	//cout<<start<<" "<<end<<endl;
    	mid2 = mid1;
        mid1 = (end-start)/2 +start;
        bool flag = 1;
        for(int i=mid1;i<n;i++)
        {
        	if((a[i]-a[i-mid1])>x)
        	{
        		ans[mid1] = (a[i]-a[i-mid1]);
        		flag =0;
        		break;
			}
		}
		if(flag)
		{
			start = mid1;
			if(mid1==mid2){
				break;
			}
		}
		else{
			end = mid1-1;
		}
    }
    if(ans[mid1+1]<x && ans[mid1+1]!=0){
    	cout<<ans[mid1+1]<<endl;
    	cout<<"HEllo World!"<<endl;
    	return mid1+1;
	}
	if(ans[mid1]<=x){
		return mid1;
	}
	else if(ans[mid1-1]<x){
		return mid1-1;
	}
}

int main()
{
    ll n, x;
    cin>>n>>x;
    ll *arr = new ll[n];
    cin>>arr[0];
    for(ll i=1;i<n;i++)
    {
        cin>>arr[i];
        arr[i] += arr[i-1];
    }

    cout<<findSpecialInt(arr, n, x);

    return 0;
}
