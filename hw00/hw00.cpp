#include<iostream>
#include<fstream>
#include<vector>
#include<string>
using namespace std;
void openFile(ifstream&);
int readFile(ifstream&, vector<string>&);
void decrypt(vector<string>&,const int);
void print(const vector<string>&);
int main()
{
  ifstream ifs;
  openFile(ifs);
  vector<string> text;
  int numberOfRotations = readFile(ifs,text);
  decrypt(text,numberOfRotations);
  print(text);
}

void openFile(ifstream& ifs)
{
  ifs.open("encrypted.txt");
  if(!ifs)
  {
    cerr << "Could not open the file";
    exit(1);
  }

}
int readFile(ifstream& ifs,vector<string>& text)
{
  int numberOfRotations;
  string line;
  ifs >> numberOfRotations;
  getline(ifs,line);
  while(getline(ifs,line))
  {
    text.push_back(line);
  }
  ifs.close();
  return numberOfRotations;
}

void decrypt(vector<string>& text,const int numberOfRotations)
{
  for(size_t i=0;i<text.size();i++)
  {
    string encrypted_line = text[i];
    for(int j=0;j<encrypted_line.size();j++)
    {
      char encrypted = encrypted_line[j];
      if (encrypted > 'a' && encrypted != ' ')
      {
        if(encrypted - numberOfRotations < 'a')
        {
          int diff = encrypted_line[j] - 'a';
          diff++;
          encrypted_line[j] = 'z' - (numberOfRotations - diff);
        }
        else
          encrypted_line[j] = encrypted - numberOfRotations;
      }
      text[i] = encrypted_line;
    }
  }
}
void print(const vector<string>& text)
{
  for(size_t i = text.size() ; i-- > 0;  )
  {
    cout << text[i] << endl;
  }
}
