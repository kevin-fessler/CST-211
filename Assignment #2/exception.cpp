/***********************************************************
* Author:					Kevin Fessler
* Date Created :			10/2/2015
* Last Modification Date :  10/3/2015
* Lab Number :				CST 211 - Data Structures
* File name :				main.cpp
*
*   Overview: Implementation of the array and exception classes
*
*    Input: An exception message to be set or retrieved
*
*   Output: An exception message or the creation of 
*			an exception object
*
*****************************************************************/


#include "exception.h"

using namespace std;



// Default constructor constructs a message object,
// but no message if none was set
Exception::Exception(){}


// Set an call "setMessage" to set an exception message
Exception::Exception(char *msg)
{
	setMessage(msg);
}


// Copy constructor
Exception::Exception(const Exception & copy){}


// Message destructor
Exception::~Exception()
{
	delete &m_msg;
}


/**************************************************************
*   Entry:  The rhs of the input from the client code
*
*    Exit:  Assigns a new message from the user
*
* Purpose:  Set an exception message when the assignment operator
*			is called from the client code
*
***************************************************************/
Exception & Exception::operator=(const Exception & rhs)
{
	// To avoid self assignment...
	if (this == &rhs)   
		return  *this;

	// Destruct the old message
	delete[] &m_msg;

	// Create a message with the same length as the new one
	m_msg = new char[strlen(rhs.m_msg) + 1];
	
	// Copy the new message
	strcpy(m_msg, rhs.m_msg);

	return  *this;

}


/**************************************************************
*   Entry:  Message string from the constructor
*
*    Exit:  A newly assigned message
*
* Purpose:  Sets a new message when the constructor is called
*
***************************************************************/
void Exception::setMessage(char *msg)
{
	m_msg = msg;
}
