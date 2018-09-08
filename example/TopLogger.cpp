#include <iostream>
#include <iomanip>
#include <string>

#include "TopLogger.hpp"


using namespace std;

int main( int argc, char *argv[] )
 {
  cout << "aaaaa" << endl;

  TOPLOG_SCOPE;
  TOPLOG_POINT;
  TOPLOG_VALUE(100);
  TOPLOG_VALUE(123.123);
  int i;
  TOPLOG_VALUE(i);
  
  std::string s="sssssssssssssssss";
  TOPLOG_VALUE(s);
  

  cin.get();
  return EXIT_SUCCESS;
 }

