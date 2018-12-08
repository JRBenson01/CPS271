#include <fstream>
#include <iostream>
#include <iomanip>
#include <string>
#include "Report.h"

using namespace std;

void Candidate::setVotes(int *arr)
{
	for (int i = 0; i < 3; i++)
	{
		votes[i] = arr[i];
		voteSum += votes[i];
	}
}

void Candidate::setName(string name)
{
	this->name = name;
}

void Report::readData()
{
	cout << "Reading data..." << endl;
	ifstream fin("mp4election.txt");
	if (fin)
		cout << "File found" << endl;
	else
		cout << "ERROR: File not found." << endl;

	while (!fin.eof())
	{
		string name = "";
		int *voteNums = new int[3];
		Candidate temp;
		fin >> name;
		for (int i = 0; i < 3; i++)
		{
			fin >> voteNums[i];
			voteTotals[i] += voteNums[i];
			voteTotal += voteNums[i];
		}

		temp.setName(name);
		temp.setVotes(voteNums);

		voteList.push_back(temp);
	}
	fin.close();
	cout << endl << endl;
}

void Candidate::dispVotes()
{
	const int nameLen = 15;
	const int voteLen = 5;
	char tab = '\t';
	cout << setw(nameLen) << name;
	for (int i = 0; i < 3; i++)
		cout << setw(voteLen) << votes[i];
	cout << setw(voteLen) << voteSum
		<< endl;
}

int Candidate::retVoteSum()
{
	return voteSum;
}

void Report::dispData()
{
	const int nameLen = 15;
	const int voteLen = 5;
	cout << left << setw(nameLen) << "Candidate"
		<< setw(voteLen) << "P1"
		<< setw(voteLen) << "P2"
		<< setw(voteLen) << "P3"
		<< setw(voteLen) << "Total"
		<< endl;
	for (int i = 0; i < voteList.size(); i++)
	{
		voteList[i].dispVotes();
	}
	cout << setw(nameLen) << "Total";
	for (int i = 0; i < 3; i++)
		cout << setw(voteLen) << voteTotals[i];
	cout << voteTotal << endl;
}

//void Report::readData()
//{
//	cout << "Reading data..." << endl;
//	ifstream fin("mp4election.txt");
//	if (fin.is_open())
//		cout << "File found" << endl;
//	else
//		cout << "ERROR: File not found" << endl;
//	
//	int cand = 0;
//	string name;
//	while (!fin.eof())
//	{
//		fin >> name;
//		for (int i = 0; i < 3; i++)
//		{
//			fin >> votes[cand][i];
//			cout << "Added " << votes[cand][i] << " to " << name << endl;
//		}
//		cand++;
//	}
//	fin.close();
//}

istream& operator>>(istream& is, Candidate& rhs)
{
	
}

ostream& operator<<(ostream& os, Candidate& rhs)
{

}