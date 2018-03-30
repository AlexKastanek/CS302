// Class Implemntation File Information ///////////////////////////////////////
/**
  * @file LinkedListQueue.cpp
  *
  * @brief Implementation file for LinkedListQueue class
  *
  * @author Alex Kastanek
  *
  * @details Implements all member methods of the LinkedListQueue class
  *
  * @version 1.00
  *  		 C.S. Student (15 November 2016)
  *			 Initial development and testing of LinkedListQueue class
  *
  * @note This class is derived from one I made last semester (Spring 2016).
  *		  Any formatting inconsistencies are because of this.
  *
  */

#ifndef LINKED_LIST_QUEUE
#define LINKED_LIST_QUEUE

#include <iostream>
#include <fstream>
#include <string>
#include "Event.h"
#include "Customer.h"

using namespace std;

template <class ItemType>
struct Node
{

	ItemType data;
	Node<ItemType>* next;

};

template <class ItemType>
class LinkedListQueue
{

	public:
		LinkedListQueue();
		~LinkedListQueue();
		
		bool isEmpty() const;
		bool isFull() const;
		bool clear();
		int getLength() const;
		bool enqueue(ItemType);
		bool dequeue(ItemType&);
		bool peekFront(ItemType&) const;
		void print() const;
		void printToFile(char*, bool) const;

	private:
		Node<ItemType>* front;
		Node<ItemType>* rear;

};

/**
  * @brief Constructor for class Queue
  *
  * @details Able to construct a Queue object
  *
  * @pre None
  *
  * @post None
  *
  * @par None
  *
  * @param None
  *
  * @exception None
  *
  * @note: None
  */
template <class ItemType>
LinkedListQueue<ItemType>::LinkedListQueue()
{

	front = NULL;
	rear = NULL;

}

/**
  * @brief Destructor for class Queue
  *
  * @details Able to destruct a Queue object
  *
  * @pre None
  *
  * @post None
  *
  * @par None
  *
  * @param None
  *
  * @exception None
  *
  * @note: None
  */
template <class ItemType>
LinkedListQueue<ItemType>::~LinkedListQueue()
{

	clear();

}

/**
  * @brief Determines if queue is empty
  *
  * @details Determines if queue is empty, returns true if so
  *
  * @pre None
  *
  * @post None
  *
  * @par Algorithm
  *		 Checks if front is equal to rear, returns true if so, returns false if
  *		 it is not
  *
  * @param None
  *
  * @exception None
  *
  * @note: None
  */
template <class ItemType>
bool LinkedListQueue<ItemType>::isEmpty() const
{

	if (front == NULL)
	{
		return true;
	}
	else
	{
		return false;
	}

}

/**
  * @brief Determines if queue is full
  *
  * @details Determines if queue is full, returns true if so
  *
  * @pre None
  *
  * @post None
  *
  * @par Algorithm
  *		 Checks if front is equal to rear - max, returns true if so, returns
  *		 false if it is not
  *
  * @param None
  *
  * @exception None
  *
  * @note: None
  */
template <class ItemType>
bool LinkedListQueue<ItemType>::isFull() const
{

	return false;

}

/**
  * @brief Clears the queue
  *
  * @details Clears all items from the queue
  *
  * @pre None
  *
  * @post None
  *
  * @par Algorithm
  *		 Goes through the queue and clears all items
  *
  * @param None
  *
  * @exception None
  *
  * @note: None
  */
template <class ItemType>
bool LinkedListQueue<ItemType>::clear()
{

	Node<ItemType>* temp;

	while (front != NULL)
	{
		temp = front;
		front = front->next;
		delete temp;
	}

	front = NULL;
	rear = NULL;

}

/**
  * @brief Gets length of queue
  *
  * @details Returns rear - front
  *
  * @pre None
  *
  * @post None
  *
  * @par None
  *
  * @param None
  *
  * @exception None
  *
  * @note: None
  */
template <class ItemType>
int LinkedListQueue<ItemType>::getLength() const
{

	if (isEmpty())
	{
		return 0;
	}

	Node<ItemType>* cursor = front;
	int count = 0;

	while (cursor != NULL)
	{

		cursor = cursor->next;
		count++;

	}

	delete cursor;
	return count;

}

/**
  * @brief Enqueues an item onto the queue
  *
  * @details Enqueues an item onto the rear of the queue
  *
  * @pre None
  *
  * @post None
  *
  * @par Algorithm
  *		 Places item after rear and sets rear to new item
  *
  * @param item
  *
  * @exception None
  *
  * @note: None
  */
template <class ItemType>
bool LinkedListQueue<ItemType>::enqueue(ItemType item)
{

	if (isFull())
	{
		return false;
	}

	Node<ItemType>* temp = new Node<ItemType>();
	temp->data = item;
	temp->next = NULL;

	if (front == NULL)
	{
		front = temp;
		rear = temp;
	}
	else
	{
		rear->next = temp;
		rear = temp;
	}

	return true;

}

/**
  * @brief Dequeues an item from the queue
  *
  * @details Dequeues an item from the front of the queue
  *
  * @pre None
  *
  * @post None
  *
  * @par Algorithm
  *		 Deletes item front was holding, and sets front to next item in queue
  *
  * @param item
  *
  * @exception None
  *
  * @note: None
  */
template <class ItemType>
bool LinkedListQueue<ItemType>::dequeue(ItemType& item)
{

	if (isEmpty())
	{
		return false;
	}

	item = front->data;

	Node<ItemType>* temp = front;
	front = front->next;
	delete temp;

	if (isEmpty())
	{
		front = NULL;
		rear = NULL;
	}

	return true;

}

/**
  * @brief Returns front of queue
  *
  * @details None
  *
  * @pre None
  *
  * @post None
  *
  * @par None
  *
  * @param None
  *
  * @exception None
  *
  * @note: None
  */
template <class ItemType>
bool LinkedListQueue<ItemType>::peekFront(ItemType& item) const
{

	if (isEmpty())
	{
		return false;
	}

	item = front->data;

	return true;

}

/**
  * @brief Prints the queue
  *
  * @details Prints the queue to screen
  *
  * @pre None
  *
  * @post None
  *
  * @par Algorithm
  *		 Goes through the queue and prints out each item to screen
  *
  * @param None
  *
  * @exception None
  *
  * @note: None
  */
template <class ItemType>
void LinkedListQueue<ItemType>::print() const
{

	if (isEmpty())
	{
		return;
	}

	Node<ItemType>* cursor = front;

	while (cursor != NULL)
	{

		cout << cursor->data << endl;
		cursor = cursor->next;

	}

	delete cursor;

}

/**
  * @brief Prints the queue
  *
  * @details Prints the queue to a file
  *
  * @pre None
  *
  * @post None
  *
  * @par Algorithm
  *		 Goes through the queue and prints out each item to a file
  *
  * @param None
  *
  * @exception None
  *
  * @note: None
  */
template <class ItemType>
void LinkedListQueue<ItemType>::printToFile(char* fileName, bool append) const
{

	if (isEmpty())
	{
		return;
	}

	ofstream fout;
	Node<ItemType>* cursor = front;

	if (!append)
	{
		fout.open(fileName);
	
		while (cursor != NULL)
		{	
			fout << cursor->data;
			cursor = cursor->next;	
		}

		fout.close();
	} 
	else
	{
		fout.open(fileName, ios_base::app);
	
		while (cursor != NULL)
		{	
			fout << cursor->data;
			cursor = cursor->next;	
		}

		fout.close();
	}

	delete cursor;

}

#endif

































