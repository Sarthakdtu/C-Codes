#include<iostream>
#include<fstream>
using namespace std;

int main(){
	
	fstream file;
	file.open("fileone.txt", ios::app);
	while(true)
	{
		string line;
		cin>>line;
		if(line=="/close")
		   break;
		file<<line;
		file<<"\n";   
	}
	
	file.close();
	string f ="fileone.txt";
	file.open(f, ios::in);
	
	while(!file.eof()){
		string line;
		file>>line;
		cout<<line;
	}
	file.close();
	return 0;
}
