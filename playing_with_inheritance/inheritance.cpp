/*
  Subbu
  program to play with inheritance in c++
*/
#include<iostream>
using namespace std;
class Animal
{
public:
  Animal(){
    cout << "I am an animal" << endl;
  }
};

class Dog : public Animal
{
public:
  Dog(){
    cout << "I am a dog" << endl;
  }
};

int main()
{
  Animal aAnimal;
  Dog walle;
}
