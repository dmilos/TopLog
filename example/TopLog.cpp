#include <iostream>
#include <iomanip>
#include <string>

#include "../src/TopLog.hpp"


using namespace std;

int main( int argc, char *argv[] )
 {
  cout << "Start" << endl;

  unsigned      u=1;
  std::uint8_t  u8=1;
  std::uint16_t u16=1;
  std::uint32_t u32=2;
  std::uint64_t u64=3;

  int     i=-4;
  std::int8_t  i8=-4;
  std::int16_t i16=-1;
  std::int32_t i32=-2;
  std::int64_t i64=-3;

   double d = 1.1;
   float f = 2.2;
   long double dd = 3.3;

  TOPLOG_SCOPE;
  TOPLOG_POINT;
  TOPLOG_VALUE(100);
  TOPLOG_VALUE(123.123);

  TOPLOG_VALUE(u);
  TOPLOG_VALUE(u8);
  TOPLOG_VALUE(u16);
  TOPLOG_VALUE(u32);
  TOPLOG_VALUE(u64);

  TOPLOG_VALUE(i);
  TOPLOG_VALUE(i8);
  TOPLOG_VALUE(i16);
  TOPLOG_VALUE(i32);
  TOPLOG_VALUE(i64);

  TOPLOG_VALUE(d);
  TOPLOG_VALUE(f);
  TOPLOG_VALUE(dd);

  std::string s="sssssssssssssssss";
  TOPLOG_VALUE(s);

  cout << "Hit enter!"  << endl;

  cin.get();
  return EXIT_SUCCESS;
 }

