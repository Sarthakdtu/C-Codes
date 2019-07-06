#include<bits/stdc++.h>
#include<iostream>
using namespace std;

int main()
{
	string s1="abc";
	string s2="daef";
	char one[] = "geeksforgeeks"; 
    char two[] = "Gfg"; 
      
      cout<<"l";
    // using lexicographical_compare for checking  
    // is "one" is less than "two" 
    // returns false as "g" has larger ASCII value than "G" 
    if( lexicographical_compare(one, one+13, two, two+3)) 
    { 
        cout << "geeksforgeeks is lexicographically less than Gfg\n"; 
          
    }
	else 
	cout<<"s";
    cout<<lexicographical_compare(s1.begin(),s1.end(), s2.begin(), s2.end());   
    
    return 0;
}
