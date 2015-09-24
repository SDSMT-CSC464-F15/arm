#include <iostream>
#include <fstream>
#include <chrono>
#include <ctime>

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

  chrono::time_point<chrono::system_clock> start, end;
  start = chrono::system_clock::now();

  for ( int i = 0; i < 100000; i ++)
  {
     for ( int j = 0; j < 1000; j ++)
     {
        add[i] = x[i] + y[j];
        mult[i] = x[i] * y[j];
        div[i] = x[i] / y[j];
     }
  }

  end = chrono::system_clock::now();

  chrono::duration<double> elapsed_time = end - start;
  cout << "Addition took a total of: " << elapsed_time.count() << "s\n";

  start = chrono::system_clock::now();

  for ( int i = 0; i < 100000; i ++)
  {
     for ( int j = 0; j < 1000; j ++)
     {
        add[i] = x[i] + y[j];
        mult[i] = x[i] * y[j];
        div[i] = x[i] / y[j];
     }
  }

  end = chrono::system_clock::now();

  elapsed_time = end - start;
  cout << "Multiplication took a total of: " << elapsed_time.count() << "s\n";

  start = chrono::system_clock::now();

  for ( int i = 0; i < 100000; i ++)
  {
     for ( int j = 0; j < 1000; j ++)
     {
        add[i] = x[i] + y[j];
        mult[i] = x[i] * y[j];
        div[i] = x[i] / y[j];
     }
  }

  end = chrono::system_clock::now();

  elapsed_time = end - start;
  cout << "Division took a total of: " << elapsed_time.count() << "s\n";

  cout << add[0] << endl << mult [0] << endl << div[0] << endl;

  return 0;
};
