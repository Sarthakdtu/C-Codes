#include<iostream>
#include<queue>
#include<string>
using namespace std;

void lexico(int n)
{
	queue<string> q;
	string s;

	int no=1;
	
	while(n)
	{
	  int i=0;
	  string sno = to_string(no);
	  q.push(sno);	
	  
	  string s1 = q.front();
	  cout<<s1<<"\n";
	  q.pop();    
	  n--;
	  while(i<10)
	  {
		string a=to_string(i);	
		string s =s1;
		if(s.size()<2)
		{
			q.push(s.append(a));
		}
		i++;
	  } 
	  while(!q.empty()&&n)
	  {
	  	n--;
	  	s1 = q.front();
	    cout<<s1<<"\n";
	    q.pop();    
	  }
	   no++; 
    }

	
}

int main()
{
	int n;
	cin>>n;
	lexico(n);
	int lim = 12;
	//string ch= to_string(lim);
	//cout<<"j "<<ch;
	return 0;
}
