#pragma once
#include <string>
#include <iostream>

using namespace std;

class StockType
{
	friend istream& operator>>(istream& is, StockType& rhs);
	friend ostream& operator<<(ostream& os, StockType& rhs);
private:
	string symbol = "";
	double	openPrice = 0.0,
		closePrice = 0.0,
		highPrice = 0.0,
		lowPrice = 0.0,
		prevPrice = 0.0,
		percentGainOrLoss = 0.0;
	int numOfShares = 0;
public:
	StockType();

	string retSymbol();

	void readData(istream& is);

	void dispData();
	void dispData(ostream& os);
	void calcGL();

	bool operator>(StockType& stock);
	bool operator<(StockType& stock);
};

template <typename T>
class StockListType
{
private:
	//vector<T> stockList;
public:

};