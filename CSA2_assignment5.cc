//Student Recorder!
//The purpose of this program is to record the name, id and registered classes of the students.
//Written by James Gouveia 7/27/16
#include <iostream>
#include <cctype>
using namespace std;

class Student
{
	private:
		string name;
		int student_id;
		string classes_registered[10];
	public:
		Student(int);
		Student(string name, int student_id, string c);

		void setStudentName();
		void setStudentId();
		void setClassesRegistered();
		void getStudentName();
		void getStudent_id();
		void getClasses_registered();		
};

void show_intro();

void show_intro()
{
	cout << "\nStudent Record Program\n"
	     << "========================\n"
	     << "This program will record the name, student ID and Classes registered data for each student.\n";
}

//Constuctor 1
Student::Student(int s_id)
{
	student_id = s_id;
}

//Constructor 2
Student::Student(string s_name = "James", int s_id = 123, string c = "CS2A")
{
	name = s_name;
	student_id = s_id;
	classes_registered[0] = c;
}

void Student::setStudentName()
{
	cout << "\nPlease enter the name of the student.\n";
	getline(cin, name);
}

void Student::setStudentId()
{
	cout << "\nPlease enter the student's id number.\n";
	cin.clear();
	cin >> student_id;
}

void Student::setClassesRegistered()
{
	int n = 0;
	char flag = 'Y';
	do
	{
		cout << "\nPlease enter the student's class number.\n";
		cin.clear();
		cin.ignore();
		getline(cin, classes_registered[n]);
		cout << "\nWould you like to enter another class number for this student? Y for yes, N for no\n";
		cin >> flag;
		flag = toupper(flag);
		if(!(flag == 'Y'))
		{
			break;
		}
		n = n + 1;
	}while(flag == 'Y');
}

void Student::getStudentName()
{
	cout << "The student's name is: " << (*this).name << endl;
}

void Student::getStudent_id()
{
	cout << name << "'s" << " id is: " << student_id << endl;
}

void Student::getClasses_registered()
{
	string y = classes_registered[0];
	int i = 0;
	while(classes_registered[i] != "" && i < 11)
	{
		cout << name << "'s " << "registered classes is/are: " << classes_registered[i] << endl << endl;
		i = i + 1;
	}
}

int main()
{
	show_intro();

	Student number1("Barry", 321, "CS2A"), number2(5);

	number1.getStudentName();

	number1.getStudent_id();

	number1.getClasses_registered();

	number2.setStudentName();

	number2.setStudentId();

	number2.setClassesRegistered();

	number2.getStudentName();

	number2.getStudent_id();

	number2.getClasses_registered();
	
}

/*
output

Student Record Program
========================
This program will record the name, student ID and Classes registered data for each student.
The student's name is: Barry
Barry's id is: 321
Barry's registered classes is/are: CS2A


Please enter the name of the student.
James

Please enter the student's id number.
2

Please enter the student's class number.
CSA1

Would you like to enter another class number for this student? Y for yes, N for no
y

Please enter the student's class number.
CSA2

Would you like to enter another class number for this student? Y for yes, N for no
n
The student's name is: James
James's id is: 2
James's registered classes is/are: CSA1

James's registered classes is/are: CSA2

james@james-K55N:~/Desktop$ 

*/
