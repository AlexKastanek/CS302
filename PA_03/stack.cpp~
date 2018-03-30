// Class Implemntation File Information ///////////////////////////////////////
/**
  * @file stack.cpp
  *
  * @brief Implementation file for Stack class
  *
  * @author Alex Kastanek
  *
  * @details Implements all member methods of the Stack class
  *
  * @version 1.00
  *  		 C.S. Student (18 April 2016)
  *			 Initial development and testing of Stack class
  *
  * @version 1.01
  *			 C.S. Student (18 October 2016)
  *			 Revising of Stack class to work with strings
  *
  * @note Derived from class author made in semester of Spring 2016, please
  *		  excuse format inconsistencies that this class has when compared to 
  *		  the other classes in this project.
  *
  */

#ifndef STACK_
#define STACK_

#include <iostream>
#include <fstream>
#include "stack.h"

using namespace std;

Stack::Stack(int a) { //default constructor with value of max set to 10 if no parameters are given

	max = a;
	top = -1;
	data = new string[max];

}

Stack::~Stack() { //destructor

	top = -1;
	delete[] data;
	data = NULL;

}

Stack& Stack::operator=(const Stack& source) { //assignment operator function assigns each value in the calling class to the source

	clear();
	delete[] data;
	data = NULL;

	max = source.max;

	top = source.top;

	data = new string[source.max];

	for (int i = 0; i < top; i++) {
		data[i] = source.data[i];
	}

	return *this;

}

bool Stack::push(string item) { //function that pushes a specified element onto the stack

	if (full()) { //if stack is full returns false
		return false;
	}

	top++; //increments top

	data[top] = item; //places new item on top

	return true;

}

bool Stack::pop(string& item) { //function that pushes the top element off of the stack

	if (empty()) { //if stack is empty returns false
		return false;
	}

	item = data[top]; //stores top in item

	data[top] = " "; //sets top to null character

	top--; //decrements top

	return true;

}

string Stack::peek() {

	if (empty()) {
		return "";
	} else return data[top];

}

int Stack::getLength()
{

	return top + 1;

}

bool Stack::empty() const { //checks if stack is empty

	if (top == -1) { //returns true if top is -1
		return true;
	} else return false;

}

bool Stack::full() const { //checks if stack is full

	if (top == max - 1) { //returns true if top is equal to the max number of items - 1
		return true;
	} else return false;

}

bool Stack::clear() { //clears the stack

	if (empty()) { //if the stack is empty returns false
		return false;
	}

	for (int i = 0; i < max; i++) { //loop that sets each item in the stack to null
		data[i] = " ";
	}

	top = -1; //sets top back to its default value

	return true;

}

ostream& operator<<(ostream& os, const Stack& list) { //outputs the data within the stack

	for (int i = 0; i < list.top + 1; i++) {
		if (i == 0)
		{
			os << list.data[i];
		} else os << " -> " << list.data[i];
	}

	return os;

}

#endif



