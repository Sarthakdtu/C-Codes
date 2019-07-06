#include<iostream>
using namespace std;
int subsetSumToK(int input[], int n, int output[][50], int k) {
    // Write your code here
  
  if(n==0)
  {
    output[0][0]=0;
    if(k==0)
      return 1;
    return 0;
  }
  
  
  int o1[50][50];
  int o2[50][50];
  
  int so1 = subsetSumToK(input+1, n-1, o1, k-input[0]);
  int so2 = subsetSumToK(input+1, n-1, o2, k);
  
  cout<<"K is "<<k<<endl;
  cout<<"so1, so2 "<<so1<<" , "<<so2<<endl;
  
  for(int i=0;i<so1;i++)
  {
  	output[i][0] = o1[i][0]+1;
  	output[i][1] = input[0];
    for(int j=2;j<o1[i][0]+2;j++)
    {
    	output[i][j] = o1[i][j-1];
	}
  }
  
  for(int i=0;i<so2;i++)
  {
  	output[so1+i][0] = o2[i][0];
    for(int j=1;j<o2[i][0]+1;j++)
    {
    	output[i+so1][j] = o2[i][j];
	}
  }
  
  return so1+so2; 
}

int main()
{
	
	int arr[]={1,2,3, 4, 5};
	int output[100][50];
	int size = subsetSumToK(arr, 5, output, 6);
	cout<<"\nSubsets are \n";
	//cout<<size;
	for(int i=0;i<size;i++)
	{
		cout<<"\n Size = ";
		cout<<output[i][0]<<endl;
	//	cout<<"AAAAA";
		for(int j=1;j<output[i][0]+1;j++){
		  cout<<output[i][j]<<" ";
		//  cout<<"Wai AA UU Ranin?";
	}
		cout<<endl;
	}
	return 0;
}
