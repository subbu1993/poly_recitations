/*
Rec04
Subbu
Modelling a sandwich making and delivering company and ensuring proper return of the delivery trucks
*/
#include<iostream>
using namespace std;

class Sandwich1
{
	int numberOfBread, quantityOfCheese, numberOfTomatoes;
	double amountOfMustard;
	double amountOfMayo;

public:


};

class Sandwich2
{
  int numberOfBread, quantityOfCheese, numberOfTomatoes;
  double amountOfMustard;
  double amountOfMayo;

  public:
    void display()
  	{ // method that outputs the contents of a sandwich
  		cout << "Here are the contents of my sandwich" << endl;
  		cout << "Bread: " << numberOfBread << endl;
  		cout << "Cheese: " << quantityOfCheese << endl;
  		cout << "Mayo: " << amountOfMayo << endl;
  		cout << "Tomoatoes: " << numberOfTomatoes << endl;
      cout << "Mustard: " << amountOfMustard << endl;
  	}
};

class Sandwich3
{
  int numberOfBread, quantityOfCheese, numberOfTomatoes;
  double amountOfMustard;
  double amountOfMayo = 0.1;

  public:
    void display()
  	{  // method that outputs the contents of a sandwich
  		cout << "Here are the contents of my sandwich" << endl;
  		cout << "Bread: " << numberOfBread << endl;
  		cout << "Cheese: " << quantityOfCheese << endl;
  		cout << "Mayo: " << amountOfMayo << endl;
  		cout << "Tomoatoes: " << numberOfTomatoes << endl;
      cout << "Mustard: " << amountOfMustard << endl;
  	}
};

class Sandwich4
{
  int numberOfBread, quantityOfCheese, numberOfTomatoes;
  double amountOfMustard;
  double amountOfMayo;

  public:
    void display()
  	{  // method that outputs the contents of a sandwich
  		cout << "Here are the contents of my sandwich" << endl;
  		cout << "Bread: " << numberOfBread << endl;
  		cout << "Cheese: " << quantityOfCheese << endl;
  		cout << "Mayo: " << amountOfMayo << endl;
  		cout << "Tomoatoes: " << numberOfTomatoes << endl;
      cout << "Mustard: " << amountOfMustard << endl;
  	}

    Sandwich4() : amountOfMayo(0.1)
    {

    }
};

class Sandwich5
{
  int numberOfBread, quantityOfCheese, numberOfTomatoes;
  double amountOfMustard;
  double amountOfMayo;

  public:
    void display()
  	{  // method that outputs the contents of a sandwich
  		cout << "Here are the contents of my sandwich" << endl;
  		cout << "Bread: " << numberOfBread << endl;
  		cout << "Cheese: " << quantityOfCheese << endl;
  		cout << "Mayo: " << amountOfMayo << endl;
  		cout << "Tomoatoes: " << numberOfTomatoes << endl;
      cout << "Mustard: " << amountOfMustard << endl;
  	}

    Sandwich5(int numberOfBread = 2,int quantityOfCheese = 1,double amountOfMayo = 0.1 , int numberOfTomatoes = 2, double amountOfMustard = 1.0) : numberOfBread(numberOfBread),quantityOfCheese(quantityOfCheese),numberOfTomatoes(numberOfTomatoes),amountOfMustard(amountOfMustard),amountOfMayo(amountOfMayo)
    {

    }
};

class Sandwich6
{
  int numberOfBread, quantityOfCheese, numberOfTomatoes;
  double amountOfMustard;
  double amountOfMayo;

  public:
    void display()
  	{  // method that outputs the contents of a sandwich
  		cout << "Here are the contents of my sandwich" << endl;
  		cout << "Bread: " << numberOfBread << endl;
  		cout << "Cheese: " << quantityOfCheese << endl;
  		cout << "Mayo: " << amountOfMayo << endl;
  		cout << "Tomoatoes: " << numberOfTomatoes << endl;
      cout << "Mustard: " << amountOfMustard << endl;
  	}

    Sandwich6(int numberOfBread = 2,int quantityOfCheese = 1,double amountOfMayo = 0.1 , int numberOfTomatoes = 2, double amountOfMustard = 1.0) : numberOfBread(numberOfBread),quantityOfCheese(quantityOfCheese),numberOfTomatoes(numberOfTomatoes),amountOfMustard(amountOfMustard),amountOfMayo(amountOfMayo)
    {

    }

    int getBread() const
    { // return the number of breads in the sandwich
      return numberOfBread;
    }

    int getTomatoes() const
    { // return the number of tomatoes in the sandwich
      return numberOfBread;
    }

    int getCheese() const
    { // return the number of cheese slices in the sandwich
      return numberOfBread;
    }

    double getMayo() const
    { // return the amount of mayo in the sandwich
      return amountOfMayo;
    }

    double getMustard() const
    { // return the amount of mustard in the sandwich
      return amountOfMustard;
    }

};

int main()
{
	Sandwich1 s1;
  Sandwich2 s2;
	s2.display();
  Sandwich3 s3;
	s3.display();
  Sandwich4 s4;
  s4.display();
  Sandwich5 s5;
  s5.display();
  Sandwich6 s6;
  s6.display();


}
