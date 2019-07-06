#include<iostream>
#include<string>

using namespace std;

void print(string ip, string op)
{
  if(ip[0] =='\0')
  {
    cout<<op<<endl;
    return;
  }
  cout<<"At letter "<<ip[0]<<endl;
  
  string op1;
  
  
  
  for(int i=0;i<op.size()+1;i++)
  {
  //	cout<<"Working";
    op1= op.substr(0, i) + ip[0] + op.substr(i) ;
    print(ip.substr(1), op1);
  }
  
  
}

int permutation(string ip, string op[])
{
	//cout<<"At letter "<<ip[0]<<endl;
	if(ip[0]=='\0')
	{
		op[0]="";
		return 1;
	}
	
	string op1[100];
	int size = permutation(ip.substr(1), op1);
	if(op1[0]=="")
	{
		op[0]=ip[0];
		return 1;
	}
	int k=0;
	
	for(int i=0;i<size;i++)
	{
		//cout<<"op1[i].size "<<op1[i].size()<<endl;
		for(int j=0;j<op1[i].size()+1;j++)
		{
			//cout<<op1[i];
			op[k] = op1[i].substr(0, j)+ip[0]+op1[i].substr(j);
			//cout<<"At ip[0]"<<ip[0]<<" op is "<<op[k]<<endl;
			k++;
		}
	}


	
	return k+1;
	
}


int main()
{
	
	string s="abc";
	string output[50];
	string s1="abc";
	cout<<s1.substr(0,1)<<endl;
	for(int j=0;j<s1.size()+1;j++)
		{
			//cout<<op1[i];
		   cout<<s1.substr(0, j)+'d'+s1.substr(j)<<endl;
		}
		cout<<endl;
	int size = permutation(s, output);
	for(int i=0;i<size;i++)
	{
		cout<<output[i]<<endl;
	}
	
	print(s, "");
	return 0;
}


