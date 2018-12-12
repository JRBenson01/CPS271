#include <iostream>
#include <fstream>
#include "Report.h"

using namespace std;

int main()
{
	ifstream fin("mp4election.txt");

<<<<<<< HEAD
	FirstReport fr1;
	SecondReport sr1;
	ThirdReport tr1;

	fr1.readData(fin);
	fr1.calcData();
	fr1.dispData(cout);

	fin.clear();
	fin.seekg(0);

	sr1.readData(fin);
	sr1.calcData();
	sr1.dispData(cout);

	fin.clear();
	fin.seekg(0);

	tr1.readData(fin);
	tr1.calcData();
	tr1.dispData(cout);

	return 0;
=======
	Candidate c1;
	Report r1;

	fin >> r1;
	cout << r1;
>>>>>>> 7264a62a4c9d8774a8bf9f8103f406c6dffbde28
}