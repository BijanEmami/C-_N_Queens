/**
* Bijan Emami
* Project N-Queens
**/

#include "ChessBoard.h"
#include <iostream>
using namespace std;


//Default Constructor
ChessBoard::ChessBoard()
{
	
	boardPtr = new char* [boardSize];
	
	for (int i = 0; i < boardSize; i++)
	{
		boardPtr[i] = new char[boardSize];
	}

	for (int i = 0; i < boardSize; i++)
	{
		for (int j = 0; j < boardSize; j++)
		{
			boardPtr[i][j] = '*';
		}
	}
	
}

//Constructor with size passed in parameter
ChessBoard::ChessBoard(int size)
{	
	
	boardPtr = new char* [size];

	for (int i = 0; i < size; i++)
	{
		boardPtr[i] = new char[size];
	}

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			boardPtr[i][j] = '*';
		}
	}
	
}

// Destructor
ChessBoard::~ChessBoard()
{
	for (int i = 0; i < getSize(); i++)
	{
		delete[] boardPtr[i];
	}
	
	delete[] boardPtr;
}

// Checks to see if a queen can be placed
bool ChessBoard::canMove(int row, int column)
{
	bool canPlace = true;

	for (int i = 0; i < column; i++)  // check for placement in row
	{
		if (boardPtr[row][i] == 'Q')
		{
			canPlace = false;  
		}
	}

	for (int i = 0; i < row; i++)  // check for placement in column
	{
		if (boardPtr[i][column] == 'Q')
		{
			canPlace = false;
		}
	}

	for (int i = row, j = column; i >= 0 && j >= 0; i--, j--)  // check for placement upper diagonal
	{
		if (boardPtr[i][j] == 'Q')
		{
			canPlace = false;
		}

	}

	for (int i = row, j = column; i < getSize() && j >= 0; i++, j--) // check for placement lower diagonal
	{
		if (boardPtr[i][j] == 'Q')
		{
			canPlace = false;
		}
	}

	return canPlace;  //  return true if all checks are passed and can move queen to position

}




//solves problem with backtracking
bool ChessBoard::placeQueens(int column)  
{
	int row = 0;

	if (column >= getSize())
	{
		return true;
	}
	else
	{
		while (row < boardSize)
		{
						
			if (canMove(row, column) == true)
			{
				
				boardPtr[row][column] = 'Q';

				if (!placeQueens(column + 1)) 
				{
					boardPtr[row][column] = '*';
					row++;
				}
				else
				{
					return true;
				}
			}
			else
			{
				row++;
			}
						
		}

		return false;

	}
	
}

// Set size of board
void ChessBoard::setSize(int size)
{
	for (int i = 0; i < boardSize; i++)
	{
		delete[] boardPtr[i];
	}

	delete[] boardPtr;

	if (size < 4)
	{
		boardSize = 4;
	}
	if (size > 12)
	{
		boardSize = 12;
	}
	if (size >= 4 && size <= 12)
	{
		boardSize = size;
	}

	boardPtr = new char* [boardSize];

	for (int i = 0; i < boardSize; i++)
	{
		boardPtr[i] = new char[boardSize];
	}

	for (int i = 0; i < boardSize; i++)
	{
		for (int j = 0; j < boardSize; j++)
		{
			boardPtr[i][j] = '*';
		}
	}

}

// Get size of board
int ChessBoard::getSize()
{
	return boardSize;
}

//returns true if board is solved
bool ChessBoard::solve() 
{
	bool isSolved = false;
	
	if (placeQueens(isSolved) == true)
	{
		isSolved = true;
	}
	
	return isSolved;
}



void ChessBoard::displayBoard()
{
	
	for (int i = 0; i < boardSize; i++)
	{
		for (int j = 0; j < boardSize; j++)
		{
			cout << boardPtr[i][j] << " ";
		}

		cout << endl;
		
	}
}