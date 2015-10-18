/***********************************************************
* Author:					Kevin Fessler
* Date Created :			10/2/2015
* Last Modification Date :  10/2/2015
* Lab Number :				CST 211 - Data Structures
* File name :				exception.h
*
*   Overview: Implementation of an Array ADT that is
*			  based on a dynamic array.
*
*    Input: The user specifies an index smaller than the lower bounds
*          or has specified an index larger than the upper bounds.
*
*   Output: A string with an error message
*
*****************************************************************/

#include <iostream>
#include <typeinfo.h>

using namespace std;


class Exception {

private:
	char *m_msg;					// Exception message 

public:
	Exception();
	Exception(char *msg);
	Exception(const Exception &copy);
	~Exception();

	Exception &operator=(const Exception &rhs);
	const char *getMessage();
	void setMessage(char *msg);
	ostream &operator<<(ostream &stream, const Exception &except);


};


//
// Get the exception error message
//
ostream & Exception::operator<<(ostream & stream, const Exception & except){
	return stream << except.getMessage;
}



//
// Default constructor
//
Exception::Exception() {}


//
// Exception constructor
//
Exception::Exception(char * msg) {setMessage(msg);}


//
// Copy constructor
//
Exception::Exception(const Exception & copy) {}


//
// Destructor
//
Exception::~Exception() { delete m_msg; }


//
// Assignment Operator
//
Exception & Exception::operator=(const Exception & rhs) {

	if (this != &rhs) {					// self-assignment check
		
			delete[] m_msg;            		
			m_msg = new char[]; 
		}
	return *this;
}


//
// Return an error message
//
const char * Exception::getMessage() {return m_msg;}


//
// Set the error message for an exception
//
void Exception::setMessage(char * msg) {*m_msg = *msg;}

