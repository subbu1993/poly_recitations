/*
  HW01
  Subbu
  A program that programs a game of medieval times
*/

#include<iostream>
#include<string>
#include<fstream>

using namespace std;

openFile(ifstream&);
int main()
{
  ifstream ifs;
  openFile(ifs);
  readFromFile(ifs);
}


void openFile(ifstream& ifs)
{
  ifs.open("warriors.txt");
  if(!ifs)
  {
    cerr << "Cannot open file";
    exit(1);
  }
}
