// Class Implemntation File Information ///////////////////////////////////////
/**
  * @file Node.cpp
  *
  * @brief Implementation file for Node class
  *
  * @author Alex Kastanek
  *
  * @details Implements all member methods of the Node class
  *
  * @version 1.00
  *  		 C.S. Student (14 September 2016)
  *			 Initial development and testing of Node class
  *
  * @note Requires Node.h
  *
  * @note Adapted from Frank M. Carrano and Timothy M. Henry Copyright (c) 0217
  *       Pearson Education, Hoboken, New Jersey.
  *
  */

#include "Node.h"

template<class ItemType>
Node<ItemType>::Node() : next(NULL)
{
}

template<class ItemType>
Node<ItemType>::Node(const ItemType& anItem) : item(anItem), next(NULL)
{
}

template<class ItemType>
Node<ItemType>::Node(const ItemType& anItem, Node<ItemType>* nextNodePtr) : item(anItem), next(nextNodePtr)
{
}

template<class ItemType>
void Node<ItemType>::setItem(const ItemType& anItem)
{
	item = anItem;
}

template<class ItemType>
void Node<ItemType>::setNext(Node<ItemType>* nextNodePtr)
{
	next = nextNodePtr;
}

template<class ItemType>
ItemType Node<ItemType>::getItem() const
{
	return item;
}

template<class ItemType>
Node<ItemType>* Node<ItemType>::getNext() const
{
	return next;
}
