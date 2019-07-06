#include<iostream>
#include<vector>
using namespace std;

void display(vector<int> v)
{
	cout<<"\n";
	vector<int> ::iterator itr;
	
	for(itr= v.begin();itr!= v.end();itr++)
	{
		cout<<*itr<<" ";
	}
	cout<<"\n";
}

void rotateArray(vector<int> &A, int B)
 {
    //vector<int> ret; 
    int k;
    int j= 0;
    int pre=0;
    int n = A.size();
    for (int i = 0; i < A.size(); i++) {
     k=0;
     j=i; 
     pre = i;
     while(j<n && k <B )
     {
         k++;
         j++;
     }
    // if(j==n)
        j--;
     //j is index of last elt
     int cou= 0;
     cout<<"Reversing from: "<<A[j]<<" to "<<A[pre]<<"\n"; 
     int lim = (j-pre+1)/2;
     while(cou<lim)
     {
         cou++;
         display(A);
         int temp = A[pre];
         A[pre] = A[j];
         A[j] =temp;
         pre++;
         j--;
     }
     display(A);
     if(j==n-1)
     break;
       //pre = i;
    }
       
       
       
    //return A; 
}

int main()
{
	vector<int> v={1,2,3,4,5,6,7,8,9};
	rotateArray(v, 4);
	
	display(v);
	return 0;
}
