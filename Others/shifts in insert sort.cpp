#include<iostream>
#include<vector>
using namespace std;

int insertSort(vector<int> arr) {
    int s=0;
    for(int i=1;i<arr.size();i++)
    {
        int j = i-1;
        int key = arr[i];
        while(j>=0 && arr[j]>key)
        {
            arr[j+1] = arr[j];
            
            j--;
            s++;
        }
        j++;
        
        arr[j] = key;
    }
    return s;
}


int main()
{
	
	vector<int> v={4, 3, 2, 1};
	cout<<insertSort(v);
	return 0;
}
