#include<iostream>
#include<string.h>
#include<stack>
using namespace std;

int opType(char op)
{
	if(op=='!')
    	return 1;
    return 2;	
}

char operate(char op1, char op2, char opr)
{
	if(opr=='!')
	{
		if(op1=='1')
		   return '0';
		return '1';
	}
	else
	{
		if(opr=='&')
		{
			if(op1==op2&&op1=='1')
			{
				return '1';
			}
			return '0';
		}
		else if(opr=='|')
		{
			if(op2=='1'||op1=='1')
			{
				return '1';
			}
			return '0';
		}
	}
	return '\0';
}


char func(string exp)
{
	stack<char> s;
	stack<char> op;
	for(int i=0;i<exp.size();i++)
	{
		if(exp[i]=='0'||exp[i]=='1'||exp[i]=='[')
		{
			s.push(exp[i]);
		}
		else if(exp[i]!=','&&exp[i]!=']')
		{
		   op.push(exp[i]);		
		}
		else if(exp[i]==']')
		{
			char opr = op.top();
			cout<<"Operator is "<<opr<<endl;
			op.pop();
			int type = opType(opr);
			if(type==1)
			{
				char op1 = '\0';
				op1 = s.top();
				cout<<"Operand is type1 ="<<op1<<endl;
				s.pop();
				while(s.top()=='[')
				{
					s.pop();
				}
				char tbp = operate(op1, '\0', opr);
				cout<<"TBP = "<<tbp<<endl;
				s.push(tbp);
			}
			else if(type==2)
			{
				char op1 = '\0';
				char op2 = '\0';
				op1 = s.top();
				s.pop();
				op2 = s.top();
				s.pop();
				cout<<"Operands are type2 ="<<op1<<" "<<op2<<endl;
				while(s.top()=='[')
				{
					s.pop();
				}
				char tbp = operate(op1,op2, opr);
				cout<<"TBP = "<<tbp<<endl;
				s.push(tbp);
				
			}
		}
	}
	return s.top();
}
int main()
{
	string s = "[&1[![|10[&01]]]]";
	cout<<"Answer is = "<<func(s);
	return 0;
}
