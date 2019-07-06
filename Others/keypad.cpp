#include <string>
#include<iostream>
using namespace std;
//SARTHAK

string comb(int n)
{
  switch(n)
  {
    case 2:{
      return "abc";
    }
    case 3:{
      return "def";
    }
    case 4:{
      return "ghi";
    }
    case 5:{
      return "jkl";
    }
    case 6:{
      return "mno";
    }
    case 7:
      {
        return "pqrs";
      }
    case 8:
      {
        return "tuv";
      }
    case 9:{
      return "wxyz";
    }
    default:{
      return "";
    }
  }
}


int keypad(int num, string output[]){
    /* Insert all the possible combinations of the integer number into the output string array. You do not need to
    print anything, just return the number of strings inserted into the array.
    */
  
  
  if(num==0)
  {
    output[0]="";
    return 1;
  }
  
  int small = keypad(num/10, output);
  int rem = num%10;
  
  string c = comb(rem);
  string *new_output = new string[rem*small];
  int count=0;
  
  for(int i=0;i<small;i++)
  {
    for(int j=0;j<c.size();j++)
    {
      new_output[count] = output[i]+c[j];
      count++;
    }
  }
 // cout<<"Op"<<endl;
  
	cout<<"Actual Op"<<endl;
  for(int i=0;i<count;i++)
	{
		cout<<new_output[i]<<endl;
	}
  for(int j=0;j<count;j++)
    {
      output[j] = new_output[j];
      
    }
  cout<<"New op"<<endl;
  for(int i=0;i<count;i++)
	{
		cout<<output[i]<<endl;
	}
  return count;
  
}

int main()
{
	//string str="abaaac";
	string *output = new string[1000];
	int n=345;
	
	int count = keypad(n ,output);
	for(int i=0;i<count;i++)
	{
		cout<<output[i]<<endl;
	}
	return 0;
}

