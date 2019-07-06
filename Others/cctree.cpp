#include<iostream>
#include<string>
#include<map>
#include<algorithm>
using namespace std;

string parser(map<int, string> m, string tree, int x)
{
	int root =0;
	m[root]=tree[0];
//root--;
	bool isright=false;
	for(int i =1;i<tree.size();i++)
	{
		if(tree[i]!=')'&&tree[i]!='(')//!isright)
		{
			//root--;
			if(!isright){
			cout<<"inserting "<<tree[i]<<" at "<<root<<" and is right(!) is "<<isright<<endl; 
			m[root]=m[root]+tree[i];
			isright=!isright;
		}
		else{		
			//cout<<"b is at 1"<<endl;
			root+=2;
			cout<<"inserting "<<tree[i]<<" at "<<root<<" and is right is "<<isright<<endl; 
			m[root]=m[root]+tree[i];
			isright=!isright;
		}
		}
		else if(tree[i]=='(')
		{
			root--;
			if(isright)
			isright=!isright;
		//	cout<<"at ("<<endl;
		}
		else if(tree[i]==')')
		{
			//cout<<"at )"<<endl;
			root+=1;
			
		}
		
	}
	

	
	return m[x];
	
	
}
//a(b(..)c(..))

string getX(string tree, int x)
{
	map<int, string> m;
	string ans = parser(m, tree, x);
	if(ans=="")
	{
		return "Hallelujah!";
	}
	sort(ans.begin(), ans.end());
	string new_ans="";
	for(int i=0;i<ans.size();i++)
	{
		if(ans[i]!='.')
		{
			new_ans=new_ans+ans[i];
		}
	}
	if(new_ans=="")
	{
		return "Hallelujah!";
	}
	return new_ans;
	
	
}
/*
3
-1
a(d(.c(b(a(.b(..)).).))c(..))
3
a(b(..)c(..))
2
a(b(..)c(d(..)e(f(..).)))

*/

int main()
{
	int t;
	cin>>t;
	
	while(t)
	{
		t--;
		string tree;
		int x ;
		cin>>x;
		cin>>tree;
		
		string ans =getX(tree, x);
		cout<<ans;
	}
	
	return 0;
}
//a(b(c(h(..).)d(..))e(f(..)g(..))
