/*
HW02
Subbu
Program that represents delegation in a warrior and a weapon
*/
#include<iostream>
#include<string>
#include<fstream>
#include<vector>
using namespace std;

class Weapon
{// a type that represents a warrior's weapon. It has two fields a name and a strength
  string name;
  int strength;

  public:
    string getName() const
    {// accessor for name
      return name;
    }

    int getStrength() const
    {// accessor for strength
      return strength;
    }

};

class Warrior
{// a type that represents a warrior. It has two fields a name and a weapon... composition
  string name;
  Weapon weapon;

  public:
    string getName() const
    {// accessor for name
      return name;
    }

    string getWeaponName() const
    {// delegation of task to the weapon class
      return weapon.getName();
    }

    int getWeaponStrength() const
    {// delegation of task to the weapon class
      return weapon.getStrength();
    }

};

void openFile(ifstream&);
void readFromFile(ifstream&,vector<Warrior>&);


int main()
{
  ifstream ifs;
  openFile(ifs);
  readFromFile(ifs);
}

void openFile(ifstream& ifs)
{ // a function to check if the input file can be opened, in case it cannot be opened the program terminates
  ifs.open("warriors.txt");
  if(!ifs)
  {
    cerr << " File cannot be opened ";
    exit(1);
  }
}

void readFromFile(ifstream& ifs,vector<Warrior>& warriors)
{//function that reads the input file and processes the commmands

  string command;

  while(ifs >> command)
  {
    if (command == "Status")
    {
      printWarriors(warriors)
    }

    else if(command == "Warrior")
    {

    }

    else if(command == "Battle")
    {

    }
  }

}

void printWarriors(const vector<Warrior>& warriors)
{
  cout << "There are " << warriors.size() << " warriors";
  for(size_t i = 0;i<warriors.size();i++)
  {
    cout << "Warrior: " << warriors[i].getName() << " , Weapon: " << warriors[i].getWeaponName() <<", " << warriors[i].getWeaponStrength();
  }

}
