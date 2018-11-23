#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>

double process( double a, double b, double c )
 { // It is somewhere in this function.
  double s = 0;
  s += a*a;        //<< Might be here
  s += sqrt( b );   //<< Might be here
  s += sin( c );  //<< Might be here
  return s;
 }

int main( int argc, char *argv[] )
 {
  std::cout << "Step 1" << std::endl;

  std::cout << process( 1, -2, 3 ) << std::endl;

  std::cin.get();
  return EXIT_SUCCESS;
 }

