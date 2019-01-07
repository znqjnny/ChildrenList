#include "pch.h"
#ifndef LINKED_LIST_CPP
#define LINKED_LIST_CPP
#include "LinkedList.h"


template <class ItemType>
LinkedList<ItemType>::LinkedList()
{
	head = NULL;
}

template <class ItemType>
LinkedList<ItemType>::~LinkedList()
{
	//cout << "List delete" << endl;
}

template <class ItemType>
bool LinkedList<ItemType>::Insert(ItemType *obj)
{
	ItemType *newObj = new ItemType();
	*newObj = *obj;

	// check if head is null then set head data
	if (this->head == NULL)
	{
		Node *newNode = new Node;
		newNode->data = newObj;
		this->head = newNode;
		this->head->next = NULL;
		return true;
	}

	// check if small than head then replace head position
	Node * current = this->head;
	if (*newObj < *this->head->data)
	{
		Node *newNode = new Node;
		newNode->data = this->head->data;
		newNode->next = this->head->next;
		this->head->data = newObj;
		this->head->next = newNode;
		return true;
	}

	//check dulplicate
	while (current != NULL) {

		if (*current->data == *newObj)
			return false;
		current = current->next;

	}

	current = this->head;

	// insert middle
	while (current->next != NULL)
	{
		if (*newObj >= *current->data && *newObj < *current->next->data)
		{

			Node * newNode;
			newNode = new Node;
			newNode->data = newObj;
			newNode->next = current->next;
			current->next = newNode;
			return true;
		}

		current = current->next;
	}


	// insert last position


	current = this->head;

	while (current->next != NULL)
	{
		current = current->next;
	}
	Node * newNode;
	newNode = new Node();
	newNode->data = newObj;
	newNode->next = NULL;
	current->next = newNode;


	return false;
}

template <class ItemType>
bool LinkedList<ItemType>::Remove(ItemType target, ItemType &result)
{
	//if removing head node
	if (*this->head->data == target)
	{
		delete this->head->data;
		this->head = head->next;
		return true;
	}
	Node *current = this->head->next;
	Node *lastNode = this->head;

	//continue with  head's next node
	while (current != NULL)
	{


		if (*current->data == target)
		{
			lastNode->next = current->next;
			result = *current->data;
			delete current->data;
			delete current;

			return true;
		}
		lastNode = current;
		current = current->next;
	}

	return false;
}


template <class ItemType>
bool LinkedList<ItemType>::Peek(ItemType target, ItemType &result) const
{

	if (*this->head->data == target)
	{
		delete head;
		return true;
	}
	Node *current = this->head->next;
	Node *lastNode = this->head;

	//continue with  head's next node
	while (current != NULL)
	{


		if (*current->data == target)
		{
			lastNode->next = current->next;
			result = *current->data;
			delete current;

			return true;
		}
		lastNode = current;
		current = current->next;
	}

	return true;
}

template <class ItemType>
bool LinkedList<ItemType>::isEmpty() const
{
	if (this->head == NULL)
		return true;
	return false;
}

template <class ItemType>
void LinkedList<ItemType>::DeleteList()
{
	Node * temp = head;
	while (temp != NULL)
	{
		head = head->next;
		delete temp->data;
		delete temp;
		temp = head;
	}
}

template <class ItemType>
bool LinkedList<ItemType>::Merge(LinkedList &list1)
{
	if (this == &list1)
	{
		return false;
	}
	if (list1.head == NULL)
	{
		return false;
	}
	Node* curr = list1.head;
	while (curr != NULL)
	{
		ItemType *item = new ItemType;
		*item = *(curr->data);
		Insert(item);
		curr = curr->next;
	}
	list1.DeleteList();
	return true;
}




template <class ItemType>
LinkedList<ItemType> LinkedList<ItemType>::operator+(const LinkedList &list) const
{
	LinkedList temp = *this;
	temp += list;
	return temp;
}


template <class ItemType>
LinkedList<ItemType> LinkedList<ItemType>::operator+=(const LinkedList &list)
{
	Node* curThis = this->head;
	Node* curPara = list.head;
	if (this->head == NULL)
	{

		while (curPara != NULL)
		{
			this->Insert(curPara->data);
			curPara = curPara->next;
		}
	}
	else 
	{
		if (*this != list)
		{
			while (curThis != NULL)
			{

				while (1)
				{
					bool ifSwitch = false;
					if (*curPara->data >= *curThis->data && curThis->next == NULL)
					{
						ifSwitch = true;
					}
					// replace this head
					else if (*curPara->data < *curThis->data)
					{
						ItemType *newObj = new ItemType;
						*newObj = *this->head->data;

						Node *newNode = new Node();
						newNode->data = newObj;
						newNode->next = this->head->next;
						ItemType *paraObj = new ItemType;
						*paraObj = *curPara->data;

						this->head->data = paraObj;
						this->head->next = newNode;
						ifSwitch = false;
						curThis = curThis->next;
						curPara = curPara->next;

					}
					else if (*curPara->data >= *curThis->data && *curPara->data < *curThis->next->data)
					{
						ifSwitch = true;
					}
					else
					{
						break;
					}
					if (ifSwitch)
					{

						if (*curPara->data == *curThis->data)
						{
							curPara = curPara->next;
						}
						else
						{
							Node *newNode = new Node();
							ItemType *newObj = new ItemType;
							*newObj = *curPara->data;


							newNode->data = newObj;
							newNode->next = curThis->next;
							curThis->next = newNode;

							curThis = curThis->next;
							curPara = curPara->next;
						}
						if (curPara == NULL)
							break;
					}
				}
				curThis = curThis->next;
			}
		}
	}
	return *this;
}

template <class ItemType>
bool LinkedList<ItemType>::operator==(const LinkedList &list) const
{
	Node* curThis = this->head;
	Node* curPara = list.head;
	while (curThis != NULL || curPara != NULL)
	{
		if (curThis->data != curPara->data)
			return false;
		curThis = curThis->next;
		curPara = curPara->next;
	}
	return true;
}

template <class ItemType>
bool LinkedList<ItemType>::operator!=(const LinkedList &list)
{

	Node* curThis = this->head;
	Node* curPara = list.head;
	while (curThis != NULL || curPara != NULL)
	{
		if (curThis->data != curPara->data)
			return true;
		curThis = curThis->next;
		curPara = curPara->next;
	}
	return false;
}

template <class ItemType>
LinkedList<ItemType> LinkedList<ItemType>::operator=(const LinkedList &list)
{
	//insert the data to curlist in order to have a deep copy
	Node* curPara = list.head;

	while (curPara != NULL)
	{
		this->Insert(curPara->data);
		curPara = curPara->next;
	}

	return *this;
}



#endif