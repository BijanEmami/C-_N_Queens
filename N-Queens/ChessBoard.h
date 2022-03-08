/**
* Bijan Emami
* Project N-Queens
**/

#ifndef CHESSBOARD_H
#define CHESSBOARD_H

class ChessBoard
{

private:
	/**
	* char pointer for 2D dynamic array to hold board size.
	**/
	char** boardPtr;
	int boardSize;
	/**
	* Recursive algorithm to place queens on the board.  If unable to place
	* queen, it backtracks to find another possible solution.
	* @param int column  Used to specify which column to start placing queen in.
	* @return returns true if all queens have been place correctly, otherwise false which
	* calls the recursive function.
	**/
	bool placeQueens(int column); // recursive solution
	/**
	* Function to find if a queen can be placed on the board without
	* being attacked by another queen.  Horizontally, vertically, and diagonally
	* @param row checks for queen placement in rows
	* @param column check for queen placement in columns
	* @return canPlace,  canPlace == true if all checks are passed, and a queen can be placed, otherwise == false.
	* @pre column number must be < getSize() function
	**/
	bool canMove(int row, int column); // check if can move
public:
	ChessBoard();
	ChessBoard(int size);
	~ChessBoard();
	/**
	*Recieves size of board, deletes previous board, then creates new board
	* @param int size size used to determine the size of the board for creation.
	**/
	void setSize(int size);
	int getSize();
	/**
	* Confirms the board has been solved.
	* returns true if the board has been successfully solved, else false.
	**/
	bool solve();
	/**
	* Displays the board with queens placed
	**/
	void displayBoard();

};


#endif // !

