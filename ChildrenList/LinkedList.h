#pragma once


#include <iostream>
#include <vector>
#include "Child.h"
#ifndef LINKED_LIST_H
#define LINKED_LIST_H

using namespace std;


template <class ItemType>
class LinkedList
{
	//<< overload
	friend ostream& operator<<(ostream &outStream, const LinkedList& other)
	{
		Node *currNode;
		currNode = other.head;
		while (currNode != NULL)
		{
			outStream << *currNode->data;
			currNode = currNode->next;
		}
		return outStream;
	};
public:
	LinkedList();
	~LinkedList();



	// list head

	//Insert an object in the list in the correct place.Return true or false depending on whether the insert was successful.
	//Duplicates of an object are not allowed.
	//If there is a duplicate the function should return false.
	//Note that a pointer to the object is passed in but the Insert should create a copy of the object to keep in the list.
	bool Insert(ItemType *obj);

	//Remove the target item from the list.
	//Return the item using a second parameter that is passed in by reference.
	//If the item was found and removed return true, else return false.
	bool Remove(ItemType target, ItemType &result);

	//The same as Remove except the item is not removed from the list.Again, the second item is returned by reference.
	bool Peek(ItemType target, ItemType &result) const;

	//Is the list empty ?
	bool isEmpty() const;


	//Remove all items from the list.Deallocate all memory appropriately. 
	//This includes not only the nodes in the list but the items being pointed to by the nodes.
	void DeleteList();


	//Takes a sorted list and merges into the calling sorted list
	//(no new memory should be allocated).At termination of function, the list passed in(list1)
	//should be empty(unless it is the calling list).No duplicates are allowed.
	bool Merge(LinkedList &list1);



	//operator overload

	LinkedList operator+(const LinkedList &list) const;
	LinkedList operator+=(const LinkedList &list);
	bool operator==(const LinkedList &list) const;
	bool operator!=(const LinkedList &list);
	LinkedList operator=(const LinkedList &list);



private:
	struct Node
	{
		ItemType  *data;
		Node *next;
	};
	Node *head;

};

#include "LinkedList.cpp"
#endif




