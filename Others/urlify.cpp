#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

string urlify(string s1,string s2)
{
	for(int i =0;i<s1.length();i++)
	{
		if(s1[i]==' ')
		{
			s1.replace(i,1,s2); 
		}
		
	}
	
	return s1;
}

int main()
{
	string s1 = "abb abb acc dda ";
	string s2 = "%20";
	cout<<urlify(s1, s2);
	return 0;
}

