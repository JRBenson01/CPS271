#include "pubs.h"
#include <iostream>

using namespace std;

int main()
{
	//Publication *pubs = nullptr;

	Publication **pubs = new Publication*[5];

	for (int i = 0; i < 5; i++)
	{
		char bt;
		cout << "Book or tape?: ";
		cin >> bt;
		switch (bt)
		{
		case 'b': pubs[i] = new Book(); break;
		case 't': pubs[i] = new Tape(); break;
		default: i = 5; break;
		}
		pubs[i]->readData();
	}

	pubs[0] = new Book();

	pubs[0]->readData();
	pubs[0]->dispData();

	return 0;
}
