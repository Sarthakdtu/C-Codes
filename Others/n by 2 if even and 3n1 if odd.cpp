#include<iostream>
using namespace std;
typedef long long ll;

ll *arr = new ll[100000000]();

void findSteps(ll i)
{
//	cout<<"\nAt "<<i;
	if(arr[i]!=0)
	{
		return ;
	}
	else
	{
		if(i%2==0)
		{
			arr[i] = i/2;
			findSteps(i/2);
			//cout<<"pushed "<<ans<<" at "<<i<<endl;
		}
		else
		{
			arr[i] = 3*i+1;
			findSteps(3*i+1);
			//cout<<"pushed "<<ans<<" at "<<i<<endl;
			
		}
	}
}

void n23n1()
{
	arr[1]=1;
	//cout<<"For 7";
	//findSteps(7);
	cout<<"Calculating....."<<endl;
	for(ll i=2;i<13332;i++)
	{
		if(arr[i]==0)
		{
			findSteps(i); 
		}
	}
	cout<<"\nNow I am ready!"<<endl;
	
	while(true){
	cout<<"To see the steps enter the no. ";
	ll n;
	cin>>n;
	cout<<endl;
	ll jump=n;
	if(n==0)
	{
		return;
	}
//	cout<<arr[12];
	while(n!=1)
	{
		cout<<n<<" -> ";
		n = arr[n];		
	}
	cout<<1<<endl;
    }
}

int main()
{
	n23n1();
	return 0;
	
}
