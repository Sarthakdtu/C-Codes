#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

string compress(string s)
{
	int counter =1;
	char prev_char = s[0];
	string str ="";
	int l=0;

	for(int i =1;i<s.length();i++)
	{
	   if(s[i]!=s[i-1]){
	   	if(l>=s.length()-1)
	   	{
	   	  return s;	
	    }  
	   	str = str + s[i-1];
		str = str+ to_string(counter);
	   		   	
	   	prev_char = s[i];
	   	counter=1;
	   	l+=2;
	   	
	   }	
	   else{
	   		if(l>=s.length()-2)
	   	{
	   	  return s;	
	    }  
	   	counter++;
	   }
	   
	}
	return str;
}

int main()
{
	string s = "abcdeFGHghijk";
	
	cout<<compress(s);
	return 0;
}

