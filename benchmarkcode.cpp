#include <iostream>
#include <fstream>
#include <chrono> /* c++11 */
#include <ctime>
#include <omp.h>

using namespace std;

/* Compile: g++ -g -Wall -fopenmp -std=c++11 benchmarkcode.cpp -o benchmark */ 

int main()
{
  double x[100000] = {0};
  double y[100000] = {0};
  double add[100000] = {0};
  double mult[100000] = {0};
  double div[100000] = {0};
  int num_procs = omp_get_num_procs();
  ifstream xfin, yfin;

  xfin.open("RandomNumbersX.txt");
  yfin.open("RandomNumbersY.txt");

  cout << "Number of processers: " << num_procs << endl;

  // fill arrays with the random numbers
  for ( int i = 0; i < 100000; i++ )
  {
     xfin >> x[i];
     yfin >> y[i];  
  }

  // addition
  chrono::time_point<chrono::system_clock> start, end;
  start = chrono::system_clock::now();

  # pragma omp parallel for num_threads( num_procs )
  for ( int i = 0; i < 100000; i ++)
  {
     for ( int j = 0; j < 100000; j ++)
     {
        add[i] = x[i] + y[j];
     }
  }

  end = chrono::system_clock::now();

  chrono::duration<double> elapsed_time = end - start;
  cout << "Addition took a total of: " << elapsed_time.count() << "s\n";

  // multiplation
  start = chrono::system_clock::now();

  # pragma omp parallel for num_threads( num_procs )
  for ( int i = 0; i < 100000; i ++)
  {
     for ( int j = 0; j < 100000; j ++)
     {
        mult[i] = x[i] * y[j];
     }
  }

  end = chrono::system_clock::now();

  elapsed_time = end - start;
  cout << "Multiplication took a total of: " << elapsed_time.count() << "s\n";

  // division
  start = chrono::system_clock::now();

  # pragma omp parallel for num_threads( num_procs )
  for ( int i = 0; i < 100000; i ++)
  {
     for ( int j = 0; j < 100000; j ++)
     {
        div[i] = x[i] / y[j];
     }
  }

  end = chrono::system_clock::now();

  elapsed_time = end - start;
  cout << "Division took a total of: " << elapsed_time.count() << "s\n";

  cout << add[0] << endl << mult [0] << endl << div[0] << endl;

  return 0;
};
