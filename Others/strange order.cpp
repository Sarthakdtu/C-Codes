#include<bits/stdc++.h>
#include<vector>
using namespace std;

void display(vector<int> v)
{
	int a=0;
	vector<int>::iterator i;
	for(i = v.begin();i!= v.end();i++)
	{
	    a++;
		cout<<*i<<" ";
	}
//	cout<<"no of elmnts "<<a;
}

void displayA(int *arr, int n)
{
	for(int i=2;i<n+1;i++)
	cout<<i<<" : "<<arr[i]<<endl;
}

void multiplesLowestPrime(int n, int* fac)
{
	for(int i=2;i<n+1;i++)
	{
		if(fac[i]==i)
		{
			for(int j=i;j<n+1;j+=i)
			{
				if(fac[j]==j)
				  fac[j]=i;
			}
		}
	}
}

vector<int> fillVector(int a, int p, bool* arr, int n)
{
	vector<int> v;
	for(int i=a;i>1;i-=p)
	{
		if(!arr[i])
		{
			v.push_back(i);
			//cout<<"Currently at "<<i<<endl;
		}
		arr[i]=true;
		
	}
	return v;
}

int nextFactor(int a, int p)
{
	a=a/p;
	while(a%p==0&&a!=1)
	{
	//	cout<<a<<" "<<p<<endl;
		a=a/p;
	}
	return a;
}

void strangeOrder(int n)
{
	bool *arr= new bool[n+1]();
	int *fac = new int[n+1];
	for(int i =2;i<n+1;i++)
	    fac[i] = i;
	fac[1]=0;
	fac[0]=0;
	multiplesLowestPrime(n, fac);                      //marks lowest prime factors
	//displayA(fac, n);
	vector<int> v;
	
	for(int i=n;i>1;i--)
	{
		if(!arr[i])
		{
		    //displayA(fac, n);	
		    vector<int> v1;
			v1 = fillVector(i, fac[i], arr, n);               //manages the array
			int idx = nextFactor(i, fac[i]);                   //next Lowest Prime Factor
			fac[i] = 1;
			int lf = fac[idx];
			fac[idx]=1;			                                  
			while(lf>1)
			{
				
				vector<int> v2;
				v2 = fillVector(i, lf, arr, n);     
			            
				v1.insert( v1.end(), v2.begin(), v2.end() );
				
				idx = nextFactor(idx, lf);
			
				lf = fac[idx];
				fac[idx]=1;
				
			}
			
            sort(v1.begin(), v1.end(), greater<int>()); 
            
            v.insert( v.end(), v1.begin(), v1.end() );
		}
	}
	v.push_back(1);
	display(v);
}


int main()
{
	int n=631;
	strangeOrder(n);
	return 0;
}












