#include <iostream>
#include <fstream>
#include "Report.h"

using namespace std;

int main()
{
	ifstream fin("mp4election.txt");

	Candidate c1;
	Report r1;

	fin >> r1;
	cout << r1;
}