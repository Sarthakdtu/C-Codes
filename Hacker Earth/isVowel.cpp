#include<bits/stdc++.h>

using namespace std;


void preProcess(map<char, bool> v)
{
    for(char a='A';a!='Z';a++)
    {
        switch(a)
        {
            case 'A':{v[a]=true; break;}
            case 'E':{v[a]=true; break;}
            case 'I':{v[a]=true; break;}
            case 'O':{v[a]=true; break;}
            case 'U':{v[a]=true; break;}
            default:{v[a]=false;}
        }
    }

    for(char a='a';a!='z';a++)
    {
        switch(a)
        {
            case 'a':{v[a]=true; break;}
            case 'e':{v[a]=true; break;}
            case 'i':{v[a]=true; break;}
            case 'o':{v[a]=true; break;}
            case 'u':{v[a]=true; break;}
            default:{v[a]=false;}
        }
    }
}

int countVowels(string str, map<char, bool> v)
{
    int count=0;
    for(int i=0;i<str.size();i++)
    {
        if(v[str[i]])
            count++;
    }
    return count;
}

int main()
{
    map<char, bool> vowel;
    preProcess(vowel);
    int t;
    cin>>t;
    while(t)
    {
        t--;
        string str;
        cin>>str;
        cout<<countVowels(str)<<endl;
    }
}