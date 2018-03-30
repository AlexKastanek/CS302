// Class Implemntation File Information ///////////////////////////////////////
/**
  * @file Queue.cpp
  *
  * @brief Implementation file for Queue class
  *
  * @author Alex Kastanek
  *
  * @details Implements all member methods of the Queue class
  *
  * @version 1.00
  *  		 C.S. Student (15 November 2016)
  *			 Initial development and testing of Queue class
  *
  * @note This class is derived from one I made last semester (Spring 2016).
  *		  Any formatting inconsistencies are because of this.
  *
  */

#ifndef QUEUE
#define QUEUE

#include <iostream>
#include <fstream>
#include <string>
#include "Event.h"
#include "Customer.h"

using namespace std;

template <class ItemType>
class Queue
{

	public:
		Queue(int = 99999);
		~Queue();

		bool isEmpty() const;
		bool isFull() const;
		int getLength() const;
		bool enqueue(ItemType);
		bool dequeue(ItemType&);
		ItemType peekFront() const;
		void print() const;
		void printToFile(char*, bool) const;

	private:
		int max;
		int front;
		int rear;
		ItemType *data;

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
template<class ItemType>
Queue<ItemType>::Queue(int a)
{

	max = a;
	front = -1;
	rear = -1;
	data = new ItemType[max];

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
template<class ItemType>
Queue<ItemType>::~Queue()
{

	delete[] data;
	data = NULL;

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
template<class ItemType>
bool Queue<ItemType>::isEmpty() const
{

	//(rear % max) == ((front % max) - 1)
	if (front == rear)
	{
		return true;
	} else {
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
template<class ItemType>
bool Queue<ItemType>::isFull() const
{

	if ((rear - max) == front)
	{
		return true;
	} else {
		return false;
	}

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
template<class ItemType>
int Queue<ItemType>::getLength() const
{

	return rear - front;

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
template<class ItemType>
bool Queue<ItemType>::enqueue(ItemType item)
{

	if(isFull())
	{
		return false;
	}

	rear++;

	int index; //index to keep the array in bounds

	//rear++; //rear is incremented, even if the array is full

	index = rear % max; //index is rear modulo max, which allows the queue to stay within the bounds of the array and wrap. If max is 7, for example, 0 mod 7 is 0 and so is 7 mod 7 as well as 14 mod 7. It keeps wrapping no matter how high rear or front get

	data[index] = item; //item is stored in the data array at position index

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
template<class ItemType>
bool Queue<ItemType>::dequeue(ItemType& item)
{

	if (isEmpty())
	{
		return false;
	}

	front++;
	
	int index; //index to keep array in bounds

	index = front % max; //index gets front's array position

	item = data[index]; //item gets what is currently stored in front

	//data[index] = 0; //the value in front is eliminated

	//front++; //front is incremented, which means dequeue no longer has to shift every data member down

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
template<class ItemType>
ItemType Queue<ItemType>::peekFront() const
{

	return data[front + 1];

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
template<class ItemType>
void Queue<ItemType>::print() const
{

	if (isEmpty())
	{
		return;
	}

	int cursor = front + 1; //cursor to go through array
	int index; //index to stay within bounds of the array

	while (cursor != rear) { //loop that outputs each indivdual data member
		index = cursor % max;
		cout << data[index];
		cursor++;
	}

	index = cursor % max;

	cout << data[index] << endl;

	//cout << front << " " << rear << endl;

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
template<class ItemType>
void Queue<ItemType>::printToFile(char* fileName, bool append) const
{

	if (isEmpty())
	{
		return;
	}

	ofstream fout;
	int cursor = front + 1; //cursor to go through array
	int index; //index to stay within bounds of the array

	//cout << "APPENDING: " << append << endl;

	if (!append)
	{
		fout.open(fileName);
		while (cursor != rear) { //loop that outputs each indivdual data member
			index = cursor % max;
			fout << data[index];
			cursor++;
		}
	
		index = cursor % max;
	
		fout << data[index];

		fout.close();
	}
	else
	{
		fout.open(fileName, ios_base::app);
		while (cursor != rear) { //loop that outputs each indivdual data member
			index = cursor % max;
			fout << data[index];
			cursor++;
		}
	
		index = cursor % max;
	
		fout << data[index];

		fout.close();
	}

}

#endif













