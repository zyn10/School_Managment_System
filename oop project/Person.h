#define PERSON_HEADER
#include<iostream>
#include<string>
using namespace std;
class Person
 {
protected:
	string firstName;
	string lastName;
	char gender;
	int ID;
public:
	void setFirstName(string n);
	void setLastName (string m);
	void setID(int id);
	void setGender(char malefemale);
	int  getID();
	string getFirstName();
	string getLastName();
	char  getGender();
	
	virtual void add() = 0;
	//virtual void del() = 0;
	//virtual void show() = 0;
	//virtual void update() = 0;
	//virtual void search() = 0;
};

