/***********************************************************
* Author:					Kevin Fessler
* Date Created :			10/2/2015
* Last Modification Date :  10/3/2015
* Lab Number :				CST 211 - Data Structures
* File name :				array.h
*
*   Overview: Definition of the array base class and row class
*
*   Input: User specification of a certain 2D array, size, 
*			column, width or length.
*
*   Output: Assignment of the array, creation of the array,
*			or a particular element in the array (given the 
*			row and column).
*
*****************************************************************/

#include <iostream>

using namespace std;



// The Array2D class is derived from the Row class

template<typename T>
class Row : public Array2D
{

public:

	Row(Array2D &array, int row);

	// Select a column
	T &operator[](int column);

private:

	// Reference to the array object
	Array2D & m_array2D;

	int m_row;

};


/*********************************************/


template<typename T>

class Array2D
{

public:
	
	// Default 2D array constructor
	Array2D();

	// 2D Array constructor given a row and/or column
	Array2D(int row, int col = 0);

	// Array constructor
	Array2D(const Array2D &Array2D);

	// Array destructor
	~Array2D();

	// Assignment and subscript operator
	Array2D &operator=(const Array2D &rhs);
	Row<T> operator[](int index);


	// Get the row/column
	int getRow() {return m_row;}
	int getColumn() { return m_col; }


	// Set the row/column
	void setRow(int rows);
	void setColumn(int columns);


	// Select a certain cell in the array
	T &Select(int row, int column);
	

// Mutator
protected:
	
	T** m_array;
	int m_row;
	int m_col;
	
};

#include "array2D.inc"