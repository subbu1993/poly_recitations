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
void printByConventionalFor(vector<vector<string>>&);
void printByRangedFor(vector<vector<string>>&);
int main()
{
	vector<vector<string>> molecules;
	ifstream ifs;
	openFile(ifs);
	readFileContents(ifs,molecules);
	ifs.close();
	printByConventionalFor(molecules);
	printByRangedFor(molecules);
}

void openFile(ifstream& ifs)
{
	//Function that tries to open the file or terminates the program on an unsuccessful file open
	ifs.open("C:\\Users\\Subramaniam\\Downloads\\chemicals.txt");
	if(!ifs)
	{
		cerr << "File cannot be opened";
		exit(0);
	}
}

void readFileContents(ifstream& ifs,vector<vector<string>>& molecules)
{
	// Function that reads each line pushing back the formula and the name into the molecules vector
	string name,formula;
	while(ifs >> name >> formula)
	{
		vector<string> molecule;
		molecule.push_back(name);
		molecule.push_back(formula);
		molecules.push_back(molecule);
	}
}
void printByConventionalFor(vector<vector<string>>& molecules)
{
	// Function that loops through the vector using the conventional for loop
	for(size_t i=0;i<molecules.size();i++)
	{
		cout << molecules[i][1] << ' ' << molecules[i][0] << endl;
	}
	cout << "=======================" << endl;
}
void printByRangedFor(vector<vector<string>>& molecules)
{
	// Function that loops through the vector using the Ranged for loop 
	for(vector<string> molecule : molecules)
	{
		cout << molecule[1] << ' ' << molecule[0] << endl;
	}
}
