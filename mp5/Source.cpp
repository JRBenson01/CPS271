#include <string>
#include <iostream>
#include <fstream>
#include "StockType.h"

using namespace std;

int main()
{
	StockType s1;

	ifstream fin("mp5input.txt");

	fin >> s1;

	cout << s1;
}