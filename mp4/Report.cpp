#include <fstream>
#include <iostream>
#include <iomanip>
#include <string>
#include "Report.h"

using namespace std;

const int nameLen = 15;
const int voteLen = 5;
const char tab = '\t';

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
			//voteTotals[i] += voteNums[i];
			//voteTotal += voteNums[i];
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
	char tab = '\t';
	cout << setw(nameLen) << name;
	for (int i = 0; i < 3; i++)
		cout << setw(voteLen) << votes[i];
	cout << setw(voteLen) << voteSum
		<< endl;
}

string Candidate::retName()
{
	return name;
}

int *Candidate::retVotes()
{
	return votes;
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
	//for (int i = 0; i < 3; i++)
		//cout << setw(voteLen) << voteTotals[i];
	//cout << voteTotal << endl;
}

void Report::addCand(Candidate cand)
{
	voteList.push_back(cand);
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

void FirstReport::addTotals(int *arr)
{
	for (int i = 0; i < 3; i++)
	{
		voteTotals[i] += arr[i];
		voteTotalSum += arr[i];
	}
}

istream& operator>>(istream& is, Candidate& rhs)
{
	is >> rhs.name;
	for (int i = 0; i < 3; i++)
	{
		is >> rhs.votes[i];
		rhs.voteSum += rhs.votes[i];
	}

	return is;
}

ostream& operator<<(ostream& os, Candidate& rhs)
{
	os << left << setw(nameLen) << rhs.name;
	for (int i = 0; i < 3; i++)
		os << setw(voteLen) << rhs.votes[i];
	os << setw(voteLen) << rhs.voteSum
		<< endl;

	return os;
}

istream& operator>>(istream& is, Report& rhs)
{
	while (!is.eof())
	{
		Candidate temp;
		is >> temp;
		rhs.addCand(temp);
	}


	return is;
}

ostream& operator<<(ostream& os, Report& rhs)
{
	os << left << setw(nameLen) << "Candidate"
		<< setw(voteLen) << "P1"
		<< setw(voteLen) << "P2"
		<< setw(voteLen) << "P3"
		<< setw(voteLen) << "Total"
		<< endl;
		

	for (int i = 0; i < rhs.voteList.size(); i++)
	{
		os << rhs.voteList[i];
	}
	
	return os;
}