#include "pubs.h"
#include <iostream>

using namespace std;

int main()
{
	int size = 0;

	Publication **pubs = new Publication*[5];

	for (int i = 0; i < 5; i++)
	{
		char bt;
		cout << "Book or tape?: ";
		cin >> bt;
		if (bt == 'b')
			pubs[i] = new Book();
		else if (bt == 't')
			pubs[i] = new Tape();
		else
			break;
		pubs[i]->readData();
		size++;
	}

	for (int i = 0; i < size; i++)
	{
		pubs[i]->dispData();
		cout << endl;
	}

	return 0;
}
