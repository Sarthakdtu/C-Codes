/*
PARTY - Problem
Send Feedback
You just received another bill which you cannot pay because you lack the money.
Unfortunately, this is not the first time to happen, and now you decide to investigate the cause of your constant monetary shortness. The reason is quite obvious: the lion's share of your money routinely disappears at the entrance of party localities.
You make up your mind to solve the problem where it arises, namely at the parties themselves. You introduce a limit for your party budget and try to have the most possible fun with regard to this limit.
You inquire beforehand about the entrance fee to each party and estimate how much fun you might have there. The list is readily compiled, but how do you actually pick the parties that give you the most fun and do not exceed your budget?
Write a program which finds this optimal set of parties that offer the most fun. Keep in mind that your budget need not necessarily be reached exactly. Achieve the highest possible fun level, and do not spend more money than is absolutely necessary.
Input
The first line of the input specifies your party budget and the number n of parties.

The following n lines contain two numbers each. The first number indicates the entrance fee of each party. Parties cost between 5 and 25 francs. The second number indicates the amount of fun of each party, given as an integer number ranging from 0 to 10.

The budget will not exceed 500 and there will be at most 100 parties. All numbers are separated by a single space.

There are many test cases. Input ends with 0 0.
Output
For each test case your program must output the sum of the entrance fees and the sum of all fun values of an optimal solution. Both numbers must be separated by a single space. 
Sample Input
50 10
12 3
15 8
16 9
16 6
10 2
21 9
18 4
12 4
17 8
18 9 

50 10
13 8
19 10
16 8
12 9
10 2
12 8
13 5
15 5
11 7
16 2

0 0
Sample Output
49 26
48 32
*/

#include<iostream>
using namespace std;

struct val
{
	int fu;
	int fe;
};

val max(val a1, val a2)
{
	if(a1.fu>a2.fu)
		return a1;
	return a2;	
}

val maxFun(int *fee, int *fun, int m, int p)
{
	val dp[p+1][m+1];

	for(int i=0;i<=p;i++)
	{
		for(int j=0;j<=m;j++)
		{
			if(i==0||j==0)
			{
				dp[i][j]={0, 0};
			}
			else
			{
				val a2 = dp[i-1][j];
				val a1 = {0, 0};
				if(fee[i-1]<=j)
					a1 = {dp[i-1][j-fee[i-1]].fu+fun[i-1],
					  	  dp[i-1][j-fee[i-1]].fe +fee[i-1]};		
				dp[i][j] = max(a1, a2);		
			}
		}
	}
	return dp[p][m];
}

int main()
{
	while(true)
	{
	int money, party;
	cin>>money>>party;
	if(money==0&&party==0)
	{
		break;
	}
	int *fee = new int[party];
	int *fun = new int[party];
	
	for(int i=0;i<party;i++)
	{
		cin>>fee[i]>>fun[i];
	}
	val ans = maxFun(fee, fun, money, party);
	cout<<ans.fe<<ans.fu<<endl;
	}
	return 0;
}
