#ifndef Contactinfo_H_INCLUDED
#define Contactinfo_H_INCLUDED
#include<iostream>
#include<string>
using namespace std;
class Crdentials
{
protected:
string phone_no;
	string email;
public:
	void set_phone_no(string);
	void set_email(string);
	string get_phone_no();
	string get_email();
};

void Crdentials::set_phone_no(string p)
{
	phone_no = p;
}
void Crdentials::set_email(string e)
{
	email = e;
}
string Crdentials::get_phone_no()
{
	return phone_no;
}
string Crdentials::get_email()
{
	return email;
}

#endif 
