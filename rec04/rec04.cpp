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
  	}
}

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
  	}
}



int main()
{
	Sandwich1 s1;
  Sandwich2 s2;
	s2.display();
  Sandwich3 s3;
	s3.display();


}
