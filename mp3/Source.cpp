#include "pubs.h"
#include <iostream>

using namespace std;

int main()
{
	Book foo;
	Book *bar = &foo;

	int i = 0;
	Publication *pubs[5];

	for (int i = 0)

	(*pubs)[0].readData();

	cout << &foo << endl;
	cout << bar << endl;

	//foo.readData();

	//for (i = 0; i < 2; i++)
	//	pubs[i] = new Book();

	//for (i; i < 5; i++)
	//	pubs[i] = new Tape();

	//for (int i = 0; i < sizeof(*pubs); i++)
	//	pubs[i]->readData();

	//for (int i = 0; i < sizeof(*pubs); i++)
	//	pubs[i]->dispData();
}
