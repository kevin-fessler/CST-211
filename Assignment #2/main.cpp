/***********************************************************
* Author:					Kevin Fessler
* Date Created :			10/2/2015
* Last Modification Date :  10/3/2015
* Lab Number :				CST 211 - Data Structures
* File name :				main.cpp
*
*   Overview: The test program for all of the classes
			  Implementation of the array, row and exception classes
*
*    Input: User defined input
*
*   Output: Depends on calls to the array or exception classes:
*				1) Successfull assignment
*				2) Thrown exception error
*
*****************************************************************/


#include <iostream>
#include "array2D.h"
#include "exception.h"


using namespace std;

int main()
{


	Array2D<int> letters(12,12); // <--  Construct an array of integers called letters

								 //	User can change with char or other
								 // assignable type and compile


		/************************************************
		* GENERAL 2D ARRAY TEST:
		*
		*		1. Get & Set
		*		2. Assignment
		*		3. Throwing exceptions
		*		4. Copy constructor
		*		5. Operator assignment
		*
		*************************************************/

	// Prompt the user to set a number in an array position
	int userNumber;
	cout << "Enter a number to set: ";
	cin >> userNumber;

	
	int x;					// Enter x coordinate
	cout << "Enter x: ";
	cin >> x;

	int y;					// Enter y coordinate
	cout << "Enter y: ";
	cin >> y;


	// Assign the data to a location in the array
	letters[x][y] = userNumber;


	// Display the set data
	cout << "Data that was set was: " << letters[x][y];


	// Construct an array of type char called stuff
	Array2D<char> stuff(9,9);


	// Assign an "h" to (2,2) in the array
	stuff[1][1] = 'h';


	// Create a new array called more
	Array2D<char> more(6,6);


	// Assignment : truncate + resize 'stuff' to 'more'
	more = stuff;

	// Display the data on the screen
	cout << "After all is said and done, the data remains: " << more[1][1]
		 << endl;	 


	// Test an exception by creating one
	Exception ifIWasAnException("THIS IS A TEST OF EXCEPTIONS!!!");


	// Display the exception
	cout << ifIWasAnException << " Looks like it works, right?";


	return EXIT_SUCCESS;
}
