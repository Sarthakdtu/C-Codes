#include<string>
#include<map>
#include<iostream>
using namespace std;
bool isUnique(string s)
{
	map<char, int> freqTable;
	
	for(int i = 0; i<s.length(); i++)
	{
		char c = s[i];
		if(freqTable[c]==1)
		{
			return false;
		}
		else
		{
		    freqTable[c]=1;	
		}
	}
	return true;
}

int main()
{
	
	string s ="col ude";
	cout<<isUnique(s);
	return 0;
}









