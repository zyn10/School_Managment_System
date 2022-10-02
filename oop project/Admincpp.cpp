#include<iostream>
#include<string>
#include<string.h>
#include<fstream>
#include"Admin.h"
using namespace std;
bool Admin:: isLogin()	  // ----> Function for authenticating the admin login through saved credentials in a file.
{
	system("cls");
	Admin data[3];					// ----> Structure Array for storing the read data from the file				
	admin.open("Admin_logs.txt");	// ----> Opening the file for reading
	for (int i = 0; i < 3; i++)
	{
		admin >> data[i].ad_name;
		admin >> data[i].ad_pw;

	}

	login = false;
	cin.ignore();
	cout << " Enter the name of admin: "; // ----> taking input for credentials
	getline(cin, adm_name);
	cout << " Enter the admin password: ";
	getline(cin, adm_pw);
	for (int i = 0; i < 3; i++)
	{
		if (adm_name == data[i].ad_name && adm_pw == data[i].ad_pw)  // ----> checking for password and user name match
		{
			cout << "\n\n You are successfully logged in ADMIN mode \n\n";
			login = true;
		}
	}
	admin.close();
	return login;	// ----> returning the login value to the function
}
bool Admin::isLoginTry()
{
	cout << endl << " Wrong Ussername or Password  Entered!!!!!\n\n" << endl;
	log = false;
	cout << " Do you want to choose another choice ? (y/n)    ";
	cin >> try_top;					// ----> string input for decision
	if (try_top == "y" || try_top == "Y")
	{
		system("cls");
		if (isLogin() == 1)
		{
			log = true;
			system("pause");
			return log;
		}
		else
		{
			isLoginTry();
		}

	}
	else if (try_top == "n" || try_top == "N")
	{
		system("pause");
		exit(0);
	}
	else
	{
		cout << endl << endl << " Wrong choice entered!! The system is exiting due to the wrong format used in admin login. " << endl << endl;
		system("pause");
		exit(0);
	}
	return log;

}
