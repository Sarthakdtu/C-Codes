#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

bool checkOneAway(string s1,string s2)
{
	int l1 = s1.length();
	int l2 = s2.length();
	int diff = l1-l2;
	if(diff!=0&&diff!=-1&&diff!=1)
	{
		cout<<"Due to this";
		return false;
	}
	int i=0;
	int j=0;
	int equal = 1;
	while(i!=s1.length()&&j!=s2.length())
	{
	 	if(s1[i]!=s2[j]){
	 		if(equal == 1){
	 			equal =0;
	 			if(diff==0){
	 				i++;
	 				j++;
				 }
				 else if(diff ==-1){
				 	j++;
				 }
				 else{
				 	i++;
				 }
			 }
			 else{
			 	return false;
			 }
		 }
		 else{
		 	i++;
		 	j++;
		 }
	}

	return true;
}

int main()
{
	string s1 = "pale";
	string s2 = "bal";
	cout<<checkOneAway(s1, s2);
	return 0;
}

