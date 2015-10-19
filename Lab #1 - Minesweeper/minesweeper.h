/***********************************************************
* Author:					Kevin Fessler
* Date Created:				10/17/2015
* Last Modification Date:	10/17/2015
* Lab Number:				CST 276
* Filename:					minesweeper.cpp
*
* Overview: Manages the gameboard and Board Class
*
* Input: User input for the size and complexity
*
* Output: A fully functionaly game of Minesweeper
************************************************************/

#include "board.h"

using namespace std;

class Minesweeper
{

public:

	Minesweeper(int row, int col, int numMines);	// Constructor

	~Minesweeper();									// Destructor

	void displayBoard(Board & m_map, Board & m_mask, int x_dim, int y_dim);	
	bool selectLocation(Board & m_map, Board & m_mask, int x_dim, int y_dim);
	void gameLoop(Board & m_map, Board & m_mask, int x_dim, int y_dim, int n_numMines);


	bool addMine(Board & map, Board & mask, int x_dim, int y_dim);
	void flagLocation( Board &m_mask, int x, int y);


	// bool revealLocation(Board & map, Board & mask, int x, int y, int x_dim, int y_dim);
	
	bool revealLocation(Board & map, Board & mask, int x, int y, int x_dim, int y_dim);

	int countMask(Board &map, Board &mask,int x_dim, int y_dim);
	void clear(Board &m_map, Board &m_mask);


	// Return the column of the mask to set- Subscript operator
	Board operator [](int)
	{
		return *m_mask[m_col];
	}


private:

	int m_col;
	int	m_row;
	int m_numMines;

	Board ** m_map;		// The map board (game board)
	Board ** m_mask;	// The mask board

	

};