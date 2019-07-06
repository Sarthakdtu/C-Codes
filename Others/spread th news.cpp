/*#include<iostream>
using namespace std;

/*7
2 1 1 5 5 5 5
5
5 1 3 2 1

/
int main()
{
	int n;
	cin>>n;
	int *arr= new int[n];
	int total = 1, days =0;
	//bool go =true;
	cin>>arr[0];
	//arr[0]++;
	for(int i=1;i<n;i++)
	{
	  cin>>arr[i];
	  arr[i]+=arr[i-1];
    }
    //arr[0]++;
    int i=0;
    while(i<n)
    {
    	if(total>n)
    	{
    		break;
		}
		days++;
		total = arr[i] + total;
		i = total-1;
	}
    
   /*for(int i=0;i<n;i++)
   {
   	cout<<"At day "<<i<<" people : "<<arr[i]<<endl;
   	total = total+arr[i];
   	days++;
   	if(total>=n)
   	{
   		break;
	}
	i=total-1;
   }
    
    cout<<days;
	return 0;
}
*/
#include<iostream>
using namespace std;

void func()
{
    int n;
	cin>>n;
	long *arr= new long[n];
	long total = 1, days =0;
    cin>>arr[0];
	//arr[0]++;
	for(int i=1;i<n;i++)
	{
	  cin>>arr[i];
	  arr[i]+=arr[i-1];
    }
    long i=0;
    while(i<n)
    {
    	days++;
    	//cout<<"Total : "<<total<<endl;
    	total = arr[i] + total;
    	//cout<<"At day "<<days<<" people : "<<total<<endl;
    	
    	if(total>=n)
    	{
    		//days++;
    		break;
		}
		//days++;
		
		i = total-1;
	}
    
    
    cout<<days<<endl;
}

int main()
{
	int t;
	cin>>t;
	while(t)
	{
	t--;
	func();
	}
	return 0;
}


