#include<iostream>
#include<vector>
using namespace std;

void display(vector<int> v)
{
	cout<<"\n";
	for(int i=0;i<v.size();i++)
	{
		cout<<v[i]<<" ";
	}
}

vector<int> countSort(vector<int> a, int k)
{
	k++;
	vector<int> b(a.size());
	int *c=new int[k]();
	for(int i=0;i<k;i++)
	{
		c[a[i]]++;
	}
	cout<<"\n";
	
	for(int i=1;i<k;i++)
	{
		c[i]=c[i]+c[i-1];
	}
	cout<<"\n";
	for(int i=0;i<a.size();i++)
	{
		cout<<"\nPicking "<<a[i]<<" putting it in "<<c[a[i]] ;
		b[c[a[i]]]=a[i];
		c[a[i]]--;
	}
	display(b);
	return b;
}


int main()
{
	vector<int> v;
	v.push_back(2);
	v.push_back(3);
	v.push_back(7);
	v.push_back(6);
	v.push_back(3);
	v.push_back(3);
	v.push_back(2);
	v.push_back(1);
	v.push_back(9);
	v.push_back(7);
	v.push_back(7);
	int k=9;
	vector<int> b;
	display(v);
	b = countSort(v ,k);
	cout<<"\n";
	display(b);
	return 0;
}



