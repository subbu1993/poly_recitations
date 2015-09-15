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
bool findWarrior(const string&, const vector<warrior>&);
void battle(const string&,const string&,vector<warrior>&);
int findWarriorIndex(const string&,const vector<warrior>&);

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
{ //treis to open the warriors text file or terminates the program on an unsuccesful open
  ifs.open("warriors.txt");
  if(!ifs)
  {
    cerr << "Cannot open file";
    exit(1);
  }
}

void readFromFile(ifstream& ifs, vector<warrior>& warriors)
{ // reads from file and based on the command word calls a function to do battle/ add warrior/ to print status
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
        string warrior1,warrior2;
        ifs >> warrior1 >> warrior2;
        battle(warrior1,warrior2,warriors);
      }
  }
}

void addWarrior(const string& name,const int strength,vector<warrior>& warriors)
{
  if(!findWarrior(name,warriors))
  {
    warrior aWarrior;
    aWarrior.name = name;
    aWarrior.strength = strength;
    warriors.push_back(aWarrior);
  }
  else
  {
    cout << "Warrior already exists";
  }
}

bool findWarrior(const string& name, const vector<warrior>& warriors)
{
  for(size_t i = 0; i < warriors.size(); i++)
  {
    if(warriors[i].name == name)
    {
      return true;
    }
  }
  return false;
}
void printWarriors(const vector<warrior>& warriors)
{
  cout << "There are " << warriors.size() << " warriors" << endl;
  for(size_t i = 0; i < warriors.size(); i++)
  {
    cout << "Warrior: " << warriors[i].name << " Strength: " << warriors[i].strength << endl;
  }
}

void battle(const string& warrior1, const string& warrior2,vector<warrior>& warriors)
{
  int index1 = findWarriorIndex(warrior1,warriors);
  int index2 = findWarriorIndex(warrior2,warriors);

  cout << warrior1 << " battles " << warrior2 << endl;
  int strength1 = warriors[index1].strength;
  int strength2 = warriors[index2].strength;

  if(strength1 ! = 0 && strength2 != 0)
  {
    if(strength1 > strength2)
    {
      warriors[index2].strength = 0;
      cout << warriors[index1].name << " defeats " << warriors[index2].name << endl;
    }

    else if(strength2 > strength1)
    {
      warriors[index1].strength = 0;
      cout << warriors[index2].name << " defeats " << warriors[index1].name << endl;
    }
    else
    {
      warriors[index1].strength = 0;
      warriors[index2].strength = 0;
      cout << "Mutual annihilation: " << warriors[index1].name << " and " << warriors[index2].name << " die at each other's hands" << endl;
    }
  }
  else if(strength1 == 0)
  {
    cout << "He's dead, " << warriors[index2].name << endl;
  }
  else if(strength2 == 0)
  {
    cout << "He's dead, " << warriors[index1].name << endl;
  }
  else
  {
    cout << "Oh, NO! They're both dead! Yuck!" << endl;
  }
}

int findWarriorIndex(const string& warrior_name,const vector<warrior>& warriors)
{
  for(size_t i = 0; i < warriors.size(); i++)
  {
    if(warriors[i].name == warrior_name)
    {
      return i;
    }
  }
  return warriors.size();
}
