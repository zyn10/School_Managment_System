#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include "brah.h"
using namespace std;

// 19F-0316 M Talha Zafar

int Student::studentCount = 0;
int Student::courseCount = 0;
int Student::marksTotalCount = 0;
int Student::marksObtainedCount = 0;
int Administrator::numberOfStudents = 0;
int Administrator::numberOfTeachers = 0;
int Administrator::numberOfCourses = 0;
int Teacher::courseCount = 0;

int main()
{
	Administrator theBoss;

	int option, subOption;
	cout << "\n Who are you?"
		<< "\n\n\t 1 - Administrator"
		<< "\n\n\t 2 - Teacher"
		<< "\n\n\t 3 - Student"
		<< "\n\n\t 4 - Exit"
		<< "\n\n Enter: ";
	while (!(cin >> option) || option < 1 || option > 4)
	{
		cout << "\n Invalid input. Please try again: ";
		cin.clear();
		cin.ignore(123, '\n');
	}
	cin.ignore();

	while (option != 4)
	{
		system("cls");
		switch (option)
		{
		case 1:

			theBoss.readCourses();
			theBoss.readStudents();
			theBoss.readTeachers();

			theBoss.adminLogin();

			system("cls");
			cout << "\n Choose an option"
				<< "\n\n\t 1 - Add a new student"
				<< "\n\n\t 2 - Add a new teacher"
				<< "\n\n\t 3 - Add a new course"
				<< "\n\n\t 4 - Assign course"
				<< "\n\n\t 5 - Edit student details"
				<< "\n\n\t 6 - Edit teacher details"
				<< "\n\n\t 7 - View all students"
				<< "\n\n\t 8 - View all teachers"
				<< "\n\n\t 9 - View all courses"
				<< "\n\n\t 10 - Update student marks"
				<< "\n\n\t 11 - View student marks"
				<< "\n\n\t 12 - View fee status"
				<< "\n\n\t 13 - Log out"
				<< "\n\n Enter: ";
			while (!(cin >> subOption) || subOption < 1 || subOption > 13)
			{
				cout << "\n Invalid input. Please try again: ";
				cin.clear();
				cin.ignore(123, '\n');
			}
			cin.ignore();

			while (subOption != 13)
			{
				system("cls");
				switch (subOption)
				{
				case 1:
					theBoss.addStudent();
					break;
				case 2:
					theBoss.addTeacher();
					break;
				case 3:
					theBoss.addCourse();
					break;
				case 4:
					theBoss.assignCourse();
					break;
				case 5:
					theBoss.editStudent();
					break;
				case 6:
					theBoss.editTeacher();
					break;
				case 7:
					theBoss.viewStudents();
					break;
				case 8:
					theBoss.viewTeachers();
					break;
				case 9:
					theBoss.viewCourses();
					break;
				case 10:
					theBoss.updateStudentMarks();
					break;
				case 11:
					theBoss.viewStudentMarks();
					break;
				case 12:
					theBoss.viewFeeStatus();
					break;
				}

				system("pause > 0");
				system("cls");

				cout << "\n Choose an option"
					<< "\n\n\t 1 - Add a new student"
					<< "\n\n\t 2 - Add a new teacher"
					<< "\n\n\t 3 - Add a new course"
					<< "\n\n\t 4 - Assign course"
					<< "\n\n\t 5 - Edit student details"
					<< "\n\n\t 6 - Edit teacher details"
					<< "\n\n\t 7 - View all students"
					<< "\n\n\t 8 - View all teachers"
					<< "\n\n\t 9 - View all courses"
					<< "\n\n\t 10 - Update student marks"
					<< "\n\n\t 11 - View student marks"
					<< "\n\n\t 12 - View fee status"
					<< "\n\n\t 13 - Log out"
					<< "\n\n Enter: ";
				while (!(cin >> subOption) || subOption < 1 || subOption > 13)
				{
					cout << "\n Invalid input. Please try again: ";
					cin.clear();
					cin.ignore(123, '\n');
				}
				cin.ignore();
			}

			break;
		case 2:

			theBoss.readCourses();
			theBoss.readStudents();
			theBoss.readTeachers();

			theBoss.teacherLogin();

			cout << "\n Choose an option"
				<< "\n\n\t 1 - View my courses"
				<< "\n\n\t 2 - Update student marks"
				<< "\n\n\t 3 - Log out"
				<< "\n\n Enter: ";
			while (!(cin >> subOption) || subOption < 1 || subOption > 3)
			{
				cout << "\n Invalid input. Please try again: ";
				cin.clear();
				cin.ignore(123, '\n');
			}

			while (subOption != 3)
			{
				switch (subOption)
				{
				case 1:
					theBoss.viewTeachersCourses();
					break;
				case 2:

					theBoss.updateStudentMarksAsTeacher();

					break;
				}

				system("pause > 0");
				system("cls");

				cout << "\n Choose an option"
					<< "\n\n\t 1 - View my courses"
					<< "\n\n\t 2 - Update student marks"
					<< "\n\n\t 3 - Log out"
					<< "\n\n Enter: ";
				while (!(cin >> subOption) || subOption < 1 || subOption > 3)
				{
					cout << "\n Invalid input. Please try again: ";
					cin.clear();
					cin.ignore(123, '\n');
				}
			}

			break;
		case 3:

			theBoss.readCourses();
			theBoss.readStudents();
			theBoss.readTeachers();

			theBoss.studentLogin();

			cout << "\n Choose an option"
				<< "\n\n\t 1 - View assessment marks"
				<< "\n\n\t 2 - View fee status"
				<< "\n\n\t 3 - Log out"
				<< "\n\n Enter: ";
			while (!(cin >> subOption) || subOption < 1 || subOption > 3)
			{
				cout << "\n Invalid input. Please try again: ";
				cin.clear();
				cin.ignore(123, '\n');
			}

			while (subOption != 3)
			{
				switch (subOption)
				{
				case 1:

					theBoss.viewMarksAsStudent();

					break;
				case 2:

					theBoss.viewFeeStatusAsStudent();

					break;
				}
				system("pause > 0");
				system("cls");

				cout << "\n Choose an option"
					<< "\n\n\t 1 - View assessment marks"
					<< "\n\n\t 2 - View fee status"
					<< "\n\n\t 3 - Log out"
					<< "\n\n Enter: ";
				while (!(cin >> subOption) || subOption < 1 || subOption > 3)
				{
					cout << "\n Invalid input. Please try again: ";
					cin.clear();
					cin.ignore(123, '\n');
				}
			}
		}
		system("pause > 0");
		system("cls");

		cout << "\n Who are you?"
			<< "\n\n\t 1 - Administrator"
			<< "\n\n\t 2 - Teacher"
			<< "\n\n\t 3 - Student"
			<< "\n\n\t 4 - Exit"
			<< "\n\n Enter: ";
		while (!(cin >> option) || option < 1 || option > 4)
		{
			cout << "\n Invalid input. Please try again: ";
			cin.clear();
			cin.ignore(123, '\n');
		}
		cin.ignore();
	}
}