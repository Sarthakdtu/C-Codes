#include<iostream>
#include<vector>
#define push_back pb
#include<math>
using namespace std;

void createPowerN(int n, int x)
{
	vector<int> v;
	int i=0;
	while(pow(i, n)<=x)
	{
		v.pb(i);
		i++;
	}
}

int main()
{
	int n;
	cin>>n;
	int x ;
	cin>>x;
	createPowerN(n, x);
	
	return 0;
}
