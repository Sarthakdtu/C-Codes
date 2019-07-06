#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

bool checkP(string s1,string s2)
{
	if(s1.length()!=s2.length())
	{
		return false;
	}
	
	sort(s1.begin(), s1.end());
	sort(s2.begin(), s2.end());
	for(int i = 0; i<s2.length();i++)
	{
	    if(s1[i]!=s2[i])
	    {
	    	return false;
		}
	}
	return true;
}

int main()
{
	string s1 = "abbabbaccdda";
	string s2 = "abbdbbadacaa";
	cout<<checkP(s1, s2);
	return 0;
}

