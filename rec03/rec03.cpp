/*
Rec 03
Subbu
This file stores molucules into an user-defined type called Molecules
*/

#include<iostream>
#include<string>
#include<vector>
#include<fstream>

using namespace std;

struct molecule
{
	int carbon, hydrogen;
	vector<string> names;
};

void openFile(ifstream&);
void readFromFile(ifstream&, vector<molecule>&);
void printMolecules(const vector<molecule>&);
int main()
{
	ifstream ifs;
	vector<molecule> molecules;
	openFile(ifs);
	readFromFile(ifs, molecules);
	printMolecules(molecules);
}

void openFile(ifstream& ifs)
{
	ifs.open("hydrocarbons.txt");
	if (!ifs)
	{
		cerr << "File cannot be opened";
		exit(1);
	}
}

void readFromFile(ifstream& ifs, vector<molecule>& molecules)
{
	int numberOfCarbons, numberOfHydrogens;
	string name;
	char junk;
  bool exists = true;
	while (ifs >> name >> junk >> numberOfCarbons >> junk >> numberOfHydrogens)
	{
		for (size_t i = 0; i < molecules.size(); i++)
		{
			if ((molecules[i].carbon == numberOfCarbons) && (molecules[i].hydrogen == numberOfHydrogens))
			{
				molecules[i].names.push_back(name);
        exists = false;
			}
		}
    if(exists)
    {
  		molecule aMolecule;
  		aMolecule.carbon = numberOfCarbons;
  		aMolecule.hydrogen = numberOfHydrogens;
  		aMolecule.names.push_back(name);
  		molecules.push_back(aMolecule);
    }
    exists = true;
	}
}

void printMolecules(const vector<molecule>& molecules)
{
	for (size_t i = 0; i<molecules.size(); i++)
	{
		cout << 'C' << molecules[i].carbon << 'H' << molecules[i].hydrogen << endl;
		for (const string& name : molecules[i].names)
		{
			cout << name << endl;
		}
    cout << endl;
	}
}
