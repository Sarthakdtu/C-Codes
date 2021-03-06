/*
Monk being the monitor of the class needs to have all the information about the class students. He is very busy with many tasks related to the same, so he asked his friend Mishki for her help in one task. She will be given heights of all the students present in the class and she needs to choose 2 students having heights  and  respectively, such that  and difference between the number of students having height  and number of students having height  is maximum.

Note: The difference should be greater than 0.

As Mishki has never been a monitor of the class, help her in the same. If there exists such students, then print the required difference else print "1" (without quotes).

Input:
The first line will consists of one integer T, which denotes the number of test cases. 
For each test case:
One line consists of a integer N, denotes the number of students in the class.
Second line contains N space separated integers, where  integer denotes the height of the  student in the class.
Output:

For each test case, if the required difference exists then print its value, otherwise print 1. Print the answer for each test case in a new line.
Constraints:
t<=10
height<10^6
n<10^5


SAMPLE INPUT 
1
6
3 1 3 2 3 2
SAMPLE OUTPUT 
2
Explanation
Here T=1 and N = 6.

Number of students having height = 3 is 3. 
Number of students having height = 2 is 2.
Number of students having height = 1 is 1.

Here Mishki can choose students with height=3 () and height = 1 () , as the difference between number of students having height () and number of students having height () is maximum and greater than 0.
*/


#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t)
    {
    	map<int, int> height;
        t--;
        int n;
    cin>>n;
    //int total_degree = 0;
    int min = INT_MAX;
    int max = 0;
    for(int i=0;i<n;i++)
    {
        int h;
        cin>>h;
        if(height.find(h)==height.end())
        {
    		height[h]=1;
        }
        else
        {
			height[h]++;
        }
    }
    //sort(height.begin(), height.end(), comp);
    int maxH = 0;
    int maxCount=0;
    int minCount = INT_MAX;
    int minH=INT_MAX;
    map<int, int> ::iterator it;
    for(it=height.begin();it!=height.end();it++)
    {
    	int h = it->first;
    	int count = it->second;
    	cout<<"Height : "<<h<<" Count : "<<count<<endl;
    	if(maxCount<count)
    	{
    		maxH = h;
    		maxCount = count;
		}
		
		if(minCount>count)
		{
			minCount = count;
			minH = h;
		}
	}
	if(minH-maxH==0)
	{
		cout<<"1";
	}
	else
	{
		cout<<abs(minH-maxH);
	}
	cout<<endl;

    }
    
    return 0;
}
