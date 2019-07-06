#include<iostream>
#include<string.h>
using namespace std;


char letter(int n)
{
	char ch ='a';
	n--;
	return (char)ch+n;
}

int number(char a)
{
   return (int)(a-'0');	
}
void print(string input, string op)
{
  if(input[0]=='\0')
	{
	 cout<<op<<endl;
     return ;
	}
	
	
	
	int rem1 = number(input[0]);
	
	char ch2, ch1 = letter(rem1);
	int sop2=0;
    //string s="";
     
    
	 print(input.substr(1, input.size()),op+ch1);
  
	if(input[1]!='\0'){
	   int rem2 = number(input[1]);
	   if((10*rem1+rem2)<27){
	   ch2 =  letter(10*rem1+rem2);
	   print(input.substr(2, input.size()), op+ch2);
         }  
	   
       }
	
	
}

int letterCombo(string input, string output[]){
	cout<<"At letter"<<input[0]<<endl;
	if(input[0]=='\0')
	{
		output[0]="";
		return 1;
	}
	
	string op1[50];
	string op2[50];
	
	int rem1 = number(input[0]);
	char ch2, ch1 = letter(rem1);
	int sop2=0;
	int sop1 = letterCombo(input.substr(1, input.size()), op1);
	if(input[1]!='\0'){
	   int rem2 = number(input[1]);
	   if((10*rem1+rem2)<27){
	   ch2 =  letter(10*rem1+rem2);
	   sop2 = letterCombo(input.substr(2, input.size()), op2);
         }  
	   
       }
	
	 
	for(int i=0;i<sop1;i++)
	{
		output[i] = ch1+op1[i];
	}
	
	for(int i=0;i<sop2;i++)
	{
		output[i+sop1] = ch2+op2[i];
	}
	
      
	
	return sop1+sop2;
	
	
	
}

int main()
{
	string s ="1123";
	
	string op[100];
	
	for(int i=0;i<4;i++)
	{
		cout<<s[i];
	}
	cout<<"oaky";
	int size = letterCombo(s, op);
	
	for(int i=0;i<size;i++)
	{
		cout<<op[i]<<endl;
	}
	
	string s3="";
	string s2;
      s3= s3+'a';
      cout<<s3+'b';
	
	
	
}



