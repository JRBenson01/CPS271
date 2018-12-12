#include "Report.h"
#include <iostream>
#include <iomanip>
<<<<<<< HEAD
#include <fstream>
=======
>>>>>>> 7264a62a4c9d8774a8bf9f8103f406c6dffbde28
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

const int nameLen = 15;
<<<<<<< HEAD
const int voteLen = 8;

istream& operator>>(istream& is, Candidate& rhs)
{
	string name = "";
	int *tempVotes = new int[3];
	is >> name;
	for (int i = 0; i < 3; i++)
	{
		is >> tempVotes[i];
	}
	rhs.setName(name);
	rhs.setVotes(tempVotes);

	return is;
}

ostream& operator<<(ostream& os, Candidate& rhs)
{
	int *tempVotes = rhs.getVotes();
	double *tempPrcs = rhs.getVotePrcs();

	os << left << setw(nameLen) << rhs.getName() << right;
	if (rhs.getDispType() == 0)
	{
=======
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
>>>>>>> 7264a62a4c9d8774a8bf9f8103f406c6dffbde28
		for (int i = 0; i < 3; i++)
			os << setw(voteLen) << tempVotes[i];
		os << setw(voteLen) << rhs.getTotalVotes();
	}
	else if (rhs.getDispType() == 1)
	{
		for (int i = 0; i < 3; i++)
			os << setw(voteLen) << tempPrcs[i] << '%';
	}
	else
	{
		os << setw(voteLen) << rhs.getTotalVotes()
			<< setw(voteLen) << rhs.getTotalVotePrc();
	}
	os << endl;

	return os;
}

bool Candidate::operator>(Candidate & rhs)
{
	return this->getTotalVotes() > rhs.getTotalVotes();
}

bool Candidate::operator<(Candidate & rhs)
{
	return this->getTotalVotes() < rhs.getTotalVotes();
}

void Candidate::calcTotalVotePrc(int t)
{
	totalVotePrc = (static_cast<double>(totalVotes) / t) * 100;
}

void Candidate::setName(string n)
{
	name = n;
}

void Candidate::setVotes(int *arr)
{
	for (int i = 0; i < 3; i++)
	{
		votes[i] = arr[i];
		totalVotes += votes[i];
	}
}

void Candidate::setVotePrcs(double * arr)
{
	for (int i = 0; i < 3; i++)
		votePrcs[i] = arr[i];
}

void Candidate::setTotalVotePrc(double t)
{
	totalVotePrc = t;
}

void Candidate::setDispType(int t)
{
	dispType = t;
}

string Candidate::getName()
{
	return name;
}

int *Candidate::getVotes()
{
	return votes;
}

double * Candidate::getVotePrcs()
{
	return votePrcs;
}

double Candidate::getTotalVotePrc()
{
	return totalVotePrc;
}

int Candidate::getTotalVotes()
{
	return totalVotes;
}

int Candidate::getDispType()
{
	return dispType;
}

void Report::readData(istream& is)
{
	while (!is.eof())
	{
		Candidate temp;
		is >> temp;
		candList.push_back(temp);
	}
}

void Report::dispData(ostream& os)
{
	for (int i = 0; i < candList.size(); i++)
	{
		os << candList[i];
	}
	cout << endl << endl;
}

void Report::addCand(Candidate c)
{
	candList.push_back(c);
}

//void FirstReport::readData(istream& is)
//{
//	Report::readData(is);
//}

void FirstReport::calcData()
{
	for (int i = 0; i < candList.size(); i++)
	{
		for (int j = 0; j < 3; j++)
		{
			voteTotals[j] += candList[i].getVotes()[j];
			totalVoteSum += candList[i].getVotes()[j];
		}
	}
	Candidate temp;
	temp.setName("Total");
	temp.setVotes(voteTotals);
	candList.push_back(temp);
}

void FirstReport::dispData(ostream& os)
{
	os << left << setw(nameLen) << "Candidate" << right
		<< setw(voteLen) << "P1"
		<< setw(voteLen) << "P2"
		<< setw(voteLen) << "P3"
		<< setw(voteLen) << "Total"
		<< endl;
	Report::dispData(os);
}


void SecondReport::calcData()
{
	FirstReport::calcData();
	int *totals = candList.back().getVotes();
	for (int i = 0; i < candList.size() - 1; i++)
	{
		candList[i].setDispType(1);
		double vShare[3];
		int *vAmt = candList[i].getVotes();
		for (int j = 0; j < 3; j++)
		{
<<<<<<< HEAD
			//cout << "vAmt: " << vAmt[j] << '\t' << "totals: " << totals[j] << endl;
			vShare[j] = (static_cast<double>(vAmt[j]) / totals[j]) * 100;
			//cout << "Percent: " << vShare[j] << '%' << endl;
		}
		candList[i].setVotePrcs(vShare);
	}
	candList.erase(candList.end() - 1);
}

void SecondReport::dispData(ostream & os)
{
	os << left << setprecision(1) << fixed
		<< setw(nameLen) << "Candidate" << right
		<< setw(voteLen) << "P1" << ' '
		<< setw(voteLen) << "P2" << ' '
		<< setw(voteLen) << "P3"
		<< endl;
	Report::dispData(os);
}

void ThirdReport::calcData()
{
	FirstReport::calcData();
	candList.erase(candList.end() - 1);
	for (int i = 0; i < candList.size(); i++)
	{
		candList[i].setDispType(2);
		candList[i].calcTotalVotePrc(totalVoteSum);
	}
	sort(candList.begin(), candList.end());
	reverse(candList.begin(), candList.end());
}

void ThirdReport::dispData(ostream & os)
{
	os << left << setprecision(1) << fixed
		<< setw(nameLen) << "Candidate" << right
		<< setw(voteLen) << "Total"
		<< setw(voteLen) << "Vote%"
		<< endl;
	Report::dispData(os);
}
=======
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
>>>>>>> 7264a62a4c9d8774a8bf9f8103f406c6dffbde28
