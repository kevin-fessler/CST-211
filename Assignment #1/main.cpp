/***********************************************************
* Author:					Kevin Fessler
* Date Created :			10/2/2015
* Last Modification Date :  10/3/2015
* Lab Number :				CST 211 - Data Structures
* File name :				main.cpp
*
*   Overview: Implementation of the array and exception classes
*
*    Input: An array
*
*   Output: Assignment of the array
*
*****************************************************************/

#include "array.h"
#include "exception.h"
#include <iostream>
#include <cstdlib>



//
// Main application (test)
//
int main() {

	int *array;

	array = new Array <int>(4, 10);			// Create an array with length 4, starting at 10

	cout << Array[3];			// Get the 3rd element in the array

	Array array1 = new Array()  // Copy an array
	Array array2 = array1()

	Exception msg("error");		// Set the message
	
	Array[12];					// Attempt to access the 12th element in the array

	cout << Exception;


	return EXIT_SUCCESS;		// Return EXIT SUCCESS
}









