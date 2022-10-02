#pragma once 
#include <iostream>
#include <string>
using namespace std;

// 19F-0316 M Talha Zafar

struct Date {

	int day;
	int month;
	int year;
};

class Person {

protected:

	string firstName;
	string lastName;
	string gender;
	string address;
	string password;
	string confirmPassword;
	string contactNo;

public:

	Person();
	virtual void takeInput() = 0;
};

class Teacher : public Person {

protected:

	string email;
	Date joiningDate;
	Date dateOfBirth;
	string CNIC;
	string username;
	string qualification;
	string* teachersCourses;		// Wrote teachersCourses to avoid confusion with the other pointer named 'courses';
	static int courseCount;
	double salary;


public:

	Teacher();
	void takeInput();
	void write();
	void write(ofstream& fout);
	void assignCourse(string course);
	void read(ifstream& obj);
	void display();
	void edit();
	string getName();
	string getUserName();
	string getPass();
	string* getCourses();
	int getCourseCount();
};

class Student : public Person {

protected:

	int klass;	// Can't name it "class" :/
	string rollNo;
	Date dateOfRegistration;
	string fatherName;
	string fatherProfession;
	string fathersContactNo;
	bool feeSubmitted;
	string* studentsCourses;
	double* marksObtained;
	double* marksTotal;

	// Blood Type
	string bloodType;
	bool RhFactor;	// 1 - Present - Positive
					// 2 - Absent - Negative

	static int studentCount;
	static int courseCount;
	static int marksTotalCount;
	static int marksObtainedCount;

public:

	Student();
	void takeInput();
	void write();
	void write(ofstream& fout);
	void display();
	void edit();
	void assignCourse(string course, bool first);
	bool getFeeStatus();
	void read(ifstream& obj);
	string getRollNumber();
	int getClass();
	int getCourseCount();
	string getPass();
	string getName();
	void setMarks(int courseNumber, double marksTotal, double marksObtained);
	void setMarks(string course, double marksTotal, double marksObtained);
	void displayCourses();
	void displayMarks();
};

class Course {

protected:

	string name;
	string code;
	int klass;
	string parentCourse;

public:

	Course();
	void takeInput();
	void write();
	string getName();
	int getClass();
	void read(ifstream& obj);
	void display();
};

class Administrator {

protected:

	string username;
	string password;
	int iTeacher;
	int iStudent;
	static int numberOfStudents;
	static int numberOfTeachers;
	static int numberOfCourses;

	Student* students;
	Teacher* teachers;
	Course* courses;

public:

	Administrator();

	void teacherLogin();
	void studentLogin();
	void adminLogin();

	void viewTeachersCourses();
	void viewFeeStatusAsStudent();
	void viewMarksAsStudent();

	void addStudent();
	void addTeacher();
	void addCourse();
	void assignCourse();
	void editStudent();
	void editTeacher();
	void viewStudents();
	void viewTeachers();
	void viewCourses();
	void updateStudentMarks();
	void updateStudentMarksAsTeacher();
	void viewFeeStatus();
	void viewStudentMarks();
	void readTeachers();
	void readCourses();
	void readStudents();
};