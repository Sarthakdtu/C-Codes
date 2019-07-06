/*

#include<iostream>
#include<vector>
#include<map>
using namespace std;

/*
5
fdjkd
dfjdk
dfd
fdjkd
kkjjk
/

float time(vector<string> v, int n)
{
	int curr_hand = 0;
	//int next_hand = 0;
	map<string, float> m;
	float total_time =0;
	float time =0;
	for(int i=0;i<n;i++)
	{
	 //curr_hand =0;
	 string s = v[i];
	 if(m.find(s)==m.end()){
	 	time =0;
	 	curr_hand=0;
	 	cout<<"\nFor "<<s<<" "<<endl;
		for(int j=0;j<v[i].size();j++)
		{
			cout<<"\nHand is at "<<curr_hand<<" for "<<s[j]<<endl;
			if(s[j]=='d'||s[j]=='f')
			{				
				if(curr_hand==1||curr_hand==0){
				     time +=0.2;
				     cout<<"Took 0.2s "<<endl;
			    }
				else{
					time+=0.4;
					cout<<"Took 0.4s "<<endl;
				} 
				curr_hand=-1;   
				cout<<"Now hand is at "<<curr_hand<<endl;	   
			}
			else if(s[j]=='j'||s[j]=='k')
			{
				if(curr_hand==-1||curr_hand==0){
				     time +=0.2;
				     cout<<"Took 0.2s "<<endl;
				    
			    }
				else{
				//	cout<<curr_hand<<" for "<<s[j]<<endl;
					time+=0.4;
					cout<<"Took 0.4s "<<endl;
				}   		
				 curr_hand=1;
				 cout<<"Now hand is at "<<curr_hand<<endl;		   
			}
			cout<<"Time taken = "<<time<<endl;
	    }
	    m[s]=time;
	    total_time +=time; 
	  }
	  else
	  {
	  	cout<<s<<" was previously encountered with time = "<<m[s]<<". New time is ";
	  	total_time += m[s]/2;
	  	cout<<m[s]/2<<endl;
	  }
	  cout<<"TT "<<total_time<<endl;
    } 
	return total_time;	
}


void func()
{
  int n;
  cin>>n;
  vector<string> v;
  for(int i=0;i<n;i++)
  {
  	string s;
  	cin>>s;
  	v.push_back(s);
  }
  
  float ans = time(v, n);

  cout<<ans*10.0;	
}

int main()
{
	func();
	return 0;
}





*/

#include<iostream>
#include<vector>
#include<map>
using namespace std;

float time(vector<string> v, int n)
{
	int curr_hand = 0;
	int next_hand = 0;
	map<string, float> m;
	float total_time =0;
	float time =0;
	for(int i=0;i<n;i++)
	{
	 //curr_hand =0;
	 string s = v[i];
	 if(m.find(s)==m.end()){
	 	time =0;
	 	curr_hand=0;
	 	//cout<<"\nFor "<<s<<" "<<endl;
		for(int j=0;j<v[i].size();j++)
		{
		//	cout<<"\nHand is at "<<curr_hand<<" for "<<s[j]<<endl;
			if(s[j]=='d'||s[j]=='f')
			{				
				if(curr_hand==1||curr_hand==0){
				     time +=0.2;
		//		     cout<<"Took 0.2s "<<endl;
			    }
				else{
					time+=0.4;
		//			cout<<"Took 0.4s "<<endl;
				} 
				curr_hand=-1;   
		//		cout<<"Now hand is at "<<curr_hand<<endl;	   
			}
			else if(s[j]=='j'||s[j]=='k')
			{
				if(curr_hand==-1||curr_hand==0){
				     time +=0.2;
		//		     cout<<"Took 0.2s "<<endl;
				    
			    }
				else{
				//	cout<<curr_hand<<" for "<<s[j]<<endl;
					time+=0.4;
		//			cout<<"Took 0.4s "<<endl;
				}   		
				 curr_hand=1;
		//		 cout<<"Now hand is at "<<curr_hand<<endl;		   
			}
		//	cout<<"Time taken = "<<time<<endl;
	    }
	    m[s]=time;
	    total_time +=time; 
	  }
	  else
	  {
	  	//cout<<s<<" was previously encountered with time = "<<m[s]<<". New time is ";
	  	total_time += m[s]/2;
	  	//cout<<m[s]/2<<endl;
	  }
	  //cout<<"TT "<<total_time<<endl;
    } 
	return total_time;	
}


void func()
{
  int n;
  cin>>n;
  vector<string> v;
  for(int i=0;i<n;i++)
  {
  	string s;
  	cin>>s;
  	v.push_back(s);
  }
  
  float ans = time(v, n);

  cout<<ans*10.0<<endl;	
}

int main()
{
int t;
cin>>t;
while(t){
t--;
	func();}
	
	return 0;
}




