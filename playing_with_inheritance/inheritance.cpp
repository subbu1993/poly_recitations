/*
Subbu
program to play with inheritance in c++
*/

#include<iostream>
#include<string>
using namespace std;

class Animal
{
public:
	Animal() {
		cout << "I am an animal" << endl;
	}

	Animal(const string& name) : name(name) { cout << "i am called" << endl; }
	void display() const {
		cout << name << endl;
	}

  void eat() const {
    cout << "animal is eating" << endl;
  }
private:
	string name;
};

class Dog : public Animal
{
public:
	Dog() {
		cout << "I am a dog" << endl;
	}

	Dog(const string& name) : Animal(name) {  }

	void display() const {
		cout << "i am a dog and my name is ";
		Animal::display();
	}
  void eat() const {
    cout << "Dog is eating" << endl;
  }
};

int main()
{
	Animal a ;
  Dog d;
  a = d;
  a.eat();
}
