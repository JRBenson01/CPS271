#include <string>
#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include "StockType.h"

using namespace std;

StockType::StockType()
{
	
}

string StockType::retSymbol()
{
	return symbol;
}

istream& operator>>(istream& is, StockType& rhs)
{
	rhs.readData(is);
	return is;
}

ostream& operator<<(ostream& os, StockType& rhs)
{
	rhs.dispData(os);
	return os;
}

bool StockType::operator<(StockType& stock)
{
	return this->symbol < stock.retSymbol();
}

bool StockType::operator>(StockType& stock)
{
	return this->symbol > stock.retSymbol();
}

void StockType::readData(istream& is)
{
	is >> symbol
		>> openPrice
		>> closePrice
		>> highPrice
		>> lowPrice
		>> prevPrice
		>> numOfShares;
}

void StockType::dispData()
{
	cout << symbol << endl
		<< openPrice << endl
		<< closePrice << endl
		<< highPrice << endl
		<< lowPrice << endl
		<< prevPrice << endl
		<< numOfShares << endl;
}

void StockType::dispData(ostream& os)
{
	const int len = 8;

	calcGL();

	os << left << setprecision(2) << fixed
		<< setw(len) << symbol
		<< right
		<< setw(len) << openPrice 
		<< setw(len) << closePrice 
		<< setw(len) << highPrice 
		<< setw(len) << lowPrice
		<< setw(10) << " "
		<< setw(20) << prevPrice
		<< setw(10) << " "
		<< setw(len) << numOfShares 
		<< setw(len) << percentGainOrLoss << "%"
		<< endl;
}

double StockType::calcGL()
{
	percentGainOrLoss = ((closePrice - prevPrice) / prevPrice) * 100;
	return percentGainOrLoss;
}

void StockListType::readData(istream& fin)
{
	int count = 0;
	while (!fin.eof())
	{
		StockType temp;
		fin >> temp;
		stockList.push_back(temp);
	}
}

void StockListType::dispData(ostream& os)
{
	char tab = '\t';
	const int len = 8;

	os << right
		<< setw(20) << "Today"
		<< setw(52) << "Yesterday"
		<< setw(28) << "Percent";

	os << endl;

	os << left 
		<< setw(len) << "SYM" 
		<< right
		<< setw(len) << "OPEN" 
		<< setw(len) << "CLOSE" 
		<< setw(len) << "HIGH" 
		<< setw(len) << "LOW";

	os << setw(10) << " ";

	os << setw(20) << "CLOSE"
		<< setw(10) << " "
		<< setw(len) << "SHARES"
		<< right << setw(len) << "G/L"
		<< endl;
	for (int i = 0; i < stockList.size(); i++)
	{
		os << stockList[i];
	}
}

void StockListType::sortData()
{
	sort(stockList.begin(), stockList.end());
}