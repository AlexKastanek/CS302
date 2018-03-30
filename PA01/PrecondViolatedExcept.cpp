// Class Implemntation File Information ///////////////////////////////////////
/**
  * @file PrecondViolatedExcept.cpp
  *
  * @brief Implementation file for PrecondViolatedExcept class
  *
  * @author Alex Kastanek
  *
  * @details Implements all member methods of the PrecondViolatedExcept class
  *
  * @version 1.00
  *  		 C.S. Student (14 September 2016)
  *			 Initial development and testing of PrecondViolatedExcept class
  *
  * @note Requires PrecondViolatedExcept.h
  *
  * @note Adapted from Frank M. Carrano and Timothy M. Henry Copyright (c) 0217
  *       Pearson Education, Hoboken, New Jersey.
  *
  */

#include "PrecondViolatedExcept.h"

PrecondViolatedExcept::PrecondViolatedExcept(const std::string& message)
 : std::logic_error("Precondition Violated Exception: " + message)
{
}
