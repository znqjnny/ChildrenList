#pragma once
#include <iostream>
#include <string>
using namespace std;

class Child
{

	friend ostream& operator<<(ostream& output, const Child &child);
public:
	//constructor

	Child();
	Child(string fName, string lName, int yearsOld);
	~Child();

	//operator overload
	bool operator< (const Child &child) const;
	bool operator> (const Child &child) const;
	bool operator<= (const Child &child) const;
	bool operator>= (const Child &child) const;
	bool operator== (const Child &child) const;
	bool operator!= (const Child &child) const;
	Child operator= (const Child &child);

	//accessor
	string getFirstName()const;
	void setFirstName(string name);

	string getLastName()const;

	void setLastName(string name);

	int getAge()const;

	void setAge(int yearsOld);

private:
	string firstName;
	string lastName;
	int age;
};