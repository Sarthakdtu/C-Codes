/*
Monk's best friend Micro's birthday is coming up. Micro likes Nice Strings very much, so Monk decided to gift him one. Monk is having N nice strings, so he'll choose one from those. But before he selects one, he need to know the Niceness value of all of those. Strings are arranged in an array A, and the Niceness value of string at position i is defined as the number of strings having position less than i which are lexicographicaly smaller than . Since nowadays, Monk is very busy with the Code Monk Series, he asked for your help. 
Note: Array's index starts from 1.

Input:
First line consists of a single integer denoting N.
N lines follow each containing a string made of lower case English alphabets.

Output:
Print N lines, each containing an integer, where the integer in  line denotes Niceness value of string .

Constraints:

, where  denotes the length of  string.

SAMPLE INPUT 
4
a
c
d
b
SAMPLE OUTPUT 
0
1
2
1
Explanation
Number of strings having index less than 1 which are less than "a" = 0
Number of strings having index less than 2 which are less than "c": ("a") = 1 
Number of strings having index less than 3 which are less than "d": ("a", "c") = 2 
Number of strings having index less than 4 which are less than "b": ("a") = 1
*/
#include<bits/stdc++.h>
using namespace std;

int findPos(string str, multiset<string> lexical)
{
    set<string> ::iterator it;
    int count=0;
    for(it=lexical.begin();it!=lexical.end();it++)
    {
        string curr = *it;
        cout<<curr<<" , ";
        if(curr==str)
        {
            return count;
        }
        count++;
    }
    return -1;
}

void findNum(vector<string> str, vector<multiset<string>> lexMin)
{
    cout<<0<<endl;
    for(int i=1;i<str.size();i++)
    {
        cout<<findPos(str[i], lexMin[i])<<endl;
    }
}

int main()
{
    int n;
    cin>>n;
    vector<string> str(n);
    vector<multiset<string>> lexMin(n);
    cin>>str[0];
    lexMin[0].insert(str[0]);
    for(int i=1;i<n;i++)
    {
            cin>>str[i];
            lexMin[i]=lexMin[i-1];       
            lexMin[i].insert(str[i]);
    }
    //lexMin[0].clear();
    findNum(str, lexMin);
    return 0;
}
