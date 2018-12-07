#include <string>
#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include "StockType.h"

using namespace std;

StockType::StockType()
{
	//cout << "Stock created" << endl;
}

string StockType::retSymbol()
{
	return symbol;
}

istream& operator>>(istream& is, StockType& rhs)
{
	//cout << "Getting data" << endl;
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

	os << setw(len)
		<< symbol << setw(len)
		<< openPrice << setw(len)
		<< closePrice << setw(len)
		<< highPrice << setw(len)
		<< lowPrice
		<< setw(20) << " "
		<< setw(len)
		<< prevPrice << setw(len)
		<< percentGainOrLoss
		<< endl;


	//char tab = '\t';

	//os << symbol << tab 
	//	<< openPrice << tab
	//	<< closePrice << tab
	//	<< highPrice << tab
	//	<< lowPrice << tab
	//	<< prevPrice << tab
	//	<< numOfShares << tab
	//	<< endl;
}

double StockType::calcGL()
{
	percentGainOrLoss = (closePrice - prevPrice) / (prevPrice * 100);
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
		<< setw(45) << "Yesterday";

	os << endl;

	os << left << setw(len)
		<< "SYM" << setw(len)
		<< "OPEN" << setw(len)
		<< "CLOSE" << setw(len)
		<< "HIGH" << setw(len)
		<< "LOW";

	os << setw(20) << " ";

	os << setw(len) << "CLOSE"
		<< setw(len) << "SHARES"
		<< setw(len) << "G/L"
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