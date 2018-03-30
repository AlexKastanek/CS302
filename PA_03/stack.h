// Class Header File Information //////////////////////////////////////////////
/**
  * @file stack.h
  *
  * @brief Definition file for Stack class
  *
  * @author Alex Kastanek
  *
  * @details Specifies all member methods of the Stack class
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

#ifndef STACK_HEADER_
#define STACK_HEADER_

#include <iostream>
#include <string>

using namespace std;

class Stack {
        public:
                Stack(int = 10);
                ~Stack();
                Stack& operator=(const Stack&);
                bool push(string);
                bool pop(string&);
				string peek();
				int getLength();
                bool empty() const;
                bool full() const;
                bool clear();
                friend ostream& operator<<(ostream&, const Stack&);
        private:
                int max;
                int top;
                int actual; //only used in stack (stay) implementation
                string* data;
};

#endif
