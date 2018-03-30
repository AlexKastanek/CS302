// Class Implemntation File Information ///////////////////////////////////////
/**
  * @file LinkedList.cpp
  *
  * @brief Implementation file for LinkedList class
  *
  * @author Alex Kastanek
  *
  * @details Implements all member methods of the LinkedList class
  *
  * @version 1.00
  *  		 C.S. Student (14 September 2016)
  *			 Initial development and testing of LinkedList class
  *
  * @note Requires LinkedList.h
  *
  * @note Adapted from Frank M. Carrano and Timothy M. Henry Copyright (c) 0217
  *       Pearson Education, Hoboken, New Jersey.
  *
  */

#include "LinkedList.h"

/**
  * @brief Function finds a node at a given position and return the pointer to
  * 	   that node
  *
  * @details Function points to the head pointer and searches through the list
  *			 until the specified position is reached and then returns the node
  *			 in that position
  *
  * @pre Node<ItemType>* curPtr is intialized to headPtr
  *
  * @pre int current is intialized to 1
  *
  * @post headPtr and position are not changed
  * 
  * @post curPtr gets the node at position
  * 
  * @post current gets position - 1
  * 
  * @par Algorithm
  *		 curPtr is calculated through a for loop that goes until current is
  *      equal to position - 1. At this point curPtr gets the Node that is 
  *      stored in its next
  *
  * @param[in] position
  *            holds the specified position in the LinkedList of the Node
  *
  * @param[out] None
  *
  * @return curPtr
  *
  * @note: None
  */

template<class ItemType>
Node<ItemType>* LinkedList<ItemType>::getNodeAt(int position) const
{
	//different from TB: not debugging check of precondition
	Node<ItemType>* curPtr = headPtr;
	for (int current = 1; current < position; current++)
		curPtr = curPtr->getNext();

	return curPtr;
}

/**
  * @brief Constructor for class LinkedList
  *
  * @details Able to construct a LinkedList object with Node<ItemType>*
  *          headPtr and int itemCount
  *
  * @pre Node<ItemType>* headPtr is intialized to NULL
  *
  * @pre int itemCount is intialized to 0
  *
  * @post headPtr and itemCount are not changed
  *
  * @note: None
  */

template<class ItemType>
LinkedList<ItemType>::LinkedList() : headPtr(NULL), itemCount(0)
{
}

/**
  * @brief Destructor for class LinkedList
  *
  * @details Able to destruct a LinkedList object by using clear()
  *
  * @note: None
  */

template<class ItemType>
LinkedList<ItemType>::~LinkedList()
{
	clear();
}

/**
  * @brief Function checks if LinkedList is empty
  *
  * @details Function returns 0 if LinkedList is not empty and 1 if LinkedKist
  *          is empty
  *
  * @pre itemCount contains some value depending on if there are any Nodes in
  *      the LinkedList
  *
  * @post itemCount is not changed
  * 
  * @par Algorithm
  *		 itemCount == 0 will return a 1 if this is true or a 0 if it is false
  *
  * @param[in] None
  *
  * @param[out] None
  *
  * @return itemCount
  *
  * @note: None
  */

template<class ItemType>
bool LinkedList<ItemType>::isEmpty() const
{
	return itemCount == 0;
}

/**
  * @brief Function gets the itemCount of the Linked List
  *
  * @details Function returns the length of the LinkedList by returning
  *          itemCount
  *
  * @pre itemCount contains some value
  *
  * @post itemCount is not changed
  * 
  * @par None
  *
  * @param[in] None
  *
  * @param[out] None
  *
  * @return itemCount
  *
  * @note: None
  */

template<class ItemType>
int LinkedList<ItemType>::getLength() const
{
	return itemCount;
}

/**
  * @brief Function inserts a Node in a LinkedList
  *
  * @details Function inserts a Node in a LinkedList using a specified
  *          position and entry that the Node will contain
  *
  * @pre int newPosition is initialized to some specified value
  *
  * @pre const ItemType& newEntry is initialized to some specified value
  *
  * @pre Node<ItemType>* newNodePtr is initialized to the value contained in 
  *      newEntry
  * 
  * @pre Node<ItemType>* prevPtr is initalized to the Node at position - 1
  *
  * @post newPosition and newEntry are not changed
  *
  * @post itemCount is incremented by one
  * 
  * @post newNodePtr's next value is either what headPtr used to be or what
  *       prevPtr used to be depending on the position
  * 
  * @post if the position is not equal to one, prevPtr's next value is now
  *       newNodePtr, otherwise headPtr is now equal to newNodePtr
  * 
  * @par Algorithm
  *		 newNodePtr is created containing the value newEntry. It is then
  *      inserted into the LinkedList. If the insertion position is 1, then
  *      newNodePtr is inserted before headPtr, otherwise it is inserted
  *      after prevPtr
  *
  * @param[in] newPosition
  *            holds the specified new position in the LinkedList of the Node
  *
  * @param[in] newEntry
  *            holds the new data that will be constained in newNodePtr
  *
  * @param[out] newEntry
  *             no changes made to newEntry, but its value is passed by
  *             reference
  *
  * @return ableToInsert
  *         checks if newPosition is within the valid range
  *
  * @note: None
  */

template<class ItemType>
bool LinkedList<ItemType>::insert(int newPosition, const ItemType& newEntry)
{
	bool ableToInsert = (newPosition >= 1) && (newPosition <= itemCount + 1);
	if (ableToInsert)
	{
		Node<ItemType>* newNodePtr = new Node<ItemType>(newEntry);

		if (newPosition == 1)
		{
			newNodePtr->setNext(headPtr);
			headPtr = newNodePtr;
		}
		else
		{
			Node<ItemType>* prevPtr = getNodeAt(newPosition - 1);

			newNodePtr->setNext(prevPtr->getNext());
			prevPtr->setNext(newNodePtr);
		}
		itemCount++;
	}
	return ableToInsert;
}

/**
  * @brief Function removes a Node from a LinkedList
  *
  * @details Function removes a Node from a LinkedList using a specified
  *          position
  *
  * @pre int position is initialized to some specified value
  *
  * @pre Node<ItemType>* curPtr is initialized to NULL
  * 
  * @pre Node<ItemType>* prevPtr is initalized to the Node at position - 1
  *
  * @post newPosition is not changed
  * 
  * @post itemCount is decremented by one
  * 
  * @post if the position is not equal to one, prevPtr's next value is now
  *       curPtr's next Node, otherwise headPtr is now equal to its next Node
  * 
  * @par Algorithm
  *		 curPtr is set to NULL. If the position of the Node to be removed is 1
  *      then curPtr takes the value of headPtr, and headPtr takes the value of
  *      its next node. Otherwise, curPtr takes the value of prevPtr's next,
  *      and prevPtr's next takes the value of curPtr's next. curPtr is then
  *      reset at the end of the algorithm, deleted, and pointing to NULL
  *
  * @param[in] position
  *            holds the specified position in the LinkedList of the Node
  *
  * @param[out] None
  *
  * @return ableToInsert
  *         checks if newPosition is within the valid range
  *
  * @note: None
  */

template<class ItemType>
bool LinkedList<ItemType>::remove(int position)
{
	bool ableToRemove = (position >= 1) && (position <= itemCount);
	if (ableToRemove)
	{
		Node<ItemType>* curPtr = NULL;
		if (position == 1)
		{
			curPtr = headPtr;
			headPtr = headPtr->getNext();
		}
		else
		{
			Node<ItemType>* prevPtr = getNodeAt(position - 1);
			curPtr = prevPtr->getNext();
			prevPtr->setNext(curPtr->getNext());
		}
		curPtr->setNext(NULL);
		delete curPtr;
		curPtr = NULL;

		itemCount--;
	}
	return ableToRemove;
}

/**
  * @brief Function clears the LinkedList
  *
  * @details Function clears the LinkedList using the isEmpty function and the
  *          remove function
  *
  * @pre None
  *
  * @post None
  * 
  * @par Algorithm
  *		 Function uses a while loop that removes each node until isEmtpy()
  *      returns true
  *
  * @param[in] None
  *
  * @param[out] None
  *
  * @return None
  *
  * @note: None
  */

template<class ItemType>
void LinkedList<ItemType>::clear()
{
	while (!isEmpty())
		remove(1);
}

/**
  * @brief Function finds a node at a given position and return the item stored
  * 	   in that node
  *
  * @details Function points to the head pointer and searches through the list
  *			 until the specified position is reached and then returns the item
  *			 of the Node in that position
  *
  * @pre Node<ItemType>* nodePtr is intialized to Node at specified position
  *
  * @pre int position is intialized some specified value
  *
  * @post nodePtr and position are not changed
  * 
  * @post curPtr gets the node at position
  * 
  * @par Algorithm
  *		 nodePtr is equal to the Node at position and the item in that node is
  *      returned
  *
  * @param[in] position
  *            holds the specified position in the LinkedList of the Node
  *
  * @param[out] None
  *
  * @return nodePtr->getItem()
  *
  * @note: None
  */

template<class ItemType>
ItemType LinkedList<ItemType>::getEntry(int position) const throw(PrecondViolatedExcept)
{
	bool ableToGet = (position >= 1) && (position <= itemCount);
	if (ableToGet)
	{
		Node<ItemType>* nodePtr = getNodeAt(position);
		return nodePtr->getItem();
	}
	else
	{
		std::string message = "getEntry() called with an empty list or ";
		message = message + "invalid position.";
		throw(PrecondViolatedExcept(message));
	}
}

/**
  * @brief Function finds a node at a given position and replaces that Node's
  *        data with another entry
  *
  * @details Function points to the head pointer and searches through the list
  *			 until the specified position is reached and then replaces the data
  *          of the Node in that position with newEntry
  *
  * @pre const ItemType& newEntry is initaialized to some specified value
  *
  * @pre int position is intialized to some specified value
  *
  * @pre nodePtr is initialized to the Node at position
  *
  * @pre replacedItem is initalized to nodePtr's item
  *
  * @post none
  * 
  * @par Algorithm
  *		 Function uses remove() and insert() to replace the Node at position
  *
  * @param[in] position
  *            holds the specified position in the LinkedList of the Node
  *
  * @param[in] newEntry
  *            holds the data that will be stored in the new Node
  *
  * @param[out] None
  *
  * @return replacedItem
  *
  * @note: None
  */

template<class ItemType>
ItemType LinkedList<ItemType>::replace(int position, const ItemType& newEntry) throw(PrecondViolatedExcept)
{
	Node<ItemType>* nodePtr = getNodeAt(position);
	ItemType replacedItem = nodePtr->getItem();

	remove(position);

	insert(position, newEntry);

	return replacedItem;
}
