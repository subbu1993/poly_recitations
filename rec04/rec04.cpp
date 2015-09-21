/*
  Rec04
  Subbu
  Modelling a sandwich making and delivering company and ensuring proper return of the delivery trucks
*/
#include<iostream>
using namespace std;

class Sandwich1
{
  int numberOfBread,quantityOfCheese,amountOfMayo,numberOfTomatoes;
  double amountOfMustard;

  public:
    void display()
    {
      cout << "Here are the contents of my sandwich" << endl;
      cout << "Bread: " << numberOfBread << endl;
      cout << "Cheese: " << quantityOfCheese << endl;
      cout << "Mayo: " << amountOfMayo << endl;
      cout << "Tomoatoes: " << numberOfTomatoes << endl;
    }
};

int main()
{
  Sandwich1 s1;
  s1.display();
}
