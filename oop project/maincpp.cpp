#include<iostream>
#include<string>
#include<string.h>
#include<ctime>
#include<cstdlib>
#include<fstream>
#include"Admin.h"
using namespace std;
class Menu
{
private:

public:
	void dis()
	{
		system("COLOR 70");
		cout << endl << endl << "        ";
		for (int c = 0; c<30; c++)					// ----> The main heading line
		{
			cout << "*";
		}
		cout << "  _Welcome to The School Management System_  ";
		for (int c = 0; c<30; c++)
		{
			cout << "*";
		}
		cout << endl;
		cout << endl;

		cout << "\t\t\t\t Please Enter the password to gain access to the system : " << endl << endl;
	}
	void dis1()
	{
		cout << endl << endl << "\t\t\t\t>>>>>>>>>  School Managment System  <<<<<<<<<" << endl;
		cout << "\t\t\t\t   ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ " << endl;
		cout << "\t\t\t\t  | Press  1 to gain access to Admin Mode        |" << endl;
		cout << "\t\t\t\t  |                                              |" << endl;
		cout << "\t\t\t\t  | Press  2 to gain access to Teacher Mode      |" << endl;
		cout << "\t\t\t\t  |                                              |" << endl;
		cout << "\t\t\t\t  | Press  3 to gain access to Student Mode      |" << endl;
		cout << "\t\t\t\t  |                                              |" << endl;
		cout << "\t\t\t\t  | Press  0 to Exit                             |" << endl;
		cout << "\t\t\t\t   ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ " << endl;
		cout << "\t\t\tInput Your Choice : ";
		cout << endl << " Please enter your choice (1-3) :   ";
	}
	void dis2()
	{
		cout << endl << endl << "\t\t\t\t>>>>>>>>>  School Managment System  <<<<<<<<<" << endl;
		cout << endl << endl << "\t\t\t\t................Admin Mode..................." << endl;
		cout << "\t\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
		cout << "\t\t\t\t| Press  1:   To Add New Student              |" << endl;
		cout << "\t\t\t\t|                                             |" << endl;
		cout << "\t\t\t\t| Press  2:   To Add New Teacher              |" << endl;
		cout << "\t\t\t\t|                                             |" << endl;
		cout << "\t\t\t\t| Press  3:   To Add New Course               |" << endl;
		cout << "\t\t\t\t|                                             |" << endl;
		cout << "\t\t\t\t| Press  4:   To Assign Course                |" << endl;
		cout << "\t\t\t\t|                                             |" << endl;
		cout << "\t\t\t\t| Press  5:   To Update Student               |" << endl;
		cout << "\t\t\t\t|                                             |" << endl;
		cout << "\t\t\t\t| Press  6:   To Update Teacher               |" << endl;
		cout << "\t\t\t\t|                                             |" << endl;
		cout << "\t\t\t\t| Press  7:   To View All Students            |" << endl;
		cout << "\t\t\t\t|                                             |" << endl;
		cout << "\t\t\t\t| Press  8:   To View All Teachers            |" << endl;
		cout << "\t\t\t\t|                                             |" << endl;
		cout << "\t\t\t\t| Press  9:   To View All Courses             |" << endl;
		cout << "\t\t\t\t|                                             |" << endl;
		cout << "\t\t\t\t| Press 10:   To Update Student Marks         |" << endl;
		cout << "\t\t\t\t|                                             |" << endl;
		cout << "\t\t\t\t| Press 11:   To View Student Marks           |" << endl;
		cout << "\t\t\t\t|                                             |" << endl;
		cout << "\t\t\t\t| Press 11:   To View Fee Status              |" << endl;
		cout << "\t\t\t\t|                                             |" << endl;
		cout << "\t\t\t\t| Press  0:   To Exit                         |" << endl;
		cout << "\t\t\t\t ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl << endl;
		cout << "\t\t\t\tInput Your Choice : ";
	}
	void dis3()
	{
		cout << "Teacher Section Pending" << endl;
		cout << endl << " Please enter your choice (1-9) :   ";
	}
	void dis4()
	{
		cout << "Student Section Pending" << endl;
		cout << endl << " Please enter your choice (1-9) :   ";
	}
};
class TryPass
{
private:
	string pw;
	int loginTry;
	int a;
public:

	bool trypass()
	{
		loginTry = 0;
		a = 2;
		while (loginTry <= 0)

		{
			cout << "                                              ";
			cin >> pw;		// ----> input password string for login to the library
			if (pw == "p")
			{
				system("cls");
				loginTry = 1;
			}
			else
			{
				cout << "\n\t   You entered the wrong password, please try again by pressing another password. " << a << " tries left.\n\n\n";
				loginTry--;
				a--;
			}
			if (loginTry == -3)
			{
				cout << "\n\t\t\t   You tried many times.The system is exiting. " << endl << endl;
				return false;

			}
		}
	}
};
int main()
{
	srand(time(NULL));
	string n;
	Menu a;
	TryPass t;
	Admin d;
	Person *student;// , *teacher, *course;
	Student p;
	//Teacher obj_T;
	//Course  obj_C;
	student = &p;
	//teacher = &doc;
	//course = &course;
	a.dis();
	if (t.trypass() == 0)
	{
		goto exit;
	}
top1:		// ----> defining label for first screen
	a.dis1();
	cin >> n;
	if (n == "1")
	{	//----------------------------------------------------------------------------------------
		// ADMIN MODE
		if (d.isLogin() == 1)
		{
		top2:
			system("cls");
			a.dis2();
			cin >> n;
			if (n == "1")
			{
				student->add();
				goto top2;
			}
			if (n == "2")
			{
				//student->del();
				goto top2;
			}
			if (n == "3")
			{
				//teacher->add();
				goto top2;
			}
			if (n == "4")
			{
				//teacher->del();
				goto top2;
			}
			if (n == "5")
			{
				//course->add();
				goto top2;
			}
			if (n == "6")
			{
				//course->del();
				goto top2;
			}
			if (n == "7")
			{
				//student->update();
				goto top2;
			}
			if (n == "8")
			{
				//teacher->up();
				goto top2;
			}
			if (n == "9")
			{
				//course->up();
				goto top2;
			}
			if (n == "10")
			{
				//s.doAssign();
				goto top2;
			}
			if (n == "11")
			{
				system("cls");
				goto top1;
			}
			if (n == "0")
			{
				goto exit;
			}
			else
			{
				cout << "\n Invalid Entry. Please try again. \n\n";
				system("pause");
				goto top2;
			}
		}
		else
		{
			if (d.isLoginTry() == 1)
			{
				goto top2;
			}
		}
	}
	//---------------------------------------------------------------------
	// Student SECTION
	if (n == "2")
	{
	top3:

		system("cls");
		a.dis3();
		cin >> n;
		if (n == "1")
		{
			//student->show();//student list
			system("pause");
			goto top3;
		}
		if (n == "2")
		{
			//teacher->show();//teacher list
			goto top3;
		}
		if (n == "3")
		{
			//course->show();//course list
			system("pause");
			goto top3;
		}
		if (n == "4")
		{
			//student->search();//Seacrch student
			goto top3;
		}

		if (n == "5")
		{
			//course->search();search course
			goto top3;
		}
		if (n == "6")
		{
			//teacher->search();//teacher search
			goto top3;
		}
		if (n == "7")
		{
			//s.showAssign();
			system("pause");
			goto top3;
		}
		if (n == "8")
		{
			system("cls");
			goto top1;
		}
		if (n == "9")
		{
			goto exit;
		}
		else
		{
			cout << "\n Invalid Entry. Please try again. \n\n";
			system("pause");
			goto top2;
		}

	}
	if (n == "3")
	{
		goto exit;
	}
	else
	{
		cout << "\n Invalid Entry. Please try again. \n\n";
		system("pause");
		system("cls");
		goto top1;
	}

exit:
	system("pause>0");
}
