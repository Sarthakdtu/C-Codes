#include<iostream>
//#include<string>
//#include<vector>
using namespace std;


int t=0;

int lcs_dp(string s1, string s2)
{
	int m= s1.size()+1;
	int n= s2.size()+1;
	int **L=new int*[m];
	for(int i=0;i<m;i++)
	{
		L[i]=new int[n];
		for(int j=0;j<n;j++)
		{
			if(i==0||j==0)
			{
				L[i][j]=0;
			}
			else if(s1[i-1]==s2[j-1])
			{
				if(s1[i]=='B')
				{
					cout<<"At B\n";
				}
				L[i][j]=1+L[i-1][j-1];
			}
			else
			{
				L[i][j]=max(L[i-1][j], L[i][j-1]);
			}
		}
	}
	
	string l="";
	int i=m;
	int j = n;
	while(i&&j)
	{
		if(s1[i-1]==s2[j-1])
		{
			l = s1[i-1]+l;
			i--;
			j--;
		}
		else if(L[i-1][j]>L[i][j-1])
		{
			i--;
		}
		else
		{
			j--;
		}
	}
	cout<<"\n";
	cout<<l;
	
	return L[m-1][n-1];
	
}




int lcs_length_aux(string s1, string s2, int m, int n)
{
	::t++;
	if(m==0||n==0)
	{
		return 0;
	}
	else if(s1[m-1]==s2[n-1])
	{
		return 1+lcs_length_aux(s1, s2, m-1, n-1);
	}
	else
	{
		return max(lcs_length_aux(s1, s2, m-1, n), lcs_length_aux(s1, s2, m, n-1));
	}
}



int lcs_length(string str1, string str2)
{
	return lcs_length_aux(str1, str2, str1.size(), str2.size());
}

int main()
{
	string str1="ABRCDDDD";
	
	
	string str2="ABCDEFGHABCDDDD";
	
	
	cout<<lcs_length(str1, str2);
	cout<<"\n"<<::t;
	cout<<"\n"<<lcs_dp(str1, str2);
	
	return 0;
}















