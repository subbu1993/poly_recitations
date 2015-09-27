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

	void setStrength(int strength)
	{// method to set the weapon strength
		this->strength = strength;
	}

	Weapon() {}

	Weapon(const string& name, int strength) : name(name), strength(strength) {}

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

	void die()
	{//method which sets the weapons strength to 0
		weapon.setStrength(0);
	}

	void reduceStrength(int newStrength)
	{//method to reduce the strength of the weapon, delegation again
		weapon.setStrength(newStrength);
	}

	Warrior() {}
	Warrior(const string& name, const string& weaponName, int strength) : name(name), weapon(weaponName, strength) {}

	void battle(Warrior& warrior2)
	{//method foe warriors to do battle
		int strength1 = getWeaponStrength();
		int strength2 = warrior2.getWeaponStrength();

		if (strength1 == 0 && strength2 == 0)
		{
			cout << "Oh, NO! They're both dead! Yuck!" << endl;
		}

		else if (strength2 == 0)
		{
			cout << "He's dead, " << getName() << endl;
		}

		else if (strength1 == 0)
		{
			cout << "He's dead, " << warrior2.getName() << endl;
		}

		else if (strength1 == strength2)
		{
			cout << " Mutual Annihilation: " << getName() << " and " << warrior2.getName() << " die at each other's hands " << endl;
			die();
			warrior2.die();
		}

		else if (strength1 > strength2)
		{
			cout << getName() << " defeats " << warrior2.getName() << endl;
			warrior2.die();
			reduceStrength((strength1 - strength2));
		}
		else if (strength1 < strength2)
		{
			cout << warrior2.getName() << " defeats " << getName() << endl;
			die();
			warrior2.reduceStrength(strength2 - strength1);
		}
	}

};

void openFile(ifstream&);
void readFromFile(ifstream&, vector<Warrior>&);
void printWarriors(const vector<Warrior>&);
void addWarrior(const string&, const string&, int, vector<Warrior>&);
int findWarrior(const string&, const vector<Warrior>&);
int main()
{
	ifstream ifs;
	openFile(ifs);
	vector<Warrior> warriors;
	readFromFile(ifs, warriors);
}

void openFile(ifstream& ifs)
{ // a function to check if the input file can be opened, in case it cannot be opened the program terminates
	ifs.open("warriors.txt");
	if (!ifs)
	{
		cerr << " File cannot be opened ";
		exit(1);
	}
}

void readFromFile(ifstream& ifs, vector<Warrior>& warriors)
{//function that reads the input file and processes the commmands

	string command;

	while (ifs >> command)
	{
		if (command == "Status")
		{
			printWarriors(warriors);
		}

		else if (command == "Warrior")
		{
			string name, weaponName;
			int strength;
			ifs >> name >> weaponName >> strength;
			addWarrior(name, weaponName, strength, warriors);
		}

		else if (command == "Battle")
		{
			string warrior1, warrior2;
			ifs >> warrior1 >> warrior2;
			cout << warrior1 << " battles " << warrior2 << endl;
			int index1 = findWarrior(warrior1, warriors);
			int index2 = findWarrior(warrior2, warriors);
			warriors[index1].battle(warriors[index2]);
		}
	}

}

void printWarriors(const vector<Warrior>& warriors)
{// function that prints out the status of the warrior group
	cout << "There are " << warriors.size() << " warriors" << endl;
	for (size_t i = 0; i<warriors.size(); i++)
	{
		cout << "Warrior: " << warriors[i].getName() << " , Weapon: " << warriors[i].getWeaponName() << ", " << warriors[i].getWeaponStrength() << endl;
	}
}

void addWarrior(const string& name, const string& weaponName, int strength, vector<Warrior>& warriors)
{// function to add the warrior to the list of warriors
	Warrior aWarrior(name, weaponName, strength);
	warriors.push_back(aWarrior);
}

int findWarrior(const string& name, const vector<Warrior>& warriors)
{
	for (size_t i = 0; i<warriors.size(); i++)
	{
		if (warriors[i].getName() == name)
			return i;
	}
	return warriors.size();
}
