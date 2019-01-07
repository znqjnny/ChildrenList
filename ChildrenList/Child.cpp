#include "pch.h"
#include "Child.h"

Child::Child()
{
	firstName = "John";
	lastName = "Doe";
	age = 0;
}
Child::Child(string fName, string lName, int yearsOld)
{
	firstName = fName;
	lastName = lName;
	age = yearsOld;
}
Child::~Child()
{
	//	cout << "Child delete." << endl;
}

//operator overload
ostream& operator<<(ostream& output, const Child &child)
{
	output << child.firstName << child.lastName << child.age;
	return output;
}

bool Child::operator<(const Child &child) const
{
	string lName1 = this->lastName;
	string lName2 = child.lastName;
	string fName1 = this->firstName;
	string fName2 = child.firstName;
	int age1 = this->age;
	int age2 = child.age;


	if (*this == child)
		return false;
	// compare lastname
	if (lName1 != lName2)
	{
		for (int i = 0; i < lName1.length(); i++)
		{
			if ((i + 1) > lName2.length())
			{
				return false;
			}
			if (lName1[i] < lName2[i])
			{
				return true;
			}
			if (lName1[i] > lName2[i])
			{
				return false;
			}
		}
	}
	// compare firstname
	if (fName1 != fName2)
	{
		for (int i = 0; i < fName1.length(); i++)
		{
			if ((i + 1) > fName2.length())
			{
				return false;
			}
			if (fName1[i] < fName2[i])
			{
				return true;
			}
			if (fName1[i] > fName2[i])
			{
				return false;
			}
		}
	}
	// compare age
	if (age1 < age2)
	{
		return true;
	}
	return false;
}


bool Child::operator>(const Child &child) const
{
	string lName1 = this->lastName;
	string lName2 = child.lastName;
	string fName1 = this->firstName;
	string fName2 = child.firstName;
	int age1 = this->age;
	int age2 = child.age;


	if (*this == child)
		return false;

	// compare lastname
	if (lName1 != lName2)
	{
		for (int i = 0; i < lName1.length(); i++)
		{
			if ((i + 1) > lName2.length())
			{
				return true;
			}
			if (lName1[i] < lName2[i])
			{
				return false;
			}
			if (lName1[i] > lName2[i])
			{
				return true;
			}
		}
	}

	// compare firstname
	if (fName1 != fName2)
	{
		for (int i = 0; i < fName1.length(); i++)
		{
			if ((i + 1) > fName2.length())
			{
				return true;
			}
			if (fName1[i] < fName2[i])
			{
				return false;
			}
			if (fName1[i] > fName2[i])
			{
				return true;
			}
		}
	}
	// compare age
	if (age1 < age2)
	{
		return false;
	}
	return true;
}


bool Child::operator<=(const Child &child) const
{
	string lName1 = this->lastName;
	string lName2 = child.lastName;
	string fName1 = this->firstName;
	string fName2 = child.firstName;
	int age1 = this->age;
	int age2 = child.age;


	if (*this == child)
		return true;
	// compare lastname
	if (lName1 != lName2)
	{

		for (int i = 0; i < lName1.length(); i++)
		{
			if ((i + 1) > lName2.length())
			{
				return false;
			}
			if (lName1[i] < lName2[i])
			{
				return true;
			}
			if (lName1[i] > lName2[i])
			{
				return false;
			}
		}
	}

	// compare firstname
	if (fName1 != fName2)
	{

		for (int i = 0; i < fName1.length(); i++)
		{
			if ((i + 1) > fName2.length())
			{
				return false;
			}
			if (fName1[i] < fName2[i])
			{
				return true;
			}
			if (fName1[i] > fName2[i])
			{
				return false;
			}
		}
	}
	// compare age
	if (age1 <= age2)
	{
		return true;
	}
	return false;
}


bool Child::operator>=(const Child &child) const
{
	string lName1 = this->lastName;
	string lName2 = child.lastName;
	string fName1 = this->firstName;
	string fName2 = child.firstName;
	int age1 = this->age;
	int age2 = child.age;


	if (*this == child)
		return true;

	// compare lastname
	if (lName1 == lName2)
	{
		return true;
	}
	for (int i = 0; i < lName1.length(); i++)
	{
		if ((i + 1) > lName2.length())
		{
			return true;
		}
		if (lName1[i] < lName2[i])
		{
			return false;
		}
		if (lName1[i] > lName2[i])
		{
			return true;
		}
	}

	// compare firstname
	if (fName1 == fName2)
	{
		return true;
	}
	for (int i = 0; i < fName1.length(); i++)
	{
		if ((i + 1) > fName2.length())
		{
			return true;
		}
		if (fName1[i] < fName2[i])
		{
			return false;
		}
		if (fName1[i] > fName2[i])
		{
			return true;
		}
	}
	// compare age
	if (age1 >= age2)
	{
		return true;
	}
	return false;
}


bool Child::operator==(const Child &child) const
{
	string lName1 = this->lastName;
	string lName2 = child.lastName;
	string fName1 = this->firstName;
	string fName2 = child.firstName;
	int age1 = this->age;
	int age2 = child.age;
	if ((lName1 == lName2 && fName1 == fName2) && age1 == age2)
	{
		return true;
	}
	return false;
}


bool Child::operator!=(const Child &child) const
{
	string lName1 = this->lastName;
	string lName2 = child.lastName;
	string fName1 = this->firstName;
	string fName2 = child.firstName;
	int age1 = this->age;
	int age2 = child.age;
	if ((lName1 != lName2 || fName1 == fName2) || age1 == age2)
	{
		return true;
	}
	return false;
}


Child Child::operator= (const Child &child)
{
	this->firstName = child.getFirstName();
	this->lastName = child.getLastName();
	this->age = child.getAge();

	return *this;
}


//accessor
string Child::getFirstName()const
{
	return firstName;
}
void Child::setFirstName(string name)
{
	firstName = name;
}
string Child::getLastName()const
{
	return lastName;
}
void Child::setLastName(string name)
{
	lastName = name;
}
int Child::getAge()const
{
	return age;
}
void Child::setAge(int yearsOld)
{
	age = yearsOld;
}
