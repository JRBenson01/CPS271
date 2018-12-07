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

	if (!fin)
		cout << "ERROR: Could not find file." << endl;

	stocks.readData(fin);
	stocks.dispData(cout);
	cout << endl << endl;

	stocks.sortData();

	stocks.dispData(cout);
	stocks.dispData(fout);
}