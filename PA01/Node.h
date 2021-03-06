// Class Header File Information //////////////////////////////////////////////
/**
  * @file Node.h
  *
  * @brief Definition file for Node class
  *
  * @author Alex Kastanek
  *
  * @details Specifies all member methods of the Node class
  *
  * @version 1.00
  *  		 C.S. Student (14 September 2016)
  *			 Initial development and testing of Node class
  *
  * @note Adapted from Frank M. Carrano and Timothy M. Henry Copyright (c) 0217
  *       Pearson Education, Hoboken, New Jersey.
  *
  */

#ifndef NODE_
#define NODE_

using namespace std;

#include <iostream>

template<class ItemType>
class Node
{
private:
	ItemType item;
	Node<ItemType>* next;
public:
	Node();
	Node(const ItemType& anItem);
	Node(const ItemType& anItem, Node<ItemType>* nextNodePtr);
	void setItem(const ItemType& anItem);
	void setNext(Node<ItemType>* nextNodePtr);
	ItemType getItem() const;
	Node<ItemType>* getNext() const;
};
#endif
