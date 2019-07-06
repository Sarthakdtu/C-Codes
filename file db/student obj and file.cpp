#include<iostream>
#include<fstream>
#include<string>
using namespace std;

class student{
	string name;
	int rollno;
	string mobile;
    public:
    	student();
    	void getStudent();
    	void putStudent();
    	string getName();
    	int getRoll();
    	string getMobile();
    	void putName();
    	void putMobile();
    	void putRoll();
    	void displayStudent();
};

student::student()
{
	name="NA";
	rollno=-1;
	mobile="NA";
}
void student::putMobile(){
	string no;
	cout<<"Enter Number : ";
	cin>>no;
	mobile=no;
	cout<<endl;
}
void student::putName(){
	string no;
	cout<<"Enter Name : ";
	cin>>no;
	name=no;
	cout<<endl;
}
void student::putRoll(){
	int no;
	cout<<"Enter Roll No : ";
	cin>>no;
	rollno=no;
	cout<<endl;
}

string student::getName(){
	return name;
}
int student::getRoll(){
	return rollno;
}
string student::getMobile(){
	return mobile;
}
void student::getStudent(){
	return ;
}
void student::putStudent(){
	 putName();
	 putRoll();
	 putMobile();
}
void student::displayStudent()
{
	cout<<name<<" "<<rollno<<" "<<mobile<<endl;
}

void Object()
{
	int n=2;
	student btech[n];
	fstream file;
	file.open("btech students.txt", ios::in|ios::app);
	for(int i=0;i<n;i++)
	{
		btech[i].putStudent();
		btech[i].displayStudent();
		file.write((char*)&btech[i], sizeof(btech[i]));
	}
	student read_obj;
	cout<<"\nStudents are\n";
	for(int i=0;i<n;i++)
	{
		file.read((char*)&read_obj, sizeof(read_obj));
		read_obj.displayStudent();
	}
	
	file.close();
}

int main()
{
	Object();
	return 0;
}




