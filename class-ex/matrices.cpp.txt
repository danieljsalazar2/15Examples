//
// class-ex.cpp
// Keith Mehl  Oct. 11, 2000
// CSCI-15 example program
// Introduce class
//

#include <iostream>
using namespace std;
#include "time2.h"

// first a plain struct TIME1 schema
struct TIME1
{
   int hour;
   int min;
   int sec;
};

// print times from main()
void printTimes( TIME1 time1, TIME2 time2 )
{
   cout << "time1 is " << time1.hour << ' '
        << time1.min << ' ' << time1.sec << endl;
   cout << "time2 military ";
   time2.printTime( MILITARY );
   cout << endl << "time2 normal   ";
   time2.printTime( NORMAL );
   cout << endl;
   return;
}

int main( void )
{
   TIME1 t1 = { 0, 0, 0 }; // initialize struct to 0:0:0
   TIME2 t2( 10, 30, 0 );  // t2 uses constructor to set itself to 10:30:00
   TIME2 t3;               // t3 is set by default constructor to 0:0:0
                           // You cannot use an initializer on a class
   cout << "printing times t1 and t2" << endl;
   printTimes( t1, t2 );
   cout << "printing times t1 and t3" << endl;
   printTimes( t1, t3 );
   // set t1 and t2 to illegal times
   t1.hour = 25;
   t1.min  = -2;
   t1.sec  = 65;
   t2.setTime( 25, -2, 65 );
   cout << "printing illegal times" << endl;
   printTimes( t1, t2 );
   // set t2 to OK time
   t2.setTime( 10, 30, 0 );
   printTimes( t1, t2 );
   // advance time in t2
   t2.increment();
   printTimes( t1, t2 );
   // assign one class to another
   t3 = t2;
   t3.increment();
   t3.increment();
   cout << "After increment t3 twice\n";
   t3.printTime( MILITARY );
   cout << "\nt2 is\n";
   t2.printTime( MILITARY );
   cout << endl;
   return 0;
}

