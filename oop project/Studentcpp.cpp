#include<iostream>
#include<string>
#include<string.h>
#include<ctime>
#include<cstdlib>
#include<fstream>
#include"Student.h"
using namespace std;
void Student::add()
{	
system("cls");
	std.open("student.txt", ios::app);
	Student info[99];
	i = 1;
	do 
	{	
		cin.ignore(1);
		cout << "Enter First Name                     : ";
		getline(cin,info[i].firstName);
		cout << "Enter Last Name                      : ";
		getline(cin,info[i].lastName);
		cout << "Enter Class (First to matric as 01,02 to 10 number):";
	    cin >> info[i].Class;

		/*	if (Class >= 1 && Class <= 10)
			{
				rollNo = "0" + to_string(Class) + to_string(i);
            	break;
			}
			else
			{
                  cout << "Invalid Input" << endl;
				  cout << "input the Class AGAIN" << endl;
		          cin >> info[i].Class;
			}
		*/

		cout << " Input the Registration Date.......... " << endl;
		cout << " Day                                 : ";  cin >> info[i].obj_date.day;
		cout << " Month                               : ";  cin >> info[i].obj_date.month;
		cout << " Year                                : ";  cin >> info[i].obj_date.year;
		cout << " Enter Gender                        : ";  cin >> info[i].gender;
		/*while (1)
		{    
		if (gender == 'm' || gender == 'm' || gender == 'f' || gender == 'F')
		{
			break;
		}
		else
		{
			cout << "invalid input" << endl;
		}
		}
		*/
		cout << "Enter  Contact No (only 11 numbers)  : "; cin >>info[i].Contact;
		cin.ignore();
	    cout << "Enter the Father Name                : ";getline(cin, info[i].father_Name);
		cout << "Father’s Profession                  : ";getline(cin, info[i].father_Profession);
		cout << "Fathers Contact No (only 11 numbers) : "; cin >> info[i].parents_Contact;
		cout << "Is your fee have been submitted (y/n)  "; cin >> info[i].Fee_submitted;
		if (info[i].Fee_submitted == 'y')
		{
			cout << "Thank you for submitting the fee on time " << endl;
		}
		else
		{
			cout << "Please submit your fee as soon as possible " << endl;
		}
		cout << "Input your Blood Group               : " ;cin >> info[i].Blood_Group;
		cin.ignore(1);
		cout << "Enter the address " << endl;
		getline(cin, info[i].Address);
		std << endl 
			<< info[i].firstName        <<"," 
			<< info[i].lastName         <<"," 
			<< info[i].Class            <<"," 
			<<"0"<<info[i].Class<<i     <<","
			<< info[i].obj_date.day<<"-"<< info[i].obj_date.month<<"-"<< info[i].obj_date.year<<","
			<< info[i].gender           <<","
			<< info[i].father_Name      <<","
			<< info[i].father_Profession<<","
			<< info[i].parents_Contact  <<","
			<<info[i].Fee_submitted     <<","
			<<info[i].Blood_Group       <<","
			<< info[i].Address;
//		cout << "\nThis student Data has been Successfully saved in the data base " << endl;
		cout << "Do you want to Enter another entery(y/n) : ";
		cin >> chk;
	} 
	while (chk == 'y' || chk == 'Y');
	std.close();
	system("pause");
	return;
}
