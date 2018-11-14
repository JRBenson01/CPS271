#include "pubs.h"
#include <iostream>

using namespace std;

int main()
{
	Book cunt;
	Book *fuck = &cunt;


	int i = 0;
	Publication *pubs[5];
	*pubs = &cunt;

	cout << &cunt << " " << fuck << endl;
	cout << pubs[0] << endl;

	//for (i = 0; i < 2; i++)
	//	pubs[i] = new Book();

	//for (i; i < 5; i++)
	//	pubs[i] = new Tape();

	//for (int i = 0; i < sizeof(*pubs); i++)
	//	pubs[i]->readData();

	//for (int i = 0; i < sizeof(*pubs); i++)
	//	pubs[i]->dispData();
}