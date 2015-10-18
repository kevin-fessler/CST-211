/***********************************************************
* Author:					Kevin Fessler
* Date Created :			10/2/2015
* Last Modification Date :  10/3/2015
* Lab Number :				CST 211 - Data Structures
* File name :				exceptions.h
*
*   Overview: The exception class allows the client to 
*			  know if a condition was not met when the 
*			  client calls an array from the main program.
*
*    Input: An exception message to be set
*
*   Output: The exception message which was set by the program.
*
*****************************************************************/

#include <iostream>


using namespace std;


#ifndef  exceptions_H
#define  exceptions_H

class Exception
{

public:

	// Construct or destruct the exception object
	Exception();
	Exception(char *msg);
	Exception(const Exception &copy);
	~Exception();


	// Get/set/assign the message if called
	Exception &operator=(const Exception &rhs);
	const char* getMessage() { return m_msg; }
	void setMessage(char *msg);


	// Read in the message from the user
	friend ostream &operator<<(ostream &stream, const Exception &except) 
	{ return (stream << except.m_msg); }


private:

	// Private exception message to be set
	char *m_msg;

};
#endif
