#include <string>
#include <iostream>
#include "StockType.h"

using namespace std;

StockType::StockType()
{
	cout << "Stock created" << endl;
}

string StockType::retSymbol()
{
	return symbol;
}

istream& operator>>(istream& is, StockType& rhs)
{
	cout << "Getting data" << endl;
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
	os << symbol << endl
		<< openPrice << endl
		<< closePrice << endl
		<< highPrice << endl
		<< lowPrice << endl
		<< prevPrice << endl
		<< numOfShares << endl;
}

void StockType::calcGL()
{

}