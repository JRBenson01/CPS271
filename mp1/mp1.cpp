#include <iostream>
#include "tictac.h"

using namespace std;

int main()
{
	char end;
	tictac board;

	board.print_board();
	char player = 'X';
	while (board.ret_gameStay())
	{
		
		cout << "It's " << player << "'s turn!" << endl;
		board.Input(player);
		board.print_board();
		if (player == 'X')
			player = 'O';
		else
			player = 'X';
	}
	
	cout << "GAME OVER." << endl;

	return 0;
}
/*
cout << "It's O's turn!" << endl;
board.Input('O');
board.print_board();
*/