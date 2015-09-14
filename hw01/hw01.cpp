/*
  HW01
  Subbu
  A program that programs a game of medieval times
*/

#include<iostream>
#include<string>
#include<fstream>
#include<vector>

using namespace std;

struct warrior;
void openFile(ifstream&);
void readFromFile(ifstream&, vector<warrior>&);
void addWarrior(const string&,const int,vector<warrior>& );
void printWarriors(const vector<warrior>&);
struct warrior
{
  string name;
  int strength;
};
int main()
{
  ifstream ifs;
  vector<warrior> warriors;
  openFile(ifs);
  readFromFile(ifs,warriors);
}


void openFile(ifstream& ifs)
{
  ifs.open("warriors.txt");
  if(!ifs)
  {
    cerr << "Cannot open file";
    exit(1);
  }
}

void readFromFile(ifstream& ifs, vector<warrior>& warriors)
{
  string command;
  while(ifs >> command)
  {
      if(command == "Warrior")
      {
        string name;
        int strength;
        ifs >> name >> strength;
        addWarrior(name,strength,warriors);
      }
      else if(command == "Status")
      {
        printWarriors(warriors);
      }
      else
      {

      }
  }
}

void addWarrior(const string& name,const int strength,vector<warrior>& warriors)
{
  warrior aWarrior;
  aWarrior.name = name;
  aWarrior.strength = strength;
  warriors.push_back(aWarrior);
}

void printWarriors(const vector<warrior>& warriors)
{
  cout << "There are " << warriors.size() << " warriors";
  for(size_t i = 0; i < warriors.size(); i++)
  {
    cout << "Warrior: " << warriors[i].name << " Strength: " << warriors[i].strength << endl;
  }
}
