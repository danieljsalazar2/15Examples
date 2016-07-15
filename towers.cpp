//
// towers.cpp
// Keith Mehl
// August 9, 2000
// CSCI-15 example program
//
// Illustrate recursive solution to the "Towers of Hanoi" problem, showing
// information about the recursion as it occurs.  Illustrate conditional
// compilation (with embedded DEBUG code)
//

#define DEBUG  // create a macro DEBUG and set it to the null expression
// comment this next line out to get execution trace info at run time
#undef DEBUG   // undefine (remove the definition of) DEBUG

#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

unsigned long nCalls;   // Global variable to count all calls to tower()
                        // and have number still available in main()
unsigned long nMoves;   // Global to track total number of moves
unsigned long nLevels;  // Global to track deepest level of recursion
                        // These are acceptable uses of global variables.
                        // You should avoid using them if possible...

// recursive solution to the Towers of Hanoi
// the parameters 'stack' and 'level' are for debug purposes only
// n is number of disks to move
// from, to and spare are the 3 pegs
// disk is the current disk being moved
// stack illustrates where in the call chain we are right now
// level gives the depth of recursive calls

void tower( int n, char from, char to, char spare, int disk, string stack, int level )
{
   nCalls++;   // count this call to tower()
   if( level > (int)nLevels ) // see if this level is deepest seen so far
   {
      nLevels = level;
   }
#ifdef DEBUG
   cout << "Tower called at level " << level << " with stack\n" << stack << endl;
#endif
   if( n == 1 )  // at the 'top' of this stack being moved now?
   {
       nMoves++; // yes, count moving this disk
#ifdef DEBUG
       cout << "\t\t\t\tMove disk " << disk << " from " << from << " to " << to << ".\n" << flush;
#else
       cout << "Move disk " << disk << " from " << from << " to " << to << ".\n" << flush;
#endif
   }
   else
   {
      tower( n-1, from, spare, to, disk-1, stack+" 1", level+1 ); // call point 1
      tower( 1, from, to, spare, disk, stack+" 2", level+1 );     // call point 2
      tower( n-1, spare, to, from, disk-1, stack+" 3", level+1 ); // call point 3
   }
   return;
}

// some code to drive it all
int main( int argc, char** argv )
{
   int nDisks = 3;                  // default to 3 disks
   nLevels = nMoves = nCalls = 0;   // we haven't called tower() yet
      // string to show call stack,
      // which shows which calls to tower() are currently active
   string s = "main";
   if( argc > 1 ) // optional change to the # of disks
   {
      nDisks = atoi( argv[1] );
      if( nDisks <= 0 )
      {
         nDisks = 3; // unless junk on command line...
      }
   }
   // call tower() at the "main" level, recursive calls will be from points 1, 2, 3
#ifdef DEBUG
   cout << "About to call tower() the first time." << endl;
#endif
   tower( nDisks, 'A', 'B', 'C', nDisks, s, 0 );
   cout << "Back from tower(), with nMoves " << nMoves << ", nCalls " << nCalls
        << ".\nThe deepest level of recursion seen was " << nLevels << ".\n" << flush;
   return 0;
}

