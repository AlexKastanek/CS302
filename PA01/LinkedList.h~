// Class Header File Information //////////////////////////////////////////////
/**
  * @file LinkedList.h
  *
  * @brief Definition file for LinkedList class
  *
  * @author Alex Kastanek
  *
  * @details Specifies all member methods of the LinkedList class
  *
  * @version 1.00
  *  		 C.S. Student (14 September 2016)
  *			 Initial development and testing of LinkedList class
  *
  * @note Adapted from Frank M. Carrano and Timothy M. Henry Copyright (c) 0217
  *       Pearson Education, Hoboken, New Jersey.
  *
  */

#ifndef LINKED_LIST_
#define LINKED_LIST_

//using namespace std;

//#include <iostream>
#include "ListInterface.h"
#include "Node.h"
#include "PrecondViolatedExcept.h"

template<class ItemType>
class LinkedList : public ListInterface<ItemType>
{
private:
	Node<ItemType>* headPtr;

	int itemCount;

	Node<ItemType>* getNodeAt(int position) const;

public:
	LinkedList();
	virtual ~LinkedList();

	bool isEmpty() const;
	int getLength() const;
	bool insert(int newPosition, const ItemType& newEntry);
	bool remove(int position);
	void clear();

	ItemType getEntry(int position) const throw(PrecondViolatedExcept);

	ItemType replace(int position, const ItemType& newEntry) throw(PrecondViolatedExcept);
};
#endif
