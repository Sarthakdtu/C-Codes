#include<iostream>
#include<string>
using namespace std;

int editDistance(string s, string t)
{
	if(s.length()==0 || t.length()==0)
	{
		return (s.length()>t.length()?s.length():t.length());
	}
	string subs = s.substr(1,s.size());
	string subt = t.substr(1,t.size());
	if(s[0]==t[0])
	{
		return editDistance(subs, subt);
	}
	else
	{
		return 1+min(min(editDistance(subs, subt), editDistance(subs, t)), editDistance(s, subt));
	}
}

int dpED(string s, string t)
{
	int **dp=new int*[s.size()+1];
	for(int i=0;i<s.size()+1;i++)
	{
		dp[i] = new int[t.size()+1]();
	}
	
	for(int i=0;i<s.size()+1;i++)
	{
		dp[i][0] = i;
	}
	for(int i=0;i<t.size()+1;i++)
	{
		dp[0][i] = i;
	}
	
	
	for(int i=1;i<s.size()+1;i++)
	{
		for(int j=1;j<t.size()+!;j++)
		{
			if(s[i-1]==t[j-1])
			{
				dp[i][j] = dp[i-1][j-1];
		    }
		    else
		    {
		    	dp[i][j] = 1 + min(min(dp[i-1][j], dp[i][j-1]), dp[i-1][j-1]); 
			}
		}
	}
	return dp[s.size()][t.size()];
}

int main()
{
	string s, t;
	cin>>s>>t;
	cout<<editDistance(s, t)<<endl;
	cout<<dpED(s, t);
	return 0;
}




