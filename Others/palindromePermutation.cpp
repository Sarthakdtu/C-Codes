#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

bool checkPalindromePermutation(string s)
{
	int arr[26] = {0};
	for(int i =0;i<s.length();i++)
	{
		int ch = s[i];
		if(s[i]==' '){
			continue;
		}
		ch = ch-97;
		arr[ch]++;
	}
	int odd =0;
	for(int i =0; i < 26 ;i++)
	{
		if(arr[i]>0 && arr[i]%2!=0)
		{
			if(odd == 1)
			{
				return false;
			}
			else
			{
				odd =1;
			}
		}
	}
	
	return true;
}

int main()
{
	string s = "taco cat ";
	
	cout<<checkPalindromePermutation(s);
	return 0;
}

