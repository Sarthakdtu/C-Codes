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

int main()
{
   	int b = 10;
   	int a = 16;
   	
   	Triplet t= gcdExtended(a, b);
   	cout<<t.x<<" "<<t.y;
	return 0;
}



