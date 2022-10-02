#include<iostream>
#include<string>
#include<string.h>
#include<fstream>
#include"Person.h"
using namespace std;
struct date {
	int day;
	int month;
	int year;
};
class Person;
class Student :public Person
{ private:
	int Class;
	string rollNo;
	date obj_date;
	int Contact;
	string father_Name;
	string father_Profession;
	int parents_Contact;
	char  Fee_submitted;
	string Blood_Group;
	string Address;
	ofstream std;
	char chk;//for entering another student or not
	int i;//for file handling wali loop
public:
	void add();
	void del();
	void show();
	void update();
	void search();

};
