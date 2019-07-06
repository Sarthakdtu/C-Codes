#include<iostream>
#include<string>
#include<cstdio>
#include <cstring>
#include<algorithm>
using namespace std;

int ascii(char c)
{
	return (int)c;
}

void stats(string s, string t, int k, int curr_sum, int add)
{
	cout<<endl;
	if(add>0)
	{
		cout<<"IF "<<add;
	}
	else
	{
		cout<<"ELSE";
	}
	cout<<endl;
	cout<<s<<"  "<<t<<" k = "<<k<<" c = "<<curr_sum<<endl;
	
}

int findR(string s, string t, int k, int curr_sum)
{
	if(k==0)
	{
		return curr_sum;
	}
	else if(k<0)
	{
		return 0;
	}
	
	if(s.size()==0||t.size()==0)
	{
		if(k==0)
		{
			return curr_sum;
		}
		return 0;
	}
	
	//cout<<"S = "<<s<<endl;
	//cout<<"T = "<<t<<endl;
	

	
	string subs = s.substr(1,s.size());
	string subt = t.substr(1,t.size());
	if(s[0]==t[0])
	{
		/*cout<<"Including"<<endl;
		stats(subs, subt, k-1, curr_sum, ascii(s[0]));
		cout<<"Not Including"<<endl;
		stats(subs, subt, k-1, curr_sum, 1);*/
		return max(findR(subs, subt, k-1, curr_sum+ascii(s[0])), findR(subs, subt, k, curr_sum));
	}
	else
	{
		//stats(subs, subt, k-1, curr_sum, 0);
		return max(max(findR(subs, subt, k, curr_sum), findR(subs, t, k, curr_sum)), findR(s, subt, k, curr_sum));
	}
}

int findBRec(string s, string t, int k)
{
	return findR(s, t, k, 0);
}

int findBDP(string s, string t, int k)
{
	int dp[s.size()+1][t.size()+1][(s.size()>t.size()?s.size():t.size())];
	int lcs[s.size()+1][t.size()+1];
	memset(dp, 0, sizeof(dp));
	memset(lcs, 0, sizeof lcs);
	
	for(int i=1;i<s.size()+1;i++)
	{
		for(int j=1;j<t.size()+1;j++)
		{
				if(s[i-1]==t[i-1])
				{
					lcs[i][j] = 1 + lcs[i-1][j-1]; 
						for(int x=1;x<k+1;x++)
			            {
			            	dp[i][j][x] = max(dp[i-1][j-1][x-1]+ascii(s[i-1]), dp[i-1][j-1][x]);
			            }
				}
				else
				{
                        lcs[i][j] = max(lcs[i][j-1], lcs[i-1][j]); 
						for(int x=1;x<k+1;x++)
			            {
			            	dp[i][j][x] = max(dp[i-1][j][x], dp[i][j-1][x]);
			            }				
				}
		}
	}
	
	for(int i=0;i<s.size()+1;i++)
	{
		for(int j=0;j<t.size()+1;j++)
		{
			for(int x=0;x<k+1;x++)
			{
				cout<<dp[i][j][x]<<" ";
			}
			cout<<"\n end of a j\n";
		}
		cout<<"end of an i\n";
	}
	
	if(lcs[s.size()][t.size()]<k)
	{
		return 0;
	}
	return dp[s.size()][t.size()][k];
}



int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	   string s, t;
	   int k;
	//cout<<ascii('a');
	cin>>s>>t>>k;
	//cout<<findBRec(s, t, k)<<endl;
	cout<<findBDP(s, t, k)<<endl;	
	}
	
	return 0;
}
