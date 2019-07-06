#include<iostream>
using namespace std;

int main()
{
	int x= 64;
	cout<<(!(x&(x-1)));
	return 0;
}
