#include<iostream>
#include<fstream>
#include<vector>
#include<string>
using namespace std;

int main()
{
  ifstream ifs("encrypted.txt");
  if(!ifs)
  {
    cerr << "Could not open the file";
    exit(1);
  }

  int numberOfRotations;
  string line;
  ifs >> numberOfRotations;
  vector<string> text;
  getline(ifs,line);
  while(getline(ifs,line))
  {
    text.push_back(line);
  }
  ifs.close();
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

  for(size_t i = text.size() ; i-- > 0;  )
  {
    cout << text[i] << endl;
  }
}
