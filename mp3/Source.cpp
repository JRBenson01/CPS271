#include "pubs.h"
#include <iostream>

using namespace std;

int main()
{
	//Publication *pubs = nullptr;

	Publication *pubs[5];

	pubs[0] = new Book();

	pubs[0]->readData();
	pubs[0]->dispData();

	return 0;
}
