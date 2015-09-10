/*
	New Rec 02
	Subbu
	This file reads from a text file containing chemical formulas of molecules and their names and stores them in a vector of vector of strings
	It also prints the molecules using two different types of for loops: iterative and
*/
#include<iostream>
#include<vector>
#include<string>
#include<fstream>
using namespace std;
void openFile(ifstream&);
void readFileContents(ifstream&,vector<vector<string>>&);
int main()
{
	vector<vector<string>> molecules;
	ifstream ifs;
	openFile(ifs);
	readFileContents(ifs,molecules);
}

void openFile(ifstream& ifs)
{
	ifs.open("C:\\Users\\Subramaniam\\Downloads\\chemicals.txt");
	if(!ifs)
	{
		cerr << "File cannot be opened";
		exit(0);
	}
}

void readFileContents(ifstream& ifs,vector<vector<string>>& molecules)
{
	string name,formula;
	while(ifs >> name >> formula)
	{
		vector<string> molecule;
		molecule.push_back(name);
		molecule.push_back(formula);
		molecules.push_back(molecule);
	}
}
