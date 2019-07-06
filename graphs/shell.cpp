#include<iostream>
#include<string>
#include<bits/stdc++.h>
//loop(i,1,9,1)
using namespace std;

void loop(string var, int from, int to, int add=1)
{
	for(int i=from;i<to;i+=add)
	{
		cout<<var<<" = "<<i<<endl;
	}
}

int parseNumber(string s, int &a)
{
	string num ="";
	int i=0;
	
	for(i=a+1;i<s.size();i++)
	{
		//cout<<s[i]<<endl;
		if(s[i]==','||s[i]==')')
		{
			break;
		}
		else if(s[i]==' ')
		{
			;
		}
		else
		{
			num = num+s[i];
		}
	}
	
	a = i;
	int n=-1;
	bool flag = false;
	for(int i=0;i<num.size();i++)
	{
		flag = true;
		int digit = num[i]-'0';
		if(n==-1)
		{
			n=digit;
		}
		else
		n = n*10 + digit;
	}
	return n;
}

void check(string s)
{
	string var="";
	int from;
	int to;
	int add;
	int i;
	for(i=5;i<s.size();i++)
	{
		if(s[i]==',')
		 break;
		else if(s[i]==' ')
		 continue; 
		var=var+s[i];
	}
	////cout<<"I is "<<i<<endl;
	cout<<"Variable is "<<var<<endl;
	from = parseNumber(s, i);
	//cout<<"I is "<<i<<endl;
	cout<<"From "<<from<<endl;
	to = parseNumber(s, i);
	//cout<<"I is "<<i<<endl;
	cout<<"To "<<to<<endl;
	add = parseNumber(s, i);
	//cout<<"I is "<<i<<endl;
	cout<<"Add "<<add<<endl;
	//cout<<"I is "<<i<<endl;
	loop(var, from , to, add);
}

int main()
{
	string str;
	while(true)
	{
		getline(cin, str);
		cout<<endl;
		check(str);
		cout<<endl;
		cout<<"\nEnter again\n";
	}
	return 0;
}
