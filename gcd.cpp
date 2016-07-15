//
// gcd.cpp
// Keith Mehl
// 3/28/07
// CSCI-15 example program
// Iterative and recursive implementations of Euclid's
// algorithm to calculate greatest common divisor
//
#include <iostream>
using namespace std;

// gcd: calculate greatest common divisor or a and b
//   assume both a and b > 0
// iterative solution
int gcd1( int a, int b )
{
   int r = a % b;
   while( r != 0 )
   {
      a = b;
      b = r;
      r = a % b;
   }
   return b;
}
// recursive solution
int gcd2( int a, int b )
{
   if( b == 0 ) {
      return a;
   }
   return gcd2(b, a % b);
}

int main()
{
   int x = -1, y, g;
   cout << "Enter values for x and y, both > 0.\nEnter x < 0 to quit."
        << endl;
   do
   {
      cout << "Enter x : " << flush;
      cin  >> x;
      if( x > 0 )
      {
         cout << "Enter y : " << flush;
         cin  >> y;
      }
      if( x > 0 && y > 0 )
      {
         cout << "x = " << x << ", y = " << y << endl
              << "Recursive gcd : " << gcd1( x, y ) << endl
              << "Iterative gcd : " << gcd2( x, y ) << endl;
      }
   } while( x > 0 );
   return 0;
}
