#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>

#include "TopLog.hpp"

double process( double a, double b, double c )
 {TOPLOG_SCOPE;
  double s = 0;    TOPLOG_COMMENT("Initialization");
  s += a*a;        TOPLOG_VALUE(a);
  s += sqrt( b );   TOPLOG_VALUE(b);
  s += sin( c );  TOPLOG_VALUE(c);
  return s;
 }

int main( int argc, char *argv[] )
 {
  std::cout << "Hello World" << std::endl;

  std::cout << process( 1, -2, 3 ) << std::endl;

  std::cin.get();
  return EXIT_SUCCESS;
 }

