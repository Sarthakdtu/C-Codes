#include<iostream>
#include<set>
#include<string>
using namespace std;
 
void findSuffix(string str, int k)
{
	set<string> suffix;
	
	for(int i=0;i<str.size();i++)
	{
		string subs = str.substr(i, str.size());
		suffix.insert(subs);
	}
	set<string> ::iterator it = suffix.begin();
	
	if(suffix.size()>=k)
	{
		advance(it, k-1);
		cout<<*it;
	}
}

int main()
{
	string str;
	int k;
	cin>>str>>k;
	findSuffix(str, k);
	return 0;
}


