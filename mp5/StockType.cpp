#include <string>
#include <iostream>
#include "StockType.h"

using namespace std;

StockType::StockType()
{

}

string StockType::retSymbol()
{
	return symbol;
}

istream& operator>>(istream& is, StockType rhs)
{
	
}

ostream& operator<<(ostream& os, const StockType rhs)
{

}

bool StockType::operator<(StockType& stock)
{
	return this->symbol < stock.retSymbol();
}

bool StockType::operator>(StockType& stock)
{
	return this->symbol > stock.retSymbol();
}

void StockType::readData()
{

}

void StockType::dispData()
{

}

void StockType::calcGL()
{

}