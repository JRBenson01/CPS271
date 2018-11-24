#pragma once
#include <string>

using namespace std;

class StockType
{
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
	void readData();
	void dispData();
	void calcGL();
};

template <typename T>
class StockListType
{
private:
	vector<T> stockList;
public:

};