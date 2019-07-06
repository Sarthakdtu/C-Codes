#include<iostream>
using namespace std;

class Triplet
{
	public:
		int x;
		int y;
		int g;
};



Triplet gcdExtended(int a, int b)
{
	if(b==0)
	{
		Triplet myans;
		myans.g = a;
		myans.x = 1;
		myans.y = 0;
		return myans;
	}
	Triplet sans = gcdExtended(b, a%b);
	Triplet myans;
	myans.x = sans.y;
	myans.y = sans.x - sans.y*(a/b);
	myans.g = sans.g;
	return myans;
	
}


void findModInv(int a, int m)
{
	Triplet ans = gcdExtended(a, m);
	if(ans.g==1&&ans.x<m&&ans.x>0)
	{
		cout<<"Yes "<<ans.x;
		return ;
	}
	cout<<"No ";
	cout<<ans.x;
	
}


int main()
{
   	int m = 7;
   	int a = 31;
   	
   	findModInv(a, m);
   	
	return 0;
}



