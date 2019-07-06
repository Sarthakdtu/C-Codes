#include<iostream>
#include<string>
using namespace std;

int getSubSequence(string str, string *op)
{
	if(str.empty())
	{
		op[0]="";
		return 1;
	}
	string small = str.substr(1);
	int sop = getSubSequence(small, op);
	for(int i = 0;i<sop;i++)
	{
		op[i+sop] = str[0]+op[i];
	}
	return 2*sop;
}




int main()
{
	string str="abaaac";
	string *output = new string[1000];
	int count = getSubSequence(str, output);
	for(int i=0;i<count;i++)
	{
		cout<<output[i]<<endl;
	}
	return 0;
}

