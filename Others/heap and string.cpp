#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

typedef pair<long, string> pai;
struct Comp
{
   bool operator()(const pai& s1, const pai& s2)
   {
   	    if(s1.first < s2.first)
   	    {
   	    	return true;
		}
       if(s1.first==s2.first ) 
      { 
        return lexicographical_compare(s1.second.begin(),s1.second.end(), s2.second.begin(), s2.second.end());
          
    } 
    return false;
   }
};
/*

if( lexicographical_compare(one, one+13, two, two+3)) 
    { 
        cout << "geeksforgeeks is lexicographically less than gfg"; 
          
    } 
    */
int main()
{
	int n, t;
	cin>>n>>t;
	vector<pai> v;
	for(int i=0;i<n;i++)
	{
		long q;
		string s;
		cin>>s;
		cin>>q;
		v.push_back(make_pair(q,s));
	}
	
    make_heap(v.begin(), v.end(), Comp());
    for(int i=0;i<t;i++)
    {
    	pai p = v.front();
    	cout<<p.second<<endl;
    	pop_heap(v.begin(), v.end()); 
        v.pop_back();
	}
    
	return 0;
}
