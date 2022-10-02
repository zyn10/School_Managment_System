#include "brah.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// 19F-0316 M Talha Zafar

template<class variable>
variable* resize(variable* arr, int& size)
{
	size++;
	variable* temp = new variable[size];
	for (int i = 0; i < size - 1; i++)
		temp[i] = arr[i];
	delete[] arr;
	return temp;
}

Person::Person()
{
	firstName = " ";
	lastName = " ";
	gender = " ";
	address = " ";
	password = " ";
	confirmPassword = " ";
	contactNo = " ";

}

// *************************** T E A C H E R ***************************

Teacher::Teacher()
{
	email = " ";
	dateOfBirth.day = 0;
	dateOfBirth.month = 0;
	dateOfBirth.year = 0;
	joiningDate.day = 0;
	joiningDate.month = 0;
	joiningDate.year = 0;
	CNIC = " ";
	qualification = " ";
	salary = 0;
	teachersCourses = NULL;
}

void Teacher::takeInput()
{
	int option;

	cout << "\n First name: ";
	cin >>  firstName;
	cout << "\n Last name: ";
	cin >> lastName;
	cin.ignore();
	cout << "\n Email: ";
	getline(cin, email);

	cout << "\n For the date of birth enter:"
		<< "\n\n\t Day: ";
	while (!(cin >> joiningDate.day) || joiningDate.day < 1 || joiningDate.day > 31)
	{
		cout << "\n Invalid input. Please try again: ";
		cin.clear();
		cin.ignore(123, '\n');
	}
	cout << "\n\t Month: ";
	while (!(cin >> joiningDate.month) || joiningDate.month < 1 || joiningDate.month > 12)
	{
		cout << "\n Invalid input. Please try again: ";
		cin.clear();
		cin.ignore(123, '\n');
	}
	cout << "\n\t Year: ";
	while (!(cin >> joiningDate.year) || joiningDate.year < 1 || joiningDate.year > 2020)
	{
		cout << "\n Invalid input. Please try again: ";
		cin.clear();
		cin.ignore(123, '\n');
	}

	cout << "\n Gender: "
		<< "\n\n\t 1 - Male"
		<< "\n\n\t 2 - Female"
		<< "\n\n\t 3 - Unspecified"
		<< "\n Enter: ";
	while (!(cin >> option) || option < 1 || option > 3)
	{
		cout << "\n Invalid input. Please try again: ";
		cin.clear();
		cin.ignore(123, '\n');
	}
	cin.ignore();

	while (option < 1 || option > 3)
	{
		cout << "\n Invalid input. Please try again: ";
		cin >> option;
		cin.ignore();
	}

	switch (option)
	{
	case 1:
		gender = "Male";
		break;
	case 2:
		gender = "Female";
		break;
	case 3:
		gender = "Unspecified";
		break;
	}

	cout << "\n Qualification: ";
	getline(cin, qualification);

	cout << "\n For the date of birth enter:"
		<< "\n\n\t Day: ";
	while (!(cin >> dateOfBirth.day) || dateOfBirth.day < 1 || dateOfBirth.day > 31)
	{
		cout << "\n Invalid input. Please try again: ";
		cin.clear();
		cin.ignore(123, '\n');
	}
	cout << "\n\t Month: ";
	while (!(cin >> dateOfBirth.month) || dateOfBirth.month < 1 || dateOfBirth.month > 12)
	{
		cout << "\n Invalid input. Please try again: ";
		cin.clear();
		cin.ignore(123, '\n');
	}
	cout << "\n\t Year: ";
	while (!(cin >> dateOfBirth.year) || dateOfBirth.year < 1 || dateOfBirth.year > 2020)
	{
		cout << "\n Invalid input. Please try again: ";
		cin.clear();
		cin.ignore(123, '\n');
	}

	cin.ignore();

	cout << "\n Address: ";
	getline(cin, address);
	
	cout << "\n Salary: ";
	while (!(cin >> salary) || salary < 0)
	{
		cout << "\n Invalid input. Please try again: ";
		cin.clear();
		cin.ignore(123, '\n');
	}

	cin.ignore();
	cout << "\n CNIC: ";
	getline(cin, CNIC);
	
	cout << "\n Contact Number: ";
	getline(cin, contactNo);

	cout << "\n Set a login username for this teacher: ";
	getline(cin, username);
	cout << "\n Set a login password for this teacher: ";
	getline(cin, password);
	cout << "\n Confirm password: ";
	getline(cin, confirmPassword);

	while (password != confirmPassword)
	{
		cout << "\n The passwords do not match! Try again: ";
		getline(cin, confirmPassword);
	}

	write();
}

void Teacher::write()
{
	ofstream fout("Teachers.txt", ios::app);

	fout << endl << firstName << " " << lastName << endl;
	fout << email << endl;
	fout << joiningDate.day << "/" << joiningDate.month << "/" << joiningDate.year << endl;
	fout << CNIC << endl;
	fout << gender << endl;
	fout << qualification << endl;
	fout << contactNo << endl;
	fout << dateOfBirth.day << "/" << dateOfBirth.month << "/" << dateOfBirth.year << endl;
	fout << address << endl;
	fout << salary << endl;
	fout << username << endl;
	fout << password << endl;
	if (courseCount == 0)
		fout << courseCount;
	else
		fout << courseCount << endl;
	for (int i = 0; i < courseCount; i++)
	{
		fout << teachersCourses[i];
		if (i != courseCount - 1)
			cout << endl;
	}

	fout.close();
}

void Teacher::write(ofstream& fout)
{
	fout << endl << firstName << " " << lastName << endl;
	fout << email << endl;
	fout << joiningDate.day << "/" << joiningDate.month << "/" << joiningDate.year << endl;
	fout << CNIC << endl;
	fout << gender << endl;
	fout << qualification << endl;
	fout << contactNo << endl;
	fout << dateOfBirth.day << "/" << dateOfBirth.month << "/" << dateOfBirth.year << endl;
	fout << address << endl;
	fout << salary << endl;
	fout << username << endl;
	fout << password << endl;
	if(courseCount == 0)
		fout << courseCount;
	else
		fout << courseCount << endl;
	for (int i = 0; i < courseCount; i++)
	{
		fout << teachersCourses[i];
		if (i != courseCount - 1)
			cout << endl;
	}
}

void Teacher::edit()
{
	cout << "\n New address: ";
	getline(cin, address);
	cout << "\n New contact number: ";
	getline(cin, contactNo);
	cout << "\n New qualification: ";
	getline(cin, qualification);
	cout << "\n New salary: ";
	cin >> salary;
}

void Teacher::assignCourse(string course)
{
	teachersCourses = resize(teachersCourses, courseCount);
	teachersCourses[courseCount - 1] = course;
}

void Teacher::read(ifstream& obj)
{
	string temp;
	obj >> firstName;
	if(firstName == "")
		obj >> firstName;
	obj >> lastName;
	obj.ignore(123, '\n');
	obj >> email;
	getline(obj, temp, '/');
	joiningDate.day = stoi(temp);
	getline(obj, temp, '/');
	joiningDate.month = stoi(temp);
	getline(obj, temp, '\n');
	joiningDate.year = stoi(temp);
	getline(obj, CNIC);
	getline(obj, gender);
	getline(obj, qualification);
	getline(obj, contactNo);
	getline(obj, temp, '/');
	dateOfBirth.day = stoi(temp);
	getline(obj, temp, '/');
	dateOfBirth.month = stoi(temp);
	getline(obj, temp, '\n');
	dateOfBirth.year = stoi(temp);
	getline(obj, address);
	obj >> salary;
	obj.ignore(123, '\n');
	getline(obj, username);
	getline(obj, password);
	obj >> courseCount;
	obj.ignore(123, '\n');
	teachersCourses = new string[courseCount];
	for (int i = 0; i < courseCount; i++)
		getline(obj, teachersCourses[i]);
}

void Teacher::display()
{
	cout << "\n Name: " << firstName << " " << lastName << endl;
	cout << "\n Email: " << email << endl;
	cout << "\n Gender: " << gender << endl;
	cout << "\n Qualification: " << qualification << endl;
	cout << "\n Contact Number: " << contactNo << endl;
}

string Teacher::getName()
{
	return firstName + lastName;
}

string Teacher::getUserName()
{
	return username;
}

string* Teacher::getCourses()
{
	return teachersCourses;
}

int Teacher::getCourseCount()
{
	return courseCount;
}

string Teacher::getPass()
{
	return password;
}

// *************************** S T U D E N T ***************************

Student::Student()
{
	klass = 0;
	rollNo = " ";
	dateOfRegistration.day = 0;
	dateOfRegistration.month = 0;
	dateOfRegistration.year = 0;
	fatherName = " ";
	fatherProfession = " ";
	fathersContactNo = " ";
	feeSubmitted = false;
	bloodType = " ";
	RhFactor = false;
	studentsCourses = NULL;
	marksObtained = NULL;
	marksTotal = NULL;
}

void Student::takeInput()
{
	studentCount++;
	int input = 0;
	cout << "\n First name: ";
	cin >> firstName;
	cout << "\n Last name: ";
	cin >> lastName;
	cout << "\n Class(1 to 10 inclusive): ";
	
	while (!(cin >> klass) || klass > 10 || klass < 0)
	{
		cout << "\n Invalid input. Please try again: ";
		cin.clear();
		cin.ignore(123, '\n');
	}
	cin.ignore();
	rollNo = to_string(klass) + to_string(studentCount);

	if (klass != 10)
		rollNo = '0' + rollNo;

	cout << "\n For the date of birth enter:"
		<< "\n\n\t Day: ";
	while (!(cin >> dateOfRegistration.day) || dateOfRegistration.day < 1 || dateOfRegistration.day > 31)
	{
		cout << "\n Invalid input. Please try again: ";
		cin.clear();
		cin.ignore(123, '\n');
	}
	cout << "\n\t Month: ";
	while (!(cin >> dateOfRegistration.month) || dateOfRegistration.month < 1 || dateOfRegistration.month > 12)
	{
		cout << "\n Invalid input. Please try again: ";
		cin.clear();
		cin.ignore(123, '\n');
	}
	cout << "\n\t Year: ";
	while (!(cin >> dateOfRegistration.year) || dateOfRegistration.year < 1 || dateOfRegistration.year > 2020)
	{
		cout << "\n Invalid input. Please try again: ";
		cin.clear();
		cin.ignore(123, '\n');
	}

	cout << "\n Gender: "
		<< "\n\n\t 1 - Male"
		<< "\n\n\t 2 - Female"
		<< "\n\n\t 3 - Unspecified"
		<< "\n\n Enter: ";

	while (!(cin >> input) || input < 1 || input > 3)
	{
		cout << "\n Invalid input. Please try again: ";
		cin.clear();
		cin.ignore(123, '\n');
	}
	cin.ignore();
	switch (input)
	{
	case 1:
		gender = "Male";
		break;
	case 2:
		gender = "Female";
		break;
	case 3:
		gender = "Unspecified";
		break;
	}

	cout << "\n Contact Number: ";
	getline(cin, contactNo);

	cout << "\n Father's full name: ";
	getline(cin, fatherName);

	cout << "\n Fathers Profession: ";
	getline(cin, fatherProfession);

	cout << "\n Fathers Contact Number: ";
	getline(cin, fathersContactNo);

	cout << "\n Is the fee submitted for this student?"
		<< "\n\n\t 1 - Yes"
		<< "\n\n\t 2 - No"
		<< "\n\n Enter: ";

	while (!(cin >> input) || input < 1 || input > 2)
	{
		cout << "\n Invalid input. Please try again: ";
		cin.clear();
		cin.ignore(123, '\n');
	}
	cin.ignore();
	if (input == 1)
		feeSubmitted = true;

	cout << "\n Choose a blood type:"
		<< "\n\n\t 1 - A"
		<< "\n\n\t 2 - B"
		<< "\n\n\t 3 - O"
		<< "\n\n\t 4 - AB"
		<< "\n\n Enter: ";

	while (!(cin >> input) || input < 1 || input > 4)
	{
		cout << "\n Invalid input. Please try again: ";
		cin.clear();
		cin.ignore(123, '\n');
	}
	switch (input)
	{
	case 1:
		bloodType = "A";
		break;
	case 2:
		bloodType = "B";
		break;
	case 3:
		bloodType = "O";
		break;
	case 4:
		bloodType = "AB";
		break;
	default:
		cout << "\a\n Enter a valid option." << endl;
		break;
	}
	cout << "\n\t Rh Factor:"
		<< "\n\n\t\t 1 - Positive"
		<< "\n\n\t\t 2 - Negative"
		<< "\n\n\t Enter: ";

	while (!(cin >> input) || input < 1 || input > 2)
	{
		cout << "\n Invalid input. Please try again: ";
		cin.clear();
		cin.ignore(123, '\n');
	}

	if (input == 1)
		RhFactor = true;

	cin.ignore();
	cout << "\n Address: ";
	getline(cin, address);

	cout << "\n Set a login password for this student: ";
	getline(cin, password);
	cout << "\n Confirm password: ";
	getline(cin, confirmPassword);

	while (password != confirmPassword)
	{
		cout << "\n The passwords do not match! Try again: ";
		getline(cin, confirmPassword);
	}

	write();
}


void Student::write()
{
	ofstream fout("Students.txt", ios::app);
	
	fout << endl << firstName << " " << lastName << endl;
	fout << rollNo << endl;
	fout << klass << endl;
	fout << dateOfRegistration.day << "/" << dateOfRegistration.month << "/" << dateOfRegistration.year << endl;
	fout << gender << endl;
	fout << contactNo << endl;
	fout << fatherName << endl;
	fout << fatherProfession << endl;
	fout << fathersContactNo << endl;

	fout << feeSubmitted << endl;

	fout << bloodType;

	if (RhFactor)
		fout << "+" << endl;
	else
		fout << "-" << endl;
	fout << address << endl;

	fout << password << endl;

	if (courseCount == 0)
		fout << courseCount;
	else
		fout << courseCount << endl;
	for (int i = 0; i < courseCount; i++)
	{
		fout << studentsCourses[i] << endl;
		fout << marksTotal[i] << endl;
		fout << marksObtained[i];
		if(i != courseCount - 1)
			fout  << endl;
	}

	fout.close();
}

void Student::write(ofstream& fout)
{	
	fout << endl << firstName << " " << lastName << endl;
	fout << rollNo << endl;
	fout << klass << endl;
	fout << dateOfRegistration.day << "/" << dateOfRegistration.month << "/" << dateOfRegistration.year << endl;
	fout << gender << endl;
	fout << contactNo << endl;
	fout << fatherName << endl;
	fout << fatherProfession << endl;
	fout << fathersContactNo << endl;

	fout << feeSubmitted << endl;

	fout << bloodType;

	if (RhFactor)
		fout << "+" << endl;
	else
		fout << "-" << endl;
	fout << address << endl;

	fout << password << endl;

	if(courseCount == 0)
		fout << courseCount;
	else
		fout << courseCount << endl;

	for (int i = 0; i < courseCount; i++)
	{
		fout << studentsCourses[i] << endl;
		fout << marksTotal[i] << endl;
		fout << marksObtained[i];
		if (i != courseCount - 1)
			fout << endl;
	}
}

void Student::assignCourse(string course, bool first)
{
	if (first)
	{
		marksObtained = NULL;
		marksTotal = NULL;
		studentsCourses = NULL;
	}
	marksObtained = resize(marksObtained, marksObtainedCount);
	marksTotal= resize(marksTotal, marksTotalCount);
	studentsCourses = resize(studentsCourses, courseCount);
	studentsCourses[courseCount - 1] = course;
}

void Student::display()
{
	cout << "\n Roll Number: " << rollNo << endl;
	cout << "\n Name: " << firstName << " " << lastName << endl;
	cout << "\n Class: " << klass << endl;
	cout << "\n Contact Number: " << contactNo << endl;
}

void Student::edit()
{
	int input;
	cout << "\n New first name: ";
	cin >> firstName;
	cout << "\n New last name: ";
	cin >> lastName;

	cout << "\n Is the fee submitted for this student?"
		<< "\n\n\t 1 - Yes"
		<< "\n\n\t 2 - No"
		<< "\n\n Enter: ";

	while (!(cin >> input) || input < 1 || input > 2)
	{
		cout << "\n Invalid input. Please try again: ";
		cin.clear();
		cin.ignore(123, '\n');
	}
	cin.ignore();
	if (input == 1)
		feeSubmitted = true;

	cout << "\n Address: ";
	getline(cin, address);
	cout << "\n Contact Number: ";
	getline(cin, contactNo);
}

void Student::read(ifstream& obj)
{
	studentCount++;
	string temp;
	obj >> firstName;
	if(firstName == "")
		obj >> firstName;
	obj >> lastName;
	obj.ignore(123, '\n');
	getline(obj, rollNo);
	obj >> klass;
	getline(obj, temp, '/');
	dateOfRegistration.day = stoi(temp);
	getline(obj, temp, '/');
	dateOfRegistration.month = stoi(temp);
	getline(obj, temp, '\n');
	dateOfRegistration.year = stoi(temp);
	getline(obj, gender);
	getline(obj, contactNo);
	getline(obj, fatherName);
	getline(obj, fatherProfession);
	getline(obj, fathersContactNo);
	obj >> feeSubmitted;
	obj.ignore(123, '\n');
	getline(obj, temp);

	bloodType = temp[0];

	if (temp[1] == '+')
		RhFactor = true;
	else
		RhFactor = false;

	getline(obj, address);

	getline(obj, password);

	obj >> courseCount;
	obj.ignore(123, '\n');

	studentsCourses = new string[courseCount];
	marksTotal = new double[marksTotalCount];
	marksObtained = new double[marksObtainedCount];

	for (int i = 0; i < courseCount; i++)
	{
		getline(obj, studentsCourses[i]);
		obj >> marksTotal[i];
		obj >> marksObtained[i];
	}
}

string Student::getName()
{
	return firstName + " " + lastName;
}

string Student::getRollNumber()
{
	return rollNo;
}

int Student::getCourseCount()
{
	return courseCount;
}

int Student::getClass()
{
	return klass;
}

void Student::displayCourses()
{
	for (int i = 0; i < courseCount; i++)
		cout << "\n " << i + 1 << " - " << studentsCourses[i] << endl;
}

void Student::displayMarks()
{
	cout << "\n Roll number: " << rollNo << endl;
	for (int i = 0; i < courseCount; i++)
	{
		cout << "\n Course name: " << studentsCourses[i] << endl;
		cout << "\n Total marks: " << marksTotal[i] << endl;
		cout << "\n Obtained marks: " << marksObtained[i] << endl;
	}
}

string Student::getPass()
{
	return password;
}

bool Student::getFeeStatus()
{
	return feeSubmitted;
}

void Student::setMarks(int courseNumber, double total, double obtained)
{
	marksTotal[courseNumber - 1] = total;
	marksObtained[courseNumber - 1] = obtained;
}

void Student::setMarks(string course, double total, double obtained)
{
	int courseNumber = 0;
	for (int i = 0; i < courseCount; i++)
	{
		if (studentsCourses[i] == course)
			i = courseNumber;
	}
	marksTotal[courseNumber - 1] = total;
	marksObtained[courseNumber - 1] = obtained;
}

// *************************** C O U R S E ***************************

Course::Course()
{
	name = " ";
	code = " ";
	klass = 0;
	parentCourse = " ";
}

void Course::takeInput()
{
	cout << "\n Course Name: ";
	getline(cin, name);
	cout << "\n Course Code: ";
	getline(cin, code);

	cout << "\n Class(1 to 10 inclusive): ";

	while (!(cin >> klass) || klass > 10 || klass < 0)
	{
		cout << "\n Invalid input. Please try again: ";
		cin.clear();
		cin.ignore(123, '\n');
	}
	cin.ignore();
	cout << "\n Parent Course: ";
	getline(cin, parentCourse);

	write();
}

void Course::write()
{
	ofstream fout("Courses.txt", ios::app);

	fout << endl << name << endl;
	fout << code << endl;
	fout << klass << endl;
	fout << parentCourse;

	fout.close();
}

void Course::display()
{
	cout << "\n Course name: " << name << endl;
	cout << "\n Course code: " << code << endl;
	cout << "\n Class for the course: " << klass << endl;
	cout << "\n Parent course: " << parentCourse << endl;
}

string Course::getName()
{
	return name;
}

int Course::getClass()
{
	return klass;
}

void Course::read(ifstream& obj)
{
	getline(obj, name);
	if (name == "")
		getline(obj, name);
	getline(obj, code);
	obj >> klass;
	obj.ignore(123, '\n');
	getline(obj, parentCourse);
}

// *************************** A D M I N I S T R A T O R ***************************

Administrator::Administrator()
{
	students = NULL;
	teachers = NULL;
	courses = NULL;
	username = "admin";
	password = "admin";
}

void Administrator::viewFeeStatusAsStudent()
{
	if (students[iStudent].getFeeStatus())
		cout << "\n Fee submitted" << endl;
	else
		cout << "\n Fee not submitted" << endl;
}

void Administrator::viewMarksAsStudent()
{
	students[iStudent].displayMarks();
}

void Administrator::teacherLogin()
{
	bool found = false;
	string pass;
	cout << "\n Username: ";
	while (!found)
	{
		getline(cin, username);

		for (iTeacher = 0; iTeacher < numberOfTeachers && !found; iTeacher++)
			if (username == teachers[iTeacher].getUserName())
				found = true;

		if (!found)
		{
			cout << "\n No user with the entered username exists." << endl;
			cout << "\n Try again: ";
		}
	}

	iTeacher--;

	cout << "\n Password: ";
	getline(cin, pass);

	while (pass != teachers[iTeacher].getPass())
	{
		cout << "\n Wrong password. Try again: ";
		cin.clear();
		getline(cin, pass);
	}
}

void Administrator::studentLogin()
{
	bool found = false;
	string pass;
	cout << "\n Username: ";
	while (!found)
	{
		getline(cin, username);

		for (iStudent = 0; iStudent < numberOfStudents && !found; iStudent++)
			if (username == students[iStudent].getRollNumber())
				found = true;

		if (!found)
		{
			cout << "\n No user with the entered username exists." << endl;
			cout << "\n Try again: ";
		}
	}

	iStudent--;

	cout << "\n Password: ";
	getline(cin, pass);

	while (pass != students[iStudent].getPass())
	{
		cout << "\n Wrong password. Try again: ";
		cin.clear();
		getline(cin, pass);
	}
}

void Administrator::viewTeachersCourses()
{
	int count = 0;
	string* teachersCourses = teachers[iTeacher].getCourses();
	int teacherCourseCount = teachers[iTeacher].getCourseCount();
	for (int i = 0; i < numberOfCourses; i++)
	{
		for (int j = 0; j < teacherCourseCount; j++)
		{
			if (courses[i].getName() == teachersCourses[j])
			{
				cout << "\n Course name: " << courses[i].getName() << endl;
				cout << "\n Class: " << courses[i].getClass() << endl;
				for (int k = 0; k < numberOfStudents; k++)
				{
					if (students[i].getClass() == courses[i].getClass())
						count++;
				}
				cout << "\n Total number of students registered in course are: " << count << endl;
			}
		}
	}
}

void Administrator::adminLogin()
{
	string pass;
	cout << "\n Username: " << username << endl;
	cout << "\n Enter the password: ";
	while (!(getline(cin, pass)) || pass != password)
	{
		cout << "\n Wrong password. Try again: ";
		cin.clear();
	}
}

void Administrator::addStudent()
{
	students = resize(students, numberOfStudents);
	cout << "\n Student was successfully added." << endl;
	cout << "\n Now enter the following details:" << endl;
	students[numberOfStudents - 1].takeInput();
}

void Administrator::addTeacher()
{
	teachers = resize(teachers, numberOfTeachers);
	cout << "\n Teacher was successfully added." << endl;
	cout << "\n Now enter the following details:" << endl;
	teachers[numberOfTeachers - 1].takeInput();
}
void Administrator::addCourse()
{
	courses = resize(courses, numberOfCourses);
	cout << "\n Course was successfully added." << endl;
	cout << "\n Now enter the following details:" << endl;
	courses[numberOfCourses - 1].takeInput();
}
void Administrator::assignCourse()
{
	readTeachers();
	readCourses();
	int input = 0, input2 = 0;
	cout << "\n Select a teacher from the following: " << endl;

	cout << "\n\nSr. No.\t\tName " << endl;
	for (int i = 0; i < numberOfTeachers; i++)
		cout << "\n " << i + 1 << " - " << teachers[i].getName() << endl;

	cout << "\n Enter: ";
	while (!(cin >> input) || input < 1 || input > numberOfTeachers)
	{
		cin.clear();
		cin.ignore(123, '\n');
		cout << "\n Please enter a valid number: ";
	}
	cin.ignore();

	cout << "\n Select a course to assign to this teacher: " << endl;

	cout << "\n\nSr. No.\t\t Course name " << endl;
	for (int i = 0; i < numberOfCourses; i++)
		cout << "\n " << i + 1 << " - " << courses[i].getName() << endl;

	cout << "\n Enter: ";

	while (!(cin >> input2) || input2 < 1 || input2 > numberOfCourses)
	{
		cout << "\n Please enter a valid number: ";
		cin.clear();
		cin.ignore(123, '\n');
	}

	teachers[input - 1].assignCourse(courses[input2 - 1].getName());

	ofstream writeTeachers("Teachers.txt");

	for (int i = 0; i < numberOfTeachers; i++)
		teachers[i].write(writeTeachers);

	writeTeachers.close();

}

void Administrator::editStudent()
{
	readStudents();
	int index = 0;
	cout << "\n Select a student from the following: " << endl;

	cout << "\n\nSr. No.\t\tName " << endl;
	for (int i = 0; i < numberOfStudents; i++)
		cout << "\n " << i + 1 << " - " << students[i].getName() << endl;

	cout << "\n Enter: ";
	while (!(cin >> index) || index < 1 || index > numberOfStudents)
	{
		cin.clear();
		cin.ignore(123, '\n');
		cout << "\n Please enter a valid number: ";
	}

	students[index - 1].edit();

	ofstream writeStudents("Students.txt");

	for (int i = 0; i < numberOfStudents; i++)
		students[i].write(writeStudents);

	writeStudents.close();
}

void Administrator::editTeacher()
{
	readTeachers();
	int index = 0;
	cout << "\n Select a teacher from the following: " << endl;
	
	cout << "\n\n Sr. No.\t\tName " << endl;
	for (int i = 0; i < numberOfTeachers; i++)
		cout << "\n " << i + 1 << "\t\t" << teachers[i].getName() << endl;
	
	cout << "\n Enter: ";
	while (!(cin >> index) || index < 1 || index > numberOfTeachers)
	{
		cin.clear();
		cin.ignore(123, '\n');
		cout << "\n Please enter a valid number: ";
	}
	
	cin.ignore();

	teachers[index - 1].edit();

	ofstream writeTeachers("Teachers.txt");

	for (int i = 0; i < numberOfTeachers; i++)
		teachers[i].write(writeTeachers);

	writeTeachers.close();
}

void Administrator::viewStudents()
{
	readStudents();
	int option, subOption = 0;
	bool found = false;
	string input;
	cout << "\n Choose an option: "
		<< "\n\n\t 1 - Search by roll number"
		<< "\n\n\t 2 - Display all students"
		<< "\n\n Enter: ";
	while (!(cin >> option) || option < 1 || option > 2)
	{
		cout << "\n Invalid input. Please try again: ";
		cin.clear();
		cin.ignore(123, '\n');
	}
	switch (option)
	{
	case 1:
		while (subOption != 2)
		{
			cout << "\n Enter the roll number: ";
			cin >> input;
			for (int i = 0; i < numberOfStudents && !found; i++)
			{
				if (students[i].getRollNumber() == input)
				{
					students[i].display();
					found = true;
					subOption = 2;
				}
			}
			if (!found)
			{
				cout << "\n No matches found."
					<< "\n\n\t 1 - Try again"
					<< "\n\n\t 2 - Return"
					<< "\n\n Enter: ";
				while (!(cin >> subOption) || subOption < 1 || subOption > 2)
				{
					cout << "\n Invalid input. Please try again: ";
					cin.clear();
					cin.ignore(123, '\n');
				}
			}
		}
		break;
	case 2:
		for (int i = 0; i < numberOfStudents; i++)
			students[i].display();
		break;
	}
}

void Administrator::viewTeachers()
{
	readTeachers();
	for (int i = 0; i < numberOfTeachers; i++)
		teachers[i].display();
}

void Administrator::viewCourses()
{
	readCourses();
	for (int i = 0; i < numberOfCourses; i++)
		courses[i].display();
}

void Administrator::updateStudentMarksAsTeacher()
{
	readStudents();
	readCourses();

	bool found = false;
	double total = 0, obtained = 0;

	string* teachersCourses = teachers[iTeacher].getCourses();
	int teacherCourseCount = teachers[iTeacher].getCourseCount();

	for (int i = 0; i < numberOfCourses; i++)
	{
		for (int j = 0; j < teacherCourseCount; j++)
		{
			if (courses[i].getName() == teachersCourses[j])
			{
				for (int k = 0; k < numberOfStudents; k++)
				{
					if (students[k].getClass() == courses[i].getClass())
					{
						cout << "\n Enter total marks: ";
						cin >> total;
						cout << "\n Enter obtained marks: ";
						cin >> obtained;
						found = true;

						students[i].setMarks(courses[i].getName() , total, obtained);
					}
				}
				if (!found)
				{
					cout << "\n No students have been enrolled in the course " << teachersCourses[j] << endl;
				}
			}
		}
	}


	ofstream writeStudents("Students.txt");

	for (int i = 0; i < numberOfStudents; i++)
		students[i].write(writeStudents);

	writeStudents.close();
}

void Administrator::updateStudentMarks()
{
	readStudents();
	readCourses();

	for (int i = 0; i < numberOfStudents; i++)
	{
		for (int j = 0; j < numberOfCourses; j++)
		{
			if (students[i].getClass() == courses[j].getClass())
			{
				students[i].assignCourse(courses[j].getName(), false);
			}
		}
	}

	int input = 0, index = 0;
	double total = 0, obtained = 0;
	string rollNumber;
	cout << "\n Choose a class from 1 to 10: ";
	while (!(cin >> input) || input < 1 || input > 10)
	{
		cout << "\n Invalid input. Please try again: ";
		cin.clear();
		cin.ignore(123, '\n');
	}

	for (int i = 0; i < numberOfStudents; i++)
	{
		if (students[i].getClass() == input)
			students[i].display();
	}

	cout << "\n Enter student roll number: ";
	cin >> rollNumber;

	bool found = false;

	for (int i = 0; i < numberOfStudents && !found; i++)
	{
		if (students[i].getRollNumber() == rollNumber)
		{
			index = i;
			found = true;
			break;
		}
	}
	if (!found)
	{
		cout << "\n No student found having this roll number." << endl;
		return;
	}

	students[index].displayCourses();
	cout << "\n Select course: ";
	while (!(cin >> input) || input < 1 || input > students[index].getCourseCount())
	{
		cout << "\n Invalid input. Please try again: ";
		cin.clear();
		cin.ignore(123, '\n');
	}
	
	cout << "\n Enter total marks: ";
	cin >> total;
	cout << "\n Enter obtained marks: ";
	cin >> obtained;

	students[index].setMarks(input, total, obtained);

	ofstream writeStudents("Students.txt");

	for (int i = 0; i < numberOfStudents; i++)
		students[i].write(writeStudents);

	writeStudents.close();
}

void Administrator::viewFeeStatus()
{
	readStudents();
	int index = 0;
	cout << "\n Select a student from the following: " << endl;

	cout << "\n\n Sr. No.\t\tName " << endl;
	for (int i = 0; i < numberOfStudents; i++)
		cout << "\n " << i + 1 << "\t\t\t" << students[i].getName() << endl;

	cout << "\n Enter: ";
	while (!(cin >> index) || index < 1 || index > numberOfStudents)
	{
		cin.clear();
		cin.ignore(123, '\n');
		cout << "\n Please enter a valid number: ";
	}

	if (students[index - 1].getFeeStatus())
		cout << "\n Fee status: Submitted" << endl;
	else
		cout << "\n Fee status: Not Submitted" << endl;
}

void Administrator::viewStudentMarks()
{
	readStudents();
	int index = 0;
	cout << "\n Select a student from the following: " << endl;

	cout << "\n\n Sr. No.\t\tName " << endl;
	for (int i = 0; i < numberOfStudents; i++)
		cout << "\n " << i + 1 << "\t\t\t" << students[i].getName() << endl;

	cout << "\n Enter: ";
	while (!(cin >> index) || index < 1 || index > numberOfStudents)
	{
		cin.clear();
		cin.ignore(123, '\n');
		cout << "\n Please enter a valid number: ";
	}

	students[index - 1].displayMarks();
}

void Administrator::readTeachers()
{
	numberOfTeachers = 0;
	ifstream in("Teachers.txt");
	if (!in)
		return;
	while (!in.eof())
	{
		teachers = resize(teachers, numberOfTeachers);
		teachers[numberOfTeachers - 1].read(in);
		if (in.eof())
			break;
	}
}

void Administrator::readCourses()
{
	numberOfCourses = 0;
	ifstream in("Courses.txt");
	if (!in)
		return;
	while (!in.eof())
	{
		courses = resize(courses, numberOfCourses);
		courses[numberOfCourses - 1].read(in);
		if (in.eof())
			break;
	}
}

void Administrator::readStudents()
{
	numberOfStudents = 0;
	ifstream in("Students.txt");
	if (!in)
		return;
	while (!in.eof())
	{
		students = resize(students, numberOfStudents);
		students[numberOfStudents - 1].read(in);
		if (in.eof())
			break;
	}
}