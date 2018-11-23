# TopLog

### Description
 - When big and fancy loggers are not suitable for debugging there is TopLog.

### Key features:
 - Header only
   - One file to include to start the fun
 - No third parties
 - No additional binaries
 - Out of the box ready
   - No need to recompile or start some install process.


### Work flow:

1. Isolate peace of code where problem might be.

```c++
double process( double a, double b, double c )
 { // It is somewhere in this function.
  double s = 0;
  s += a*a;        //<< Might be here
  s += sqrt( b );   //<< Might be here
  s + = sin( c );  //<< Might be here
  return s;
 }

std::cout << process( 1, -2, 3 ) << std::endl;
```


2. Populate with TopLog macros
```c++
#include "TopLog.hpp"

double process( double a, double b, double c )
 {   TOPLOG_SCOPE;
  double s = 0;    TOPLOG_COMMENT("Initialization");
  s += a*a;        TOPLOG_VALUE(a);
  s += sqrt( b );   TOPLOG_VALUE(b);
  s += sin( c );  TOPLOG_VALUE(c);
  return s;
 }

std::cout << process( 1, -2, 3 ) << std::endl;
```

3. Fix the problem
```c++
#include "TopLog.hpp"

double process( double a, double b, double c )
 { TOPLOG_SCOPE;
  double s = 0;    TOPLOG_COMMENT("Initialization");
  s += a*a;        TOPLOG_VALUE(a);
  if( b < 0 )
   { TOPLOG_SCOPE;
    BIG_FANCY_LOGGER_MESSAGE("Second value is negative.")
    b = -b; TOPLOG_VALUE(b);
   }
  s += sqrt( b );   TOPLOG_VALUE(b);
  s += sin( c );  TOPLOG_VALUE(c);
  return s;
 }

std::cout << process( 1, -2, 3 ) << std::endl;
```

4. Remove TopLog!!!
```c++
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
```

5. DONE!!!

### Install

 - Clone the project.
 - Take src\TopLog.hpp and put for you in some suitable place.
 - Use TopLog

