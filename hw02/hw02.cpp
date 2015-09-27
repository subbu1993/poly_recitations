/*
HW02
Subbu
Program that represents delegation in a warrior and a weapon
*/
#include<iostream>
#include<string>
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
