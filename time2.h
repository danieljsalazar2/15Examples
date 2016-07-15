//
// time2.h
//
// Keith Mehl
//
// 10/10/01
// header file for the time2 class
//
#ifndef TIME2_H_INCLUDED   // "header sandwich" to prevent re-inclusion
#define TIME2_H_INCLUDED
// now define a class TIME2
#define MILITARY 1   // for time display
#define NORMAL   2
class TIME2
{
private:     // only class functions can modify private members (data)
   int hour;
   int min;
   int sec;
public:      // any client code can use a public member (functions, or methods)
   TIME2();  // default constructor, time 0, 0, 0
   TIME2( int h, int m, int s ); // constructor
   void setTime( int h, int m, int s ); // set to time if legal
   void printTime( int mode );  // print time in MILITARY or NORMAL style
   void increment( void );   // add one second to time, "wrapping" at midnight
};
#endif // TIME2_H_INCLUDED

