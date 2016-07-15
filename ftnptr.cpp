//
// ftnptr.cpp
//
// Keith Mehl
// 11/17/2011
// CSCI-15 Example program
// Illustrate using pointers to functions
//
#include <iostream>
#include <cstdlib>
using namespace std;

// typedef - PF is a pointer to function that takes an int and returns void
// the return type is part of the function's data type,
//    but NOT part of a function's signature
// Since * binds left in declarations, the () are required on this type
typedef void (*PF)( int );

// first, several functions to handle the menu options...
void handle1( int n )
{
   cout << "Handling input of " << n << endl;
   return;
}
void handle2( int n )
{
   cout << "This handles " << n << " as input" << endl;
   return;
}
void handle3( int n )
{
   cout << "And in here, we take care of " << n << endl;
   return;
}
void handled( int n )
{
   cout << "Here we handle the default case (other input "
        << n << ")\n" << flush;
   return;
}
int main( void )
{
   // an array of pointers to functions
   // the name of a function alone evaluates to
   // the function's entry point (its address)
   PF pf[4] = { handle1, handle2, handle3, handled };
   int inval, i = 0;
   while( i != 3 )
   {
      cout << "Menu option 1\nMenu option 2\n"
           << "Menu option 3\nExit        4\nEnter option : "
           << flush;
      cin  >> inval;
      i = inval < 1 || inval > 3 ? 3 : inval - 1;
        // () operator calls the the function (via pointer)
        // and passes in argument
      pf[i]( inval );
   }
   return 0;
}

