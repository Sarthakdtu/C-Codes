#include<iostream>
#include<string>

using namespace std;

string encrypt(string s)
{
	string st="";
	bool flag = true;
	for(int i=0;i<s.size();i++)
	{
		st="";
		if(s[i]==' ')
		{
			flag = true;
			cout<<""<<st<<endl;
			continue;
		} 
		else if(flag)
		{
			int prev = i;
			int l = 1;
			while(i<s.size()&&s[i]!=' ')
			{
				l++;
				i++;
			}
			
			st = s.substr(prev+1, l-3) + s[i] + "ay ";
			cout<<st;
			i--;
			flag = false;
		}
		  
	}
	return st;
}

void pigLatin(int t)
{
	string str="hello world this is it";
	cout<<encrypt(str);
	/*for(int i=0;i<t;i++)
	{
		getline(cin, str, '\n');
		cout<<"Bruh";
		cout<<encrypt(str)<<endl;
	}	
	*/
}

int main()
{
	int t;
	cin>>t;
	pigLatin(t);
	return 0;
}
