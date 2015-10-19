/***********************************************************
* Author:					Kevin Fessler
* Date Created:				10/17/2015
* Last Modification Date:	10/17/2015
* Lab Number:				CST 276
* Filename:					board.cpp
*
* Overview: This is the implementation of the Board Class
*
* Input:  Game size and Cell to set
*
* Output: A set cell in the gameboard or a new gameboard
*
************************************************************/

#include "board.h"



/******************************************************
Constructor
*******************************************************/
Board::Board(int row, int col)
{
	setRow(row);
	setColumn(col);


	m_array = new Cell *[row];
	if (m_array)
	{
		for (int i = 0; i < row; i++)
		{
			m_array[i] = new Cell[col];
		}
	}

}


/******************************************************
Delete the array
*******************************************************/
Board::~Board()
{
	delete m_array;
}


/******************************************************
Set Row
*******************************************************/
void Board::setRow(int rows)
{
	m_row = rows;
}


/******************************************************
Set Column
*******************************************************/
void Board::setColumn(int columns)
{
	m_col = columns;
}



/******************************************************
Select a value in the array
*******************************************************/
Cell Board::Select(int row, int column)
{
	return m_array[row][column];
}




/******************************************************
Assignment Operator
*******************************************************/
Board & Board::operator=(const Board & rhs)
{
	delete m_array;			// Delete the current size of the array
	m_row = rhs.m_row;			// Set the new row
	m_col = rhs.m_col;			// Set the new column
	m_array = rhs.m_array;		// Assign the data to a new array
}
