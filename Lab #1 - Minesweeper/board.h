/***********************************************************
* Author:					Kevin Fessler
* Date Created:				10/17/2015
* Last Modification Date:	10/17/2015
* Lab Number:				CST 276
* Filename:					board.cpp
*
* Overview: A smaller version of the Array2D class with unecessary
*			functions removed
*
* Input: A row or column that sets the dimensions of the board
*		 and assigns the Cell a value
*
* Output: An array of Cells that contain values dependent on
*			the input from the Minesweeper game:
*			1. Mask array - A cover that counts the number of open
*							spaces on the board
*			2. Map array  - actual game board
*
************************************************************/

#include "cell.h"

class Board
{

public:

	Board(int row, int col);			// Board constructor given a row and/or column

	~Board();							// Board destructor

	int getRow() { return m_row; }		// Get row
	int getColumn() { return m_col; }	// Get Column

	void setRow(int rows);				// Set row
	void setColumn(int columns);		// Set columns

	Cell Select(int row, int column);	// Select a cell in the board

	Board &operator=(const Board &rhs);	// Assignment operator


private:

	int m_row;		// Set the number of rows in the board
	int m_col;		// Set the number of columns in the board
	Cell **m_array;	// Set the board dimensions

};

