#include <iostream>
#include <cstdlib>
#include <fstream>

using namespace std;

int main()
{
  ofstream xfout, yfout;

  xfout.open("RandomNumbersX.txt");
  yfout.open("RandomNumbersY.txt");

  for (int i = 0; i < 100000; i++ )
  {
     xfout << double (rand() % 1000 + 1.00) << endl;
     yfout << double (rand() % 1000 + 1.00) << endl;
  }


  return 0;
};
