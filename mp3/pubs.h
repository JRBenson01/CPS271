#pragma once
#include <string>

using namespace std;

class Publication
{
protected:
	string name = "";
	double price = 0.0;
public:
	Publication();
	//Publication(string t = "TBD", double p = 0.0) : name(t), price(p) {}
	virtual void readData();
	virtual void dispData();
};

class Sales
{
private:
	int sales[3];
public:
	void readData();
	void dispData();
};

class Book : public Publication, public Sales
{
private:
	int pages = 0;
public:
	Book();
	void readData();
	void dispData();
};

class Tape : public Publication, public Sales
{
private:
	double time = 0.0;
public:
	Tape();
	void readData();
	void dispData();
};
