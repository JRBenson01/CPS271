#pragma once
#include "tictac.h"
#include <iostream>

using namespace std;

tictac::tictac()
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			board[i][j] = ' ';
		}
	}
}


tictac::~tictac()
{
}

void tictac::print_board()
{
	cout << "   1  2  3 " << endl;
	for (int i = 0; i < 3; i++)
	{
		cout << i + 1;
		for (int j = 0; j < 3; j++)
		{
			cout << " " << board[i][j] << " ";
			if (j < 2)
				cout << "|";
		}
		if (i < 2)
			cout << endl << " ---+---+---";
		cout << endl;
	}
} 

bool tictac::place(int x, int y, char piece)
{
	if (board[y][x] == ' ')
	{
		board[y][x] = piece;
		return true;
	}
	else
	{
		return false;
	}
}

void tictac::Input(char piece)
{
	int x = 0, y = 0;
	bool validMove = false;

	while (!validMove)
	{
		cout << "Where to place? (x, y): ";
		cin >> x >> y;
		//reduce them by 1 to line up with array
		x--;
		y--;
		if (place(x, y, piece))
			validMove = true;
		else
			cout << "Invalid move. Try again" << endl;
	}
	board_checker(piece);
}

void tictac::set_gameStay(bool val)
{
	gameStay = val;
}

bool tictac::ret_gameStay()
{
	return gameStay;
}

bool tictac::hor_checker(char piece)
{
	for (int i = 0; i < 3; i++)
	{
		//cout << "Hor: " << "1:" << board[i][0] << " 2:" << board[i][1] << " 3:" << board[i][2] << endl;
		if (board[i][0] == piece && board[i][1] == piece && board[i][2] == piece)
			return true;
	}
	return false;
}

bool tictac::vert_checker(char piece)
{
	for (int i = 0; i < 3; i++)
	{
		//cout << "Vert: " << "1:" << board[0][i] << " 2:" << board[1][i] << " 3:" << board[2][i] << endl;
		if (board[0][i] == piece && board[1][i] == piece && board[2][i] == piece)
		{
			return true;
		}
	}
	return false;
}

bool tictac::slant_checker(char piece)
{
	if (board[0][0] == piece && board[1][1] == piece && board[2][2] == piece)
		return true;
	if (board[2][0] == piece && board[1][1] == piece && board[0][2] == piece)
		return true;
	return false;
}

void tictac::board_checker(char piece)
{
	if (vert_checker(piece) || hor_checker(piece) || slant_checker(piece))
	{
		gameStay = false;
		cout << "+++++ " << piece << " has won! +++++" << endl;
	}
}



/*
 Y | Y | Y 
-----------
*/