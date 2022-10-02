#include<iostream>
#include<string>
#include"Person.h"
#include<string.h>
using namespace std;
void Person::setFirstName(string n)
{
	firstName = n;
}

string Person::getFirstName()
{
	return firstName;
}
void Person::setLastName(string m)
{
	lastName = m;
}

string Person::getLastName()
{
	return lastName;
}

void Person::setGender(char a)
{
	gender = a;
}

char Person::getGender()
{
	return gender;
}

void Person::setID(int id)
{
	ID = id;
}

int Person::getID()
{
	return ID;
}
