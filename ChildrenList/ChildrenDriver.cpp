
// ChildrenList.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include "Child.h"
#include "LinkedList.h"

int main()
{
	Child c1("Angie", "Ham", 7), c2("Pradnya", "Dhala", 8),
		c3("Bill", "Vollmann", 13), c4("Cesar", "Ruiz", 6);
	Child c5("Piqi", "Tangi", 7), c6("Pete", "Rose", 13),
		c7("Hank", "Aaron", 3), c8("Madison", "Fife", 7);
	Child c9("Miles", "Davis", 65), c10("John", "Zorn", 4), c11;
	LinkedList<Child> class1, class2, soccer, chess;
	int a = 1, b = -1, c = 13;
	//test insert
	class1.Insert(&c1);
	class1.Insert(&c2);
	class1.Insert(&c3);
	class1.Insert(&c4);
	class1.Insert(&c5);
	class1.Insert(&c6);
	class1.Insert(&c5);
	//test output
	cout << "class1: " << class1 << endl;
	if (class1.Insert(&c1))
	{
		cout << "ERROR::: Duplicate" << endl;
	}
	class2.Insert(&c4);
	class2.Insert(&c5);
	class2.Insert(&c6);
	class2.Insert(&c7);
	class2.Insert(&c10);
	cout << "Class2: " << class2 << endl;
	//test merge
	class1.Merge(class2);
	class2.Merge(class1);
	class1.Merge(class2);
	class1.Merge(class1);
	cout << "class1 and 2 Merged: " << class1 << endl;
	if (!class2.isEmpty())
	{
		cout << "ERROR:: Class2 should be empty empty" << endl;
	}

	//test remove
	class1.Remove(c4, c11);
	class1.Remove(c5, c11);
	class1.Remove(c11, c11);
	if (class1.Remove(c1, c11))
	{
		cout << "Removed from class1, student " << c11 << endl;
	}
	cout << "class1: " << class1 << endl;
	soccer.Insert(&c6);
	soccer.Insert(&c4);
	soccer.Insert(&c9);
	cout << "soccer: " << soccer << endl;
	//test +=
	soccer += class1;
	//check += deep copy
	class1.DeleteList();
	cout << "soccer += class1 : " << soccer << endl;
	//test constructor
	LinkedList<Child> football =  LinkedList<Child>();
	cout << football<<"football is null "<<endl;
	//test assignment deep copy
	football = soccer;
	//test list ==
	if (football == soccer)
	{
		cout << "football: " << football << endl;
	} 
	//test peek
	if (football.Peek(c6, c11))
	{
		cout << c11 << " is on the football team" << endl;
	}
	soccer.DeleteList();
	//test empty
	if (!soccer.isEmpty())
	{
		cout << "ERROR: soccer should be empty" << endl;
	}


	LinkedList<int> numbers;
	numbers.Insert(&a);
	numbers.Insert(&b);
	numbers.Insert(&c);
	cout << "These are the numbers: " << numbers << endl;
	numbers.DeleteList();




	// test deep copy after delete
	cout << "after delete soccer" << endl;
	cout << "football: " << football << endl;

	//test  a=  b+c
	class1.Insert(&c1);
	class1.Insert(&c2);
	class1.Insert(&c5);
	class2.Insert(&c5);
	class2.Insert(&c6);
	chess = class1 + class2;
	cout <<"chess = class1+class2: " <<chess << endl;;


	//test list !=

	if (class1 != class2)
	{
		cout << "class1 is not class2" << endl;
	}

	//test child constructor
	Child cc1 = Child();
	Child cc2 = Child("Bob", "Redman", 16);
	Child cc3 = Child("", "", 0);

	Child cc4 = Child("Bob", "Redmannn", 16);
	Child cc5 = Child("Bobbb", "Redman", 16);

	Child cc6 = Child("Bob", "Redman", 16);
	Child cc7 = Child("Bob", "Redman", 17);

	Child *cc8 = new Child("Kevin", "Unnoi", 12);
	Child *cc9 = new Child();
	//assignment
	*cc9 = *cc8;
	//test child accessor
	
	cout << cc1.getFirstName() << " " << cc1.getLastName() << " " << cc1.getAge()<<endl;
	cout << cc2.getFirstName() << " " << cc2.getLastName() << " " << cc2.getAge()<<endl;
	cout << cc2;
	//test child < > <= >=
	if (cc1 < cc2)
	{
		cout << "cc2 bigger"<<endl;
	}
	if (cc3 > cc2)
	{
		cout << "cc2 smaller"<<endl;
	}
	if (cc4 >= cc2)
	{
		cout << "cc4 bigger"<<endl;
	}
	if (cc5 <= cc2)
	{
		cout << "cc2 bigger" << endl;;
	}

	if (cc6 <= cc2)
	{
		cout << "cc6 smaller or equal" << endl;
	}
	if (cc6 == cc2)
	{
		cout << "cc6 equal" << endl;
	}

	if (cc1 != cc2)
	{
		cout << "cc1 is not cc2" << endl;
	}
	if (cc7 > cc2)
	{
		cout << "cc7  older" << endl;
	}

	if (*cc9 == *cc8)
	{
		cout << "cc9 is equal to cc8"<<endl;
	}
	delete cc8;
	cout << "cc9 still alive" << *cc9 << endl;


	//string test
	LinkedList<string> strs;
	string ABB = "ABB";
	string ABC = "ABC";
	string abc = "abc";
	string BAC = "BAC";
	strs.Insert(&ABC);
	strs.Insert(&ABB);
	strs.Insert(&abc);
	strs.Insert(&BAC);
	string ABB2;
	strs.Remove(ABB,ABB2);
	cout << strs;

	return 0;
}