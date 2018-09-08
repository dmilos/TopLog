#include <iostream>
#include <iomanip>
#include <string>

#include "../src/TopLog.hpp"


using namespace std;

int main( int argc, char *argv[] )
 {
  cout << "Start" << endl;

  TOPLOG_SCOPE;
  TOPLOG_POINT;
  TOPLOG_VALUE(100);
  TOPLOG_VALUE(123.123);
  int i;
  TOPLOG_VALUE(i);

  std::string s="sssssssssssssssss";
  TOPLOG_VALUE(s);

  cout << "Hit enter!" << endl;

  cin.get();
  return EXIT_SUCCESS;
 }

