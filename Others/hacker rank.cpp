#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

// Complete the alternate function below.

int isalternate(string s, char a, char b)
{
    int len =0;
    bool isa = false;
    int idxa = -1;
    int idxb = -1;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]==a)
        {
            idxa = i;
            break;
        }
        if(s[i]==b)
        {
            idxb = i;
            break;
        }
    
    }
    if(idxb==-1)
    {
        isa=true;
    }
    
    for(int i=idxa+1;i<s.size();i++)
    {
        if(isa)
        {
            if(s[i]==a)
            {
                return 0;
            }
            else if(s[i] == b)
            {
                isa=!isa;
                len++;
            }
        }
        else
        {
            if(s[i]==b)
            {
                return 0;
            }
            else if(s[i] == a)
            {
                isa=!isa;
                len++;
            }
        }
    }
    return len;
}

int check(string s, vector<char> v, vector<char> v1)
{
    int len =0;
    int max = 0;
    for(int i =0;i<v.size();i++)
    {
        for(int j =0;j<v1.size();j++)
        {
            len  = isalternate(s, v[i], v1[j]);
            if(len > max)
                max = len;
        }
    }
    
    return max;
}


int alternate(string s) {
map<int, vector<char>> ntc;
    map<char, int> ctn;
    for(int i=0;i<s.size();i++)
    {
        if(ctn.count(s[i])==0)
        {
            ctn[s[i]] = 0;
        }
       ctn[s[i]] ++;
    }

    
    for(int i =0;i<s.size();i++)
    {
        
        if(ctn[s[i]]!=0)
        {
            if(ntc.count(ctn[s[i]])==0)
            {
                ntc[ctn[s[i]]] ={};
            }
            ntc[ctn[s[i]]].push_back(s[i]); 
            ctn[s[i]] = 0;
        }
    }
    
    sort(ntc.begin(), ntc.end());
    map<int, vector<char>> ::iterator it;
    int len =0;
    int max=0;
    for(it = ntc.begin();it!= ntc.end();it++)
    {
            vector<char> v = it->second;
            vector<char> v1 = (it+1)->second;
            len = check(s, v, v1);
        if(len>max)
        {
            max = len;
        }
    }
    return max;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string l_temp;
    getline(cin, l_temp);

    int l = stoi(ltrim(rtrim(l_temp)));

    string s;
    getline(cin, s);

    int result = alternate(s);

    fout << result << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

