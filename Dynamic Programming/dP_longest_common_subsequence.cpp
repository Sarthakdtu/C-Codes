#include<iostream>
#include<string>

using namespace std;

int lcsRec(string s, string t)
{
    if(s.size()==0||t.size()==0)
    {
        return 0;
    }
    else
    {
        if(s[0]==t[0])
        {
            return 1+lcsRec(s.substr(1,s.size()), t.substr(1, t.size()));
        }
        else
        {
            return max(lcsRec(s, t.substr(1, t.size())),
                       lcsRec(s.substr(1,s.size()), t));
        }
    }
}

int lcsDp(string s, string t)
{
    int n = s.size();
    int m = t.size();
    int **dp = new int*[n+1];
    for(int i=0;i<n+1  ;i++)
        dp[i]  =new int[m+1]();

    for(int i=1;i<n+1;i++)
    {
        for(int j=1;j<m+1;j++)
        {
            if(s[i-1]==t[j-1])
            {
                //cout<<"equal"<<endl;
                dp[i][j] = dp[i-1][j-1]+1;
            }
            else
            {
                //cout<<"unequal"<<endl;
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }            
        }
    }    
    return dp[n][m];
}

int main()
{
    string s1, s2;
    cin>>s1>>s2;
    cout<<lcsRec(s1, s2)<<endl;
    cout<<lcsDp(s1, s2);
}