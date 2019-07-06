/*Hasan has finally finished his final exams and he decided to go in a trip among cities in Syria.
There are N cities in Syria and they are numbered from 1 to N, each city has 
coordinates on plane, i-th city is in (Xi, Yi).
Hasan is in first city and he wants to visit some cities by his 
car in the trip but the final destination should be N-th city
and the sequence of cities he will visit should be increasing in 
index (i.e. if he is in city i he can move to city j if and only if i < j ).
Visiting i-th city will increase Hasan's happiness by Fi units (including first 
and last cities), also Hasan doesn't like traveling too much, so his happiness
 will decrease by total distance traveled by him.
 
Help Hasan by choosing a sequence of cities to visit which maximizes his happiness.

Input format:
First line contain integer N.
Next N lines contains three integers each, i-th line contains coordinates of i-th city Xi, Yi and Fi.

Output format:
Output one number rounded to 6 digits after floating point, the maximum possible happiness Hasan can get.
 Note: If answer is 2 print 2.000000
 
Constraints:
1 <= N <= 3,000
0 <= Xi, Yi, Fi <= 100,000

Sample Input
3
0 0 1
3 1 1
6 0 9

Sample Output
4.675445
*/
#include<iostream>
#include<iomanip>
#include<math.h>
using namespace std;

float distance(float a, float b, float c, float d){
	float sqa = (a-c)*(a-c);
	sqa += (b-d)*(b-d); 
	
	sqa = sqrt(sqa);
	return sqa;
}

float findRec(int *X, int *Y, int *F, int n) 
{
	//cout<<"At n = "<<n<<endl;
	if(n==1)
	{
		return F[0];
	}

	float curr=0;
	float max =0;
	
	for(int i=1;i<n;i++)
	{
		curr = findRec(X+i, Y+i, F+i, n-i) - distance(X[0], Y[0], X[i], Y[i]);
		if(curr>max)
		   max = curr;
	}
	max = max + F[0];
	return max;
}


float findFunDp(int *X, int *Y, int *F, int n)
{
	float *dp = new float[n];
	dp[0] = F[0];
	for(int i=1;i<n;i++)
	{
		dp[i] = -1000000;
		for(int j=0;j<i;j++)
		{
			float x = distance(X[i], Y[i], X[j], Y[j]);
			dp[i] = max(dp[i], dp[j] - x);
		}
		dp[i] += F[i];
	}
	return dp[n-1];
}

int main()
{
	int n;
	cin>>n;
	int *X = new int[n];
	int *Y = new int[n];
	int *F = new int[n];
	
	for(int i=0;i<n;i++)
	{
		cin>>X[i]>>Y[i]>>F[i];
	}
	cout<<fixed;
	cout<<setprecision(6)<<findRec(X, Y, F, n)<<"\n"<<findFunDp(X, Y, F, n);
	return 0;
}


























