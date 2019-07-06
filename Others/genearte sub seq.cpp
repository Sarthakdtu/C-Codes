#include<iostream>
#include<string>
#include<vector>
using namespace std;

vector<string> generateSubS(string str)
{
	if(str=="")
	{
		vector<string> v={""};
		return v;
	}
	int n = str.size();
	
	vector<string> v = generateSubS(str.substr(1, str.size()-1)) ;
	vector<string> ans;
	for(int i=0;i<v.size();i++)
	{	
		string a= v[i];
	//	cout<<a<<"\n";
		ans.push_back(a);
		a= str[0]+a;
	//	cout<<a<<"\n";
		ans.push_back(a);
	}
	
	
	return ans;	
	
}


int main()
{
	string str1="ABCDDDD";
	vector<string> v1 = generateSubS(str1);
	
	string str2="ABCDEFGHABCDDDD";
	vector<string> v2 = generateSubS(str2);
	
	cout<<"v1\n";
	for(int i =0;i<v1.size();i++)
	cout<<v1[i]<<"\n";
	
	cout<<"v2\n";
	for(int i =0;i<v2.size();i++)
	cout<<v2[i]<"\n";
	
	
	
	cout<<"Equal Ones\n";
	for(int i =0;i<v1.size();i++)
	{
		for(int j = 0;j<v2.size();j++)
		{
			if(v1[i]==v2[j])
			{
				cout<<v1[i]<<"\n";
			}
		}
	}
	
	
	return 0;
}















