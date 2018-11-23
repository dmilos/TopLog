#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>



#define BIG_FANCY_LOGGER_MESSAGE(message) std::cout << message ;


double process( double a, double b, double c )
 {
  double s = 0;
  s += a*a;
  if( b < 0 )
   {
    BIG_FANCY_LOGGER_MESSAGE("Second value is negative.")
    b = -b;
   }
  s += sqrt( b );
  s += sin( c );
  return s;
 }

int main( int argc, char *argv[] )
 {
  std::cout << "Step 4" << std::endl;

  std::cout << process( 1, -2, 3 ) << std::endl;

  std::cin.get();
  return EXIT_SUCCESS;
 }

