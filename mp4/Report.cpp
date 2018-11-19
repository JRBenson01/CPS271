#include <fstream>
#include <iostream>
#include <string>
#include "Report.h"

using namespace std;

void Report::readData()
{
	cout << "Reading data..." << endl;
	ifstream fin("mp4election.txt");
	if (fin.is_open())
		cout << "File found" << endl;
	else
		cout << "ERROR: File not found" << endl;
	
	int cand = 0;
	string name;
	while (fin)
	{
		fin >> name;
		for (int i = 0; i < 3; i++)
		{
			fin >> votes[cand][i];
			cout << "Added " << votes[cand][i] << " to " << name << endl;
		}
		cand++;
	}
	fin.close();
}