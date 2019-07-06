#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
using namespace std;

class MyQueue {
  
    public:
        stack<int> s1, s2;   
        void push(int x) {
           this->s1.push(x);
            
        }

        void pop() {
            if(!this->s2.empty())
            {
                this->s2.pop();
                return ;
            }
            int t = s1.top();
            s1.pop();
            while(!s1.empty())
            {
                this->s2.push(this->s1.top());
                this->s1.pop();
            }
            if(!this->s2.empty())
            {
             this->s2.pop();
             s1.push(t);
             return ;
            }
            
            
        }

        int front() {
            if(!this->s2.empty())
            {
                return this->s2.top();
            }
            int t = s1.top();
            s1.pop();
            while(!s1.empty())
            {
                this->s2.push(this->s1.top());
                this->s1.pop();
            }
            if(!this->s2.empty())
            {
             s1.push(t);
             t= this->s2.top() ;
             return t;
            }
              return -1;
        }
  
  void displayS1()
  {
  	if(s1.empty())
  	{
  		return ;
	  }
	  int t = s1.top();
	  cout<<s1.top()<<"->";
	  s1.pop();
	  displayS1();
	  s1.push(t);
  }
  
  void displayS2()
  {
  	if(s2.empty())
  	{
  		return ;
	  }
	  int t = s2.top();
	  cout<<s2.top()<<"->";
	  s2.pop();
	  displayS2();
	  s2.push(t);
  }
};

int main() {
    MyQueue q1;
    int q, type, x;
    cin >> q;
    
    for(int i = 0; i < q; i++) {
    	cout<<"\nS1 ";
		q1.displayS1();
		cout<<"\nS2 ";
    	q1.displayS2();
    	cout<<"\n";
        cin >> type;
        if(type == 1) {
            cin >> x;
            q1.push(x);
        }
        else if(type == 2) {
            q1.pop();
        }
        else cout << q1.front() << endl;
        cout<<"\n";
    }
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}
