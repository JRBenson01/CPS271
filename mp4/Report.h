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
	void setVotes(int *arr);
	void setName(string name);

	void dispVotes();

	int retVoteSum();
};

class Report
{
protected:
	vector <Candidate> voteList;
	int voteTotals[3];
	int voteTotal = 0;
public:
	void readData();
	void dispData();
};

class FirstReport : public Report
{
private:
	int voteTotals[3];
	int voteTotalSum = 0;
public:

};

istream& operator>>(istream& is, Candidate& rhs);

ostream& operator<<(ostream& os, Candidate& rhs);

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