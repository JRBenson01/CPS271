#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

class Candidate
{
private:
	string name = "";
	int votes[3];
	int voteSum = 0;
public:
	friend istream& operator>>(istream& is, Candidate& rhs);
	friend ostream& operator<<(ostream& os, Candidate& rhs);

	void setVotes(int *arr);
	void setName(string name);

	void dispVotes();

	string retName();
	int *retVotes();
	int retVoteSum();
};

class Report
{
protected:
	vector <Candidate> voteList;
	//int voteTotals[3];
	//int voteTotal = 0;
public:
	friend istream & operator>>(istream& is, Report& rhs);
	friend ostream& operator<<(ostream& os, Report& rhs);

	virtual void readData();
	virtual void dispData();

	void addCand(Candidate cand);
};

class FirstReport : public Report
{
private:
	int voteTotals[3];
	int voteTotalSum = 0;
public:
	void addTotals(int *arr);
};


//void Report::readData()
//{
//	cout << "Reading data..." << endl;
//	ifstream fin("mp4election.txt");
//	if (fin)
//		cout << "File found" << endl;
//	else
//		cout << "ERROR: File not found." << endl;
//
//	while (!fin.eof())
//	{
//		string name = "";
//		int *voteNums = new int[3];
//		Candidate temp;
//		fin >> name;
//		for (int i = 0; i < 3; i++)
//		{
//			fin >> voteNums[i];
//			voteTotals[i] += voteNums[i];
//			voteTotal += voteNums[i];
//		}
//
//		temp.setName(name);
//		temp.setVotes(voteNums);
//
//		voteList.push_back(temp);
//	}
//	fin.close();
//	cout << endl << endl;
//}

//char tab = '\t';
//cout << setw(nameLen) << name;
//for (int i = 0; i < 3; i++)
//	cout << setw(voteLen) << votes[i];
//cout << setw(voteLen) << voteSum
//<< endl;

//cout << left << setw(nameLen) << "Candidate"
//<< setw(voteLen) << "P1"
//<< setw(voteLen) << "P2"
//<< setw(voteLen) << "P3"
//<< setw(voteLen) << "Total"
//<< endl;
//for (int i = 0; i < voteList.size(); i++)
//{
//	voteList[i].dispVotes();
//}
//cout << setw(nameLen) << "Total";