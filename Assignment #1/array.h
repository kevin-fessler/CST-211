/***********************************************************
* Author:					Kevin Fessler
* Date Created :			10/2/2015
* Last Modification Date :  10/2/2015
* Lab Number :				CST 211
* File name :				array.h
*
*   Overview: Implementation of an Array ADT that is
*			  based on a dynamic array.
*
*    Input: The array length and starting index
*
*   Output: An array that meets the specifications:
*		- Valid length
*		- Not out of bounds
*		- Setting the length of the array
*		- Capable of starting at a negative index
*
*****************************************************************/



#include <iostream>

using namespace std;


template<typename T>

class Array {

public:
	Array();									// Array Default Constructor
	Array(int length, int start_index = 0);
	Array(const Array &copy);					// Array Copy Constructor
	~Array();									// Array Class Destructor

	Array &operator=( const Array &rhs);		//Assignment Operator
	T &operator [ ](int index);					// Index operator

	int getStartIndex();
	void setStartIndex(int start_index);

	int getLength();
	void setLength(int length);

	// Mutators

protected:
	T *m_array;
	int m_length;
	int m_start_index;

};






//
// Default constructor
//
template<typename T>
Array<T>::Array() {}


//
// Construct the array
//
template<typename T>
Array<T>::Array(int length, int start_index) {

	//
	// The actual index number of the array (what position it is in)
	//
	int r_true_index = start_index + length;
	int l_true_index = start_index - length;

	//
	// If the start index criteria isn't met, throw an exception.
	// This will allow resizing of the array to occur.
	//					  
	// Ex:  index -> |0|1|2|3|4|  can be truncated to:  |0|1|
	//               |-|-|-|-|-|						|-|-|
	//       char -> |N|A|M|E|S|						|A|M|
	//				    ^ ^							   
	//				    x x    <- New index range (1-2)
	//
	if (start_index > r_true_index || start_index < l_true_index) {
		throw Exception;
	}

	else {

		//
		// Set the new length and index of the array
		//
		setLength(length);
		setStartIndex(start_index);


		//
		// If all conditions are met, create a new array
		//
		T *m_array = new T[getLength()];
	}
}



//
// Array copy constructor
// 
template<typename T>
Array<T>::Array(const Array & copy) {}



//
// Destructor for the array class
//
template<typename T>
Array<T>::~Array() { delete m_array; }


//
// Assignment Operator
//
template<typename T>
Array & Array<T>::operator=(const Array & rhs)
{
	if (this != &rhs)
	{
		clear();
		copy(rhs.m_array);
	}	return *this;
}

template<typename T>
T & Array<T>::operator[](int index)
{
	return m_array[index];
}



//
// Return the start index of the array
//
template<typename T>
int Array<T>::getStartIndex() {	return m_start_index; }


//
// Set the start index of the array
//
template<typename T>
void Array<T>::setStartIndex(int start_index) {	m_start_index = start_index;}


//
// Return the length of the array
//
template<typename T>
int Array<T>::getLength() {	return m_length;}


//
// Set the length of the array
//
template<typename T>
void Array<T>::setLength(int length){m_length = length;}