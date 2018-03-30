// Class Header File Information //////////////////////////////////////////////
/**
  * @file PrecondViolatedExcept.h
  *
  * @brief Definition file for PrecondViolatedExcept class
  *
  * @author Alex Kastanek
  *
  * @details Specifies all member methods of the PrecondViolatedExcept class
  *
  * @version 1.00
  *  		 C.S. Student (14 September 2016)
  *			 Initial development and testing of PrecondViolatedExcept class
  *
  * @note Adapted from Frank M. Carrano and Timothy M. Henry Copyright (c) 0217
  *       Pearson Education, Hoboken, New Jersey.
  *
  */

#ifndef PRECOND_VIOLATED_EXCEPT
#define PRECOND_VIOLATED_EXCEPT

#include <stdexcept>
#include <string>

class PrecondViolatedExcept: public std::logic_error
{
public:
	PrecondViolatedExcept(const std::string& message = "");
};

#endif
