#include<iostream>
#include<string>

using namespace std;

struct val
{
    int b;
    int l;
};

val max(val a1, val a2)
{
    if(a1.b>a2.b)
        return a1;
    return a2;    
}

val findMaxBlessing(string s, string t, int k)
{
    if(s.size()==0||t.size()==0)
    {
        return {0, 0};
    }
    else
    {
        if(k==0)
            return {0, 0};
        else
        {
            if(s[0]==t[0])
            {
                val ans1 = findMaxBlessing(s.substr(1, s.size()),
                                           t.substr(1, t.size()), k-1);
                ans1.b += s[0];
                ans1.l += 1; 

                val ans2 = findMaxBlessing(s.substr(1, s.size()),
                                           t.substr(1, t.size()), k);
                                                                          
                return max(ans1, ans2);
            }
            else
            {
                val ans1 = findMaxBlessing(s.substr(1, s.size()),t, k);
                val ans2 = findMaxBlessing(s,t.substr(1, t.size()), k);
                return max(ans1,ans2);
            }            
        }    
    }
}

int main()
{
    string s, t;
    int k;
    cin>>s>>t>>k;
    int len=0;
    val ans = findMaxBlessing(s, t, k);
    cout<<"Length : "<<ans.l<<endl;
    cout<<"Blessing : "<<ans.b;
}