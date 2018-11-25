#include <string>
#include <iostream>
#include <fstream>
#include "StockType.h"

using namespace std;

int main()
{
	StockType s1;
	StockListType stocks;

	ifstream fin("mp5input.txt");
	ofstream fout("mp5output.txt");

	stocks.readData(fin);
	stocks.dispData(fout);
}