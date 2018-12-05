#include "pubs.h"
#include <iostream>

using namespace std;

Publication::Publication()
{
	cout << "Publication created " << endl;
}

void Publication::readData()
{
	cin.ignore(100, '\n');
	cin.clear();
	cout << "Enter Data: " << endl;
	cout << "Name: ";
	getline(cin, name);
	cout << "Price($): ";
	cin >> price;
	cin.ignore(100, '\n');
	cin.clear();
}

void Publication::dispData()
{
	cout << "Name: " << name << endl;
	cout << "Price: $" << price << endl;
}

void Sales::readData()
{
	cout << "Enter sales from the last 3 months: ";
	cin >> sales[0] >> sales[1] >> sales[2];
}

void Sales::dispData()
{
	cout << "Sales: ";
	for (int i = 0; i < 3; i++)
	{
		cout << "M" << i+1 << ": " << sales[i] << "\t";
	}
	cout << endl;
}

Book::Book()
{
	cout << "Book type created" << endl;
}

void Book::readData()
{
	Publication::readData();
	cout << "Number of Pages: ";
	cin >> pages;
	Sales::readData();
}

void Book::dispData()
{
	Publication::dispData();
	cout << "Number of Pages: " << pages << endl;
	Sales::dispData();
}

Tape::Tape()
{
	cout << "Tape type created" << endl;
}

void Tape::readData()
{
	Publication::readData();
	cout << "Time (minutes): ";
	cin >> time;
	Sales::readData();
}

void Tape::dispData()
{
	Publication::dispData();
	cout << "Time: " << time << " minutes" << endl;
}

