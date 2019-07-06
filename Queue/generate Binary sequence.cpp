#include<iostream>
#include<queue>
//#include<string>
using namespace std;

void generateB(int n)
{
	queue<string> q;
	string s;
	q.push("1");
	while(n)
	{
		n--;
		string s1 = q.front();
		cout<<s1<<"\n";
		s= s1;
		q.pop();
		s1.append("0");
		q.push(s1);
		s.append("1");
		q.push(s);
	}
	
	
	
}

int main()
{
	int n;
	cin>>n;
	generateB(n);
	return 0;
}
