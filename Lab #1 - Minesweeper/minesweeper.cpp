/***********************************************************
* Author:					Kevin Fessler
* Date Created:				10/17/2015
* Last Modification Date:	10/17/2015
* Lab Number:				CST 276
* Filename:					minesweeper.cpp
*
* Overview: This is the implementation of the Minesweeper class
*			It contains all the functions to run the game
*			(main() is included because there it is so small)
* Input:  Game size and the Minesweeper class
*
*
* Output: A game board and fully functioning Minesweeper 
*		  as long as the user does not quit from main()
*
*
************************************************************/


#include <iostream>
#include <utility>
#include <random>
#include <ctime>
#include <iomanip>
#include <stdlib.h> 


#include "minesweeper.h"

using namespace std;


// ASCII SQUARE TYPE DEFINTITIONS 
//
char COVERED_SQUARE(254);		// Covered squares
char BOMB_SQUARES('*');			// Mines
char MARKED_SQUARES(233);		// Flagged locations

#define GAME_OVER	  true
#define GAME_CONTINUE false



/**************************************************************
*   Entry: Map, current gameboard and the dimensions of the board
*
*    Exit:  Mines added to the board (boolean- returns true if a mine 
*			was added, else false if no mine was added)
*
* Purpose:  Allow the game to add mines to the board
*			based on the complexity
*
***************************************************************/
bool Minesweeper::addMine(Board &map, Board &mask, int x_dim, int y_dim)
{
	srand((unsigned int)time(NULL));				// Seed the random number generator

	int x = rand() % x_dim, y = rand() % y_dim;		// Seed a location for the mine

	
	if (map[x][y] != '*')							// Add a mine if there wasn't one at this location
	{
		map[x][y] = '*';

		for (int dx = x - 1; dx <= x + 1; dx++)			// Go through all the locations
			for (int dy = y - 1; dy <= y + 1; dy++) {
				if (dx >= 0 && dx < x_dim && dy >= 0 && dy < y_dim)
					if (map[dx][dy] != '*') {			// Don't update proximity count for mine locations
						if (map[dx][dy] == '.')
							map[dx][dy] = '1';			// Initial proximity is set to 1
					}
				}
		return true;	// Mine was added
	}

	return false;		// The specified location already contains a mine
}


/**************************************************************
*   Entry: Mask and coordinates to flag
*
*    Exit:  Either a flag set or removed from the mask
*
* Purpose:  Allow the player to place flags within the game
*
***************************************************************/
void Minesweeper::flagLocation( Board& mask, int x, int y) {

	if (mask[x][y] == MARKED_SQUARES)		// Revert a marked square to covered square
		mask[x][y] = COVERED_SQUARE;

	else
		mask[x][y] = MARKED_SQUARES;		// Set a marked square
}


/**************************************************************
*   Entry: Map, current gameboard and the dimensions of the board, as 
*			well as coordinates for a place to select
*
*    Exit:  Returns true if a mine was revealed
*
* Purpose: Reveals the specified location of the map/mask and/or
*			ends the game
*
***************************************************************/
bool Minesweeper::revealLocation(Board& map, Board& mask, int x, int y, int x_dim, int y_dim)
{

	mask[x][y] = '.';			//reveal the location

	if (map[x][y] == '*')		// Location on the grid already has a mine
		return true;


	if (map[x][y] == '.')		// If the selected place is a dot, reveal all neighboring locations
	{
		for (int i = 0; i < x_dim; i++) // Walk through all dot locations and reveal their neighboars
		{
			if (map[i][y] == '.' && mask[i][y] == COVERED_SQUARE)
					mask[i][y] = '.';									//reveal this neighboring location
			}

		}

	return false;
}

/**************************************************************
*   Entry: Map, mask and board dimensions
*
*    Exit:  Returns the number of remaining masked locations
*
* Purpose: Determines if the user has won the game
*
***************************************************************/
int Minesweeper::countMask(Board &map, Board &mask,
	int x_dim, int y_dim)
{
	int count = 0;

	for (int x = 0; x < x_dim; x++)
			for (int y = 0; y < y_dim; y++)
					if (mask[x][y] == COVERED_SQUARE) 
						count++;
	
	return count;
}


/******************************************************
Clear the minesweeper board
*******************************************************/
void Minesweeper::clear(Board &m_map, Board &m_mask)
{
	delete  &m_map;
	delete  &m_mask;
}



/******************************************************
Construct the minesweeper board
*******************************************************/
Minesweeper::Minesweeper(int row, int col, int numMines)
{
	m_row = row, m_col = col, m_numMines = numMines;
}



/******************************************************
Dynamically allocate memory
*******************************************************/
Minesweeper::~Minesweeper(){} // Automatically deleted


/**************************************************************
*   Entry: Call from main to start a game
*
*    Exit:  Returns the type of game to the main program
*			Creates a new board object
*
* Purpose: Allows the user to set the complexity of a game
*			and determine the size of the board
*
***************************************************************/
int enterLevel()
{

	cout << "\n MINESWEEPER | by Kevin Fessler\n"
		<< " ================================  \n\n"
		<< "Please select your level.\n\n";
	
	cout << " [b] - Beginner     = Grid is 10 X 10 and 10 mines\n"
		<< " [i] - Intermediate = Grid is 16 X 16 and 40 mines\n"
		<< " [e] - Expert       = Grid is 16 X 30 and 100 mines\n"
		<< "\n {q} - Quit\n\n";

	char input;

	while (true) {

		cout << "\nSelect: ";
		cin >> input;				// Get input from the user

		if (input == 'b') {
			Minesweeper game(10,10,10);		// Create a beginner board
		}

		if (input == 'i') {
			Minesweeper game(16, 16, 40);	// Create an intertermediate board
		}

		if (input == 'e') {
			Minesweeper game(16, 30, 100);	// Create an expert board
		}

		if (input == 'q') {					// Quit the game
			return input;
		}

		else{
			cout << "Error! Not a valid input! Try again?\n\n";
		}
	}

		system("cls");  // Clear the screen


	// Quit if the value entered was invalid
	// or there was another problem with creating the board
	return EXIT_FAILURE; 
}



/******************************************************
Display the current Minesweeper gameboard
*******************************************************/
void Minesweeper::displayBoard(Board &map, Board &mask,
	int x_dim, int y_dim) {


	cout << "\n == CURRENT MINESWEEPER GAMEBOARD == \n\n";

	cout << "    ";

	//loop through our rows
	for (int x = 0; x < x_dim; x++)
	{
		//loop through all the columns for this row
		for (int y = 0; y < y_dim; y++)
		{
			//if location is still masked, display mask char
			//otherwise display the underlying map value

			if (mask[x][y] == COVERED_SQUARE)
				cout << COVERED_SQUARE;

			else if (mask[x][y] == MARKED_SQUARES)
				cout << MARKED_SQUARES;

			else
				cout << map[x][y];
		}
		cout << endl << "    ";
	}

}

/******************************************************
Allow the user to select or flag a location on the board
*******************************************************/
bool Minesweeper::selectLocation(Board &map, Board &mask,
	int x_dim, int y_dim) {


	// Variables to get the user's input
	int x_in, y_in;
	char dummy;


	//Prompt user to input a location
	cout << "\n\n  - Select a location on the board (x,y): ";
	cin >> y_in >> dummy >> x_in;


	char option;
	cout << "      - Type 'f' to flag/unflag"
		<< "\n      - Type 's' to select "
		<< "\n\n >  Input: ";
	cin >> option;


	// Set a flag
	//
	if (option == 'f') {
		flagLocation(mask, x_in, y_in);
		system("cls");  // Formatting between gameboards
	}


	// Select a square
	//
	if (option == 's') {
		system("cls");  // Formatting between gameboards


		// revealLocation will return true if a mine was unmasked
	if (revealLocation(map, mask, x_in, y_in))
		{
			cout << "\n\n Oh no! A mine was set off!\n\n\n GAME OVER..." << endl;
			system("PAUSE");
			return GAME_OVER;
		}

		// Count our masked location, if == numMines, then only mines are left
		// and player has won the game

		if (countMask(map, mask, x_dim, y_dim) == m_numMines)
		{
			cout << "You're amazing, you win!" << endl;
			system("PAUSE");									// Pause unless you 
			return GAME_OVER;
		}
	}

	else {
		system("cls");
		cout << "**** ERROR - 'Invalid selection' - Try Again?";
	}

	return GAME_CONTINUE;			// Continue the game 
}


/******************************************************
Game loop - Loop until the game is complete
*******************************************************/
void Minesweeper::gameLoop(Board &map, Board &mask, int x_dim, int y_dim, int numMines) {

	// Generate the map and mask
	for (int i = 0; i < x_dim; i++)
	{
		for (int j = 0; j < y_dim; j++)
		{
			map[i][j] = '.';
			mask[i][j] = COVERED_SQUARE;
		}
	}

	
	
	int mineCount = 0;	// Add mines to set up the game
	do
	{
		if (addMine(map))
			mineCount++;
	} while (mineCount != numMines);


	do
	{
		// Display the current gameboard status
		displayBoard(map, mask,x_dim, y_dim);

	} while (selectLocation(map, mask, x_dim, y_dim) != GAME_OVER);	// Loop to select a location


	clear(map, mask);		// Clear map and mask

}


/******************************************************
Launch the game. If the user types in q, the game quits
*******************************************************/
int main()
{
	while (true) {
		if (enterLevel() == 'q')	// Quit from the main menu
			return EXIT_SUCCESS;
	}
}