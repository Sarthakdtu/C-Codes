#include<iostream>
#include<fstream>
#include<string>
using namespace std;

string Close = "exit";
string Read ="open";
string Write= "write";
string Create="new";

void displayBorders()
{
	cout<<"\n";
	for(int i=0;i<117;i++)
	cout<<".";
}

void readFile(string file)
{
	fstream fin;
	file = file + ".txt";
	fin.open(file, ios::in);
	if(!fin)
	{
		cout<<"file not found";
		return;
	}
	displayBorders();
    cout<<"\t\t\t\t\t\t"<<file;
	displayBorders();    
	while(!fin.eof()){
		string line;
		getline(fin, line, '\n');
		cout<<line<<endl;
	}
	//cout<<"here";
	displayBorders();
	fin.close();
}

void writeFile(string file)
{
	displayBorders();
    cout<<"\t\t\t\t\t\t"<<file;
	displayBorders();
	fstream fout;
	file = file + ".txt";
	fout.open(file, ios::app);
	
	if(!fout)
		cout<<"file not found";

	while(fout)
	{
		string line;
		getline(cin, line,'\n');
		if(line=="/close")
		  break;  
		fout<<line<<'\n';  
	}
	//cout<<"here";
    displayBorders();

	fout.close();
}

void fileSystem()
{
	while(true)
	{
		string cmd;
		cin>>cmd;
		
		if(cmd == Close)
		  break;  
		   
		string file_name;
		cin>>file_name;
		cout<<endl;    
		if(cmd == Read)  
		   readFile(file_name);
		else if(cmd == Write||cmd == Create)  
		   writeFile(file_name);  
		else
		   {
		   	//cout<<"\nIllegal Command\n"; 
		   	//cout<<"Type 'help' to know more about commands.";
		   }  
		   
		cout<<endl;   
	}
}

int main(){
	fileSystem();
	return 0;
}
