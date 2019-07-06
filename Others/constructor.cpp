#include<iostream>
#include<string>
#include<vector>


using namespace std;

class Human
{
	private:
		int head;
		int nose;
		int eyes;
		char gender;
		static int no;
	public:
		
	Human();
	Human(char c);
	void displayH()	;
	void displayS();
};
int Human::no=0;
Human::Human()
{
	cout<<"\n Default Constructor";
	gender='m';
	no++;
	eyes = 2;
	nose = head = 1;
}

Human::Human(char c)
{
	cout<<"\n Parameterized Constructor";
	gender=c;
	eyes = 2;
	nose = head = 1;
}

void Human::displayS()
{
	cout<<" no "<<Human::no;
	cout<<"\n";
	
}

void Human::displayH()
{
	cout<<" eyes "<<eyes;
	cout<<"\n";
	cout<<" gen "<<gender;
	cout<<"\n";
	cout<<" head "<<head;
	cout<<"\n";
	cout<<" nose "<<nose;
	cout<<"\n";
}




class Student :public Human
{
	private:
		int age;
		string name;
		vector<string> subjects;    
		int standard;
		
		
		
	public:
		Student()
		{
		//	Human('l');
			set_age(0);
			set_name("");
			set_std(0);
		}
		friend void display(Student s);
		Student(int a)
		{
			Human('e');
			cout<<"\nIn constructor\n";
			
			set_age(a);
			set_name("Go");
			set_std(0);
		}
		void set_age(int a);
		void set_name(string n);
		void set_std(int s);
		
		int get_age();
		string get_name();
		int get_std();
	
};


void display(Student s)
{
	s.displayH();
	cout<<" Age "<<s.age;
	cout<<"\n";
	cout<<" Std "<<s.standard;
	cout<<"\n";
	cout<<" Name "<<s.name;
	cout<<"\n";

}

void Student::set_age(int a)
{
  age = a;	
}

void Student::set_name(string n)
{
	name = n;
}

void Student::set_std(int s)
{
	standard = s;
}

int Student::get_age()
{
	return age;
}

string Student::get_name()
{
	return name;
}

int Student::get_std()
{
	return standard;
}


int main()
{
	//Student s(9);
 	Human j;
 	Human r;
 	Human e;
 	Human j1;
 	Human j2;
 	j2.displayS();
    //display(s);
	return 0;
}









