/***********************************************************
* Author:					Kevin Fessler
* Date Created :			10/2/2015
* Last Modification Date :  10/11/2015
* Lab Number :				CST 211 - Data Structures
* File name :				arra.inc
*
*   Overview: Implementation of the array, row and exception classes
*
*    Input: User defined input
*
*   Output: Assignment of the array, access to a data
*			element or a thrown exception based on the client
*			caller input
*
*****************************************************************/


using namespace std;

#define MEMORY_ERROR		"*** Memory allocation error!"
#define ASSIGNMENT_ERROR	"*** Data assignment error!"
#define OUT_OF_BOUNDS_ERROR "*** Out of bounds error!"



/**************************************************************
*   Entry:  Constructor for a new array (no size)
*
*    Exit:  The creation of a new  array with no dimensions
*
* Purpose:  Creates a new array of type T with no dimensions if
*			called by the client program
*
***************************************************************/
template<typename T>
Array2D<T>::Array2D()
{	
	m_array = new T;
}



/**************************************************************
*   Entry:  Row and column from the test program
*
*    Exit:  The creation or resizing of a new array object
*			with the determined dimensions
*
* Purpose:  Creates a new Array 2D object with valid 
*			dimensions when called
*
***************************************************************/
template<typename T>
Array2D<T>::Array2D(int row, int col)
{
	// Set the row and column variables
	setRow(row);
	setCol(col);


	// Allocate memory for the array or resize based on input
	m_array = new T * [row];
	if(m_array)
	{
		for(int i = 0; i < rows; i++)
		{
			m_array[i] = new T [col];	
		}
	}

	// If the array could not be created, throw an exception
	// of type MEMORY_ERROR
	if(!m_array)
	{
		throw exception(MEMORY_ERROR);	
	}

}




/**************************************************************
*   Entry:  New dimensions
*
*    Exit:  The creation or resizing of a new array object
*			with the determined dimensions
*
* Purpose:  Copy constructor for the Array 2D class
*
***************************************************************/
template<typename T>
Array2D<T>::Array2D(const Array2D &rhs)
{
	// Set a new value based on user input
	m_row = rhs.m_row;
	m_col = rhs.m_col;
	m_array = rhs.m_array;
	

	// If the array could not be created, throw an exception
	// of type MEMORY_ERROR
	if(!m_array)
	{
		throw exception(MEMORY_ERROR);
	}
}



/**************************************************************
*   Entry:  New Array to be assigned
*
*    Exit:  The creation or resizing of a new array object
*			with the determined dimensions
*
* Purpose:  Assignment operator for the Array 2D class
*
***************************************************************/
template<typename T>
Array2D<T> &Array2D<T>::operator=(const Array2D &rhs)
{
	
	delete[][]m_array;			// Delete the current size of the array
	m_row = rhs.m_row;			// Set the new row
	m_col = rhs.m_col;			// Set the new column
	m_array = rhs.m_array;		// Assign the data to a new array
	

	// If the array could not be assigned, throw an exception
	// of type MEMORY_ERROR
	if(!m_array)
	{
		throw exception(ASSIGNMENT_ERROR);
	}

	return *this;
}




/**************************************************************
*   Entry:  New Array to be assigned
*
*    Exit:  The creation or resizing of a new array object
*			with the determined dimensions
*
* Purpose:  Assignment operator for the Array 2D class
*
***************************************************************/
template<typename T>
void Array2D<T>::setRow(int row)
{
	m_row = row;
}



/**************************************************************
*   Entry:  A row and colum specified by the client program
*
*    Exit:  The element within the array of the specified cell
*
* Purpose:  Select an element within the array and return the
*			data that it contains
*
***************************************************************/
template<typename T>
T &Array2D<T>::Select(int row, int column)
{
	// If the selected cell is out of bounds, throw an exception
	if(row > m_row || column > m_col)
	{
		throw exception(OUT_OF_BOUNDS_ERROR);
	}
	
	// Return the data within the cell
	return m_array[row][column];
}




/**************************************************************
*   Entry:  The index position of an element
*
*    Exit:  The index position of the entire line of data
*
* Purpose:  To find the index of data within the array
*
***************************************************************/
template<typename T>
Row<T> Array2D<T>::operator[](int index)
{
	return m_array[index];
}




/**************************************************************
*   Entry:  Column number to be set
*
*    Exit:  A set column in the private member data 
*
* Purpose:  To set a column based on the constructor or client
*
***************************************************************/
template<typename T>
void Array2D<T>::setColumn(int column)
{
	m_col = column;
}




/**************************************************************
*   Entry:  A column integer
*
*    Exit:  A set column
*
* Purpose:  Find a row given a column
*
***************************************************************/
template<typename T>
T & Row<T>::operator[](int column)
{
	m_column = column;		// Reset the column
	m_array2D = array;		// Set the array in the abstract Row class
}



/**************************************************************
*   Entry:  An array reference and row integer 
*
*    Exit:  Set of columns
*
* Purpose:  Given a row, find the column in the array and resize
*
***************************************************************/
template<typename T>
Row<T>::Row(Array2D &array, int row)
{
	m_row = row;			// Reset the column
	m_array2D = array;		// Set the array in the abstract Row class
}



// Returns the data in the row and column
template<typename T>
Row <T> &Array<T>::operator[](int column)
{
	return m_array2D[m_row][column];
}



// Destructor for the Array 2D class
template<typename T>
Array2D<T>::~Array2D()
{
	delete[][]m_array;
}




























