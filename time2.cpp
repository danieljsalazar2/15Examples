//
// time2.cpp
// Keith Mehl
// 10/10/01
// The implementation file for the time2 class.
//
#include <iostream>
using namespace std;
#include "time2.h"
// the following functions can only modify an object of type TIME2
// default constructor, set time 0, 0, 0
TIME2::TIME2( void )
{
   hour = min = sec = 0;
}
// constructor, set time if it is legal
TIME2::TIME2( int h, int m, int s )
{
   setTime( h, m, s );
   cout << "I'm in the constructor now\n" << flush;
   // hour = ( h >= 0 && h <= 23 ) ? h : 0;
   // min  = ( m >= 0 && m <= 59 ) ? m : 0;
   // sec  = ( s >= 0 && s <= 59 ) ? s : 0;
}
// set time to an outside time, if time is legal
void TIME2::setTime( int h, int m, int s )
{
   hour = ( h >= 0 && h <= 23 ) ? h : 0;
   min  = ( m >= 0 && m <= 59 ) ? m : 0;
   sec  = ( s >= 0 && s <= 59 ) ? s : 0;
}
// print time in MILITARY or NORMAL format
void TIME2::printTime( int mode )
{
   switch( mode )
   {   // notice, both results of ?: must be the same type, here C-strings
   case MILITARY : cout << (hour < 10 ? "0" : "") << hour << ':'
                        << (min < 10 ? "0" : "")  << min << ':'
                        << (sec < 10 ? "0" : "")  << sec << flush;
                   break;
   case NORMAL   : cout << (hour == 0 || hour == 12 ? 12 : hour % 12) << ":"
                        << (min < 10 ? "0" : "")  << min << ':'
                        << (sec < 10 ? "0" : "")  << sec << ' '
                        << (hour >= 12 ? "PM" : "AM") << flush;
                   break;
   default       : cout << hour << ":" << min << ":" << sec << flush;
   }
}
// add one second to time
void TIME2::increment( void )
{
   sec++;
   if( sec > 59 )
   {
      sec = 0;
      min++;
      if( min > 59 )
      {
         min = 0;
         hour++;
         if( hour > 23 )
         {
            hour = 0;
         }
      }
   }
}

