/*
HW02
Subbu
Program that represents delegation in a warrior and a weapon
*/
#include<iostream>
#include<string>
#include<fstream>
using namespace std;

class Weapon
{// a type that represents a warrior's weapon. It has two fields a name and a strength
  string name;
  int strength;
};

class Warrior
{// a type that represents a warrior. It has two fields a name and a weapon... composition
  string name;
  Weapon weapon;
};

int main()
{
  ifstream ifs;
  openFile(ifs);
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
