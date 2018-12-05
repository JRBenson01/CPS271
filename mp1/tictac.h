#pragma once
class tictac
{
private:
	char board[3][3];
	bool gameStay = true;
public:
	tictac();
	~tictac();
	void print_board();
	bool place(int x, int y, char piece);
	void Input(char piece);
	void set_gameStay(bool val);
	bool ret_gameStay();
	bool hor_checker(char piece);
	bool vert_checker(char piece);
	bool slant_checker(char piece);
	void board_checker(char piece);
};