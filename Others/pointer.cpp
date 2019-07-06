#include<iostream>
using namespace std;




int main()
{
	int x=2;
	void *p;
	p = (int*)&x;
	
	cout<<p<<endl;
	float b=0.2;
 
     p = (float*)&b;
	cout<<p;
	return 0;
}
