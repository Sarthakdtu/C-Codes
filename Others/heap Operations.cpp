#include<iostream>
#include<vector>

using namespace std;

void display(vector<int> &v)
{
	for(int i=0;i<v.size();i++)
	{
		cout<<v[i]<<" ";
	}
	cout<<endl;
}
void swap(vector<int> &v, int i, int j)
{
	int temp = v[i];
	v[i] = v[j];
	v[j] = temp;
}

void maxHeapify(vector<int> &v, int i, int hS)
{
	int l = 2*i+1;
	int r = 2*i+2;
	int largest = i;
	
	if(l<hS && v[l]>v[i])
	   largest = l;
	
	if(r<hS && v[largest]<v[r])
	   largest = r;
	
	if(largest!=i)
	{
      swap(v, i, largest);
	  maxHeapify(v, largest, hS);		
    }      
	   
}

void buildMaxHeap(vector<int> &v)
{
	int heapSize = v.size();
	for(int i=heapSize/2;i>=0;i--)
	{
		maxHeapify(v, i, heapSize);
	}
}

void heapSort(vector<int> &v)
{
	buildMaxHeap(v);
	//cout<<"After ";
	//display(v);
	int heapSize=v.size();
	for(int i=v.size()-1;i>0;i--)
	{
		swap(v, i, 0);
		heapSize--;
		maxHeapify(v, 0, heapSize);
		//cout<<"Iteration "<<i<<endl;
		//display(v);
	}
}

void heap(vector<int> &v)
{
	display(v);
	heapSort(v);
	display(v);
	v.push_back(0);
	display(v);
 	display(v);
}



int main()
{
	vector<int> v;
	v.push_back(10);
	v.push_back(1);
	v.push_back(8);
	v.push_back(3);
	v.push_back(6);
	v.push_back(2);
	v.push_back(4);
	v.push_back(7);
	v.push_back(5);
	v.push_back(9);
	
	heap(v);
	//cout<<v[0];	
	return 0;
}
