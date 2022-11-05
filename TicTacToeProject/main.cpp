/*
Created by DvDream on 05/11/2022

Tic-Tac-Toe C++ project assigned by "The complete C++ course" on Udemy 

*/

#include <iostream>
#include <string>
#include <ctime>
using namespace std;

const int ROWS = 3;
const int COLS = 3;

void runGame(); // main loop function

void putIntoGameBoard(bool xTurn, string gameBoard[ROWS][COLS]);
void initializeGameBoard(string gameBoard[ROWS][COLS]);
void printGameboard(string gameBoard[ROWS][COLS]);
string whoWins(string gameBoard[ROWS][COLS]);
bool isFull(string gameBoard[ROWS][COLS]);
bool cellOccupied(int row, int col, string gameBoard[ROWS][COLS]);

int main()
{
	runGame();
	return 0;
}

void runGame()
{
	srand(time(nullptr));
	string gameBoard[ROWS][COLS];
	string winner = "";
	bool xTurn = true;

	initializeGameBoard(gameBoard);

	while (winner == "")
	{
		if (xTurn)
		{
			cout << "Is X turn, please type cell's indexes separated by space (0-2):" << endl;
		}
		else
		{
			cout << "Is O turn, please type cell's indexes separated by space (0-2):" << endl;
		}

		printGameboard(gameBoard);
		putIntoGameBoard(xTurn, gameBoard);
		winner = whoWins(gameBoard);
		
		if (winner == "" && isFull(gameBoard))
		{
			winner = "C";
		}
		
		xTurn = !xTurn;
	};

	if (winner == "C") {
		cout << "No one wins, it's the cat's game!" << endl;

	}
	else {
		cout << "The winner is: " << winner << "!" << endl;

	}

	printGameboard(gameBoard);
}

void initializeGameBoard(string gameBoard[ROWS][COLS])
{
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			gameBoard[i][j] = " ";
		}
	}

}

void printGameboard(string gameBoard[ROWS][COLS])
{
	cout << " " << gameBoard[0][0] << " | " << gameBoard[0][1] << " | " << gameBoard[0][2] << endl;
	cout << "-----------" << endl;
	cout << " " << gameBoard[1][0] << " | " << gameBoard[1][1] << " | " << gameBoard[1][2] << endl;
	cout << "-----------" << endl;
	cout << " " <<  gameBoard[2][0] << " | " << gameBoard[2][1] << " | " << gameBoard[2][2] << endl;
	cout << endl;

}

void putIntoGameBoard(bool xTurn, string gameBoard[ROWS][COLS])
{
	string mark;
	string move;
	int row_idx = 0;
	int col_idx = 0;

	if (xTurn) {
		mark = "X";
		getline(cin, move);
		row_idx = int(move[0] - 48);	// A little Cumbersome, it is mainly done to check the presence of spaces between the number. TODO: simplify this.
		col_idx = int(move[2] - 48);

		while (move[1] != ' ' || ((row_idx < 0 || col_idx < 0)) || ((row_idx > 2 || col_idx > 2)) || cellOccupied(row_idx, col_idx, gameBoard) == true) {

			cout << "Please type the correct indexes separated by a space:" << endl;
			getline(cin, move);
			row_idx = int(move[0] - 48);
			col_idx = int(move[2] - 48);

		};

	}
	else {

		mark = "O";
		row_idx = rand() % 3;	// A simple automatic opponent
		col_idx = rand() % 3;

		while ((row_idx < 0 || col_idx < 0) || (row_idx > 2 || col_idx > 2) || cellOccupied(row_idx, col_idx, gameBoard) == true) {

			cout << "Please type the correct indexes separated by a space:" << endl;
		
				row_idx = rand() % 3;
				col_idx = rand() % 3;
		};
	}

	gameBoard[row_idx][col_idx] = mark;
}

bool cellOccupied(int row, int col, string gameBoard[ROWS][COLS])
{
	if (gameBoard[row][col] != " ")
	{
		cout << "Cell is already occupied. ";
		return true;
	}
	return false;
}

string whoWins(string gameBoard[ROWS][COLS])
{
	// Rows winning condition
	for (int i = 0; i < COLS; i++)
	{
		if (gameBoard[i][0] != " " && gameBoard[i][0] == gameBoard[i][1] && gameBoard[i][1] == gameBoard[i][2])
			return gameBoard[i][0];
	}

	// Cols winning condition
	for (int i = 0; i < ROWS; i++)
	{
		if (gameBoard[0][i] != " " && gameBoard[0][i] == gameBoard[1][i] && gameBoard[1][i] == gameBoard[2][i])
			return gameBoard[0][i];
	}

	// diagonal top-left to bottom-right winning conditions
	if (gameBoard[0][0] != " " && gameBoard[0][0] == gameBoard[1][1] && gameBoard[1][1] == gameBoard[2][2])
		return gameBoard[0][0];


	// Checks winning condition for diagonal bottom - left to top - right
	if (gameBoard[2][0] != " " && gameBoard[2][0] == gameBoard[1][1] && gameBoard[1][1] == gameBoard[0][2])
		return gameBoard[0][2];

	return "";
}

bool isFull(string gameBoard[ROWS][COLS])
{

	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			if (gameBoard[i][j] == " ")
				return false;
		}
	}

	return true;
}
