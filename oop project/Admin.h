#define ADMIN_H_INCLUDED
#include<iostream>
#include<string>
#include<fstream>
#include"Student.h"
using namespace std;
class Admin
{
private:
	string ad_name;				// ----> admin names
	string ad_pw;				// ----> admin passwords
	string adm_name;									// ----> strings to hold input credentials 
	string adm_pw;
	string try_top;
	ifstream admin;
	bool login;
	bool log;
public:
	void menu();
	bool isLogin();
	bool isLoginTry();

};