#include <iostream>
#include <fstream>

using namespace std;

int main()
{
  double x[100000] = {0};
  double y[100000] = {0};
  double add[100000] = {0};
  double mult[100000] = {0};
  double div[100000] = {0};

  ifstream xfin, yfin;

  xfin.open("RandomNumbersX.txt");
  yfin.open("RandomNumbersY.txt");

  for ( int i = 0; i < 100000; i++ )
  {
     xfin >> x[i];
     yfin >> y[i];  
  }

  for ( int i = 0; i < 100000; i ++)
  {
     add[i] = x[i] + y[i];
     mult[i] = x[i] * y[i];
     div[i] = x[i] / y[i];
  }

  cout << add[0] << endl << mult [0] << endl << div[0] << endl;

  return 0;
};
