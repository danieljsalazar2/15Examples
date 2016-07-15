//
// chartype.cpp
// CSCI-15 example program
// Keith Mehl 11/10/2011
// Illustrate bit flags and fast character type functions
// and show that they can be implemented as macros too
//

#include <iostream>
#include <iomanip>
using namespace std;

#define  ISLOWER  0x01
#define  ISUPPER  0x02
#define  ISALPHA  (ISLOWER|ISUPPER)
#define  ISDIGIT  0x04
#define  ISALNUM  (ISALPHA|ISDIGIT)
#define  ISCTL    0x08
#define  ISGRAPH  0x10
#define  ISSPACE  0x20   // space, FF, NL, CR, TAB, VT (whitespace characters)
#define  ISHEXDG  0x40   // hex digit {A-F, a-f} (OR with ISDIGIT)
static const int MIN = 0, MAX = 128; // for 0 and limit of ASCII values + 1
// character table (of attributes for each character)
// index into table is the character itself
// static here means not available to linker as a global (file scope only)
static const char _ct[MAX] = {
   ISCTL, ISCTL, ISCTL, ISCTL, ISCTL, ISCTL, ISCTL, ISCTL,     /* ASCII 0-7 */
   ISCTL, ISCTL|ISSPACE, ISCTL|ISSPACE, ISCTL|ISSPACE,         /* 8-11 */
   ISCTL|ISSPACE, ISCTL, ISCTL, ISCTL,                         /* 12-15 */
   ISCTL, ISCTL, ISCTL, ISCTL, ISCTL, ISCTL, ISCTL, ISCTL,     /* 16-23 */
   ISCTL, ISCTL, ISCTL, ISCTL, ISCTL, ISCTL, ISCTL, ISCTL,     /* 24-31 */
   ISSPACE, ISGRAPH, ISGRAPH, ISGRAPH,                         /* 32-35 */
   ISGRAPH, ISGRAPH, ISGRAPH, ISGRAPH,                         /* 36-39 */
   ISGRAPH, ISGRAPH, ISGRAPH, ISGRAPH,                         /* 40-43 */
   ISGRAPH, ISGRAPH, ISGRAPH, ISGRAPH,                         /* 44-47 */
   ISGRAPH|ISDIGIT, ISGRAPH|ISDIGIT,                           /* 48-49 */
   ISGRAPH|ISDIGIT, ISGRAPH|ISDIGIT,                           /* 50-51 */
   ISGRAPH|ISDIGIT, ISGRAPH|ISDIGIT,                           /* 52-53 */
   ISGRAPH|ISDIGIT, ISGRAPH|ISDIGIT,                           /* 52-55 */
   ISGRAPH|ISDIGIT, ISGRAPH|ISDIGIT, ISGRAPH, ISGRAPH,         /* 56-59 */
   ISGRAPH, ISGRAPH, ISGRAPH, ISGRAPH,                         /* 60-63 */
   ISGRAPH, ISGRAPH|ISUPPER|ISHEXDG,                           /* 64-65 */
   ISGRAPH|ISUPPER|ISHEXDG, ISGRAPH|ISUPPER|ISHEXDG,           /* 66-67 */
   ISGRAPH|ISUPPER|ISHEXDG, ISGRAPH|ISUPPER|ISHEXDG,           /* 68-69 */
   ISGRAPH|ISUPPER|ISHEXDG, ISGRAPH|ISUPPER,                   /* 70-71 */
   ISGRAPH|ISUPPER, ISGRAPH|ISUPPER,                           /* 72-73 */
   ISGRAPH|ISUPPER, ISGRAPH|ISUPPER,                           /* 74-75 */
   ISGRAPH|ISUPPER, ISGRAPH|ISUPPER,                           /* 76-77 */
   ISGRAPH|ISUPPER, ISGRAPH|ISUPPER,                           /* 78-79 */
   ISGRAPH|ISUPPER, ISGRAPH|ISUPPER,                           /* 80-81 */
   ISGRAPH|ISUPPER, ISGRAPH|ISUPPER,                           /* 82-83 */
   ISGRAPH|ISUPPER, ISGRAPH|ISUPPER,                           /* 84-85 */
   ISGRAPH|ISUPPER, ISGRAPH|ISUPPER,                           /* 86-87 */
   ISGRAPH|ISUPPER, ISGRAPH|ISUPPER,                           /* 88-89 */
   ISGRAPH|ISUPPER, ISGRAPH,                                   /* 90-91 */
   ISGRAPH, ISGRAPH, ISGRAPH, ISGRAPH,                         /* 92-95 */
   ISGRAPH, ISGRAPH|ISLOWER|ISHEXDG,                           /* 96-97 */
   ISGRAPH|ISLOWER|ISHEXDG, ISGRAPH|ISLOWER|ISHEXDG,           /* 98-99 */
   ISGRAPH|ISLOWER|ISHEXDG, ISGRAPH|ISLOWER|ISHEXDG,           /* 100-101 */
   ISGRAPH|ISLOWER|ISHEXDG, ISGRAPH|ISLOWER,                   /* 102-103 */
   ISGRAPH|ISLOWER, ISGRAPH|ISLOWER,                           /* 104-105 */
   ISGRAPH|ISLOWER, ISGRAPH|ISLOWER,                           /* 106-107 */
   ISGRAPH|ISLOWER, ISGRAPH|ISLOWER,                           /* 108-109 */
   ISGRAPH|ISLOWER, ISGRAPH|ISLOWER,                           /* 110-111 */
   ISGRAPH|ISLOWER, ISGRAPH|ISLOWER,                           /* 112-113 */
   ISGRAPH|ISLOWER, ISGRAPH|ISLOWER,                           /* 114-115 */
   ISGRAPH|ISLOWER, ISGRAPH|ISLOWER,                           /* 116-117 */
   ISGRAPH|ISLOWER, ISGRAPH|ISLOWER,                           /* 118-119 */
   ISGRAPH|ISLOWER, ISGRAPH|ISLOWER,                           /* 120-121 */
   ISGRAPH|ISLOWER, ISGRAPH,                                   /* 122-123 */
   ISGRAPH, ISGRAPH, ISGRAPH, ISCTL                            /* 124-127 */
};
// now implementations of clones of several <cctype> library functions
// the real functions have all lower-case names, but I ran into conflicts
// with the library's identifiers because Quincy automatically #includes
// the standard C library headers itself if you don't do it
int IsAlnum( int c )
{
   return c >= MIN && c < MAX && _ct[c] & ISALNUM;
}
int IsAlpha( int c )
{
   return c >= MIN && c < MAX && _ct[c] & ISALPHA;
}
int IsCntrl( int c )
{
   return c >= MIN && c < MAX && _ct[c] & ISCTL;
}
int IsDigit( int c )
{
   return c >= MIN && c < MAX && _ct[c] & ISDIGIT;
}
int IsGraph( int c )
{
   return c >= MIN && c < MAX && _ct[c] & ISGRAPH;
}
int IsSpace( int c )
{
   return c >= MIN && c < MAX && _ct[c] & ISSPACE;
}
int IsLower( int c )
{
   return c >= MIN && c < MAX && _ct[c] & ISLOWER;
}
int IsUpper( int c )
{
   return c >= MIN && c < MAX && _ct[c] & ISUPPER;
}
int IsXDigit( int c )  /* hex digit works with a-f or A-F, and 0-9 */
{
   return c >= MIN && c < MAX && _ct[c] & (ISHEXDG|ISDIGIT);
}
char ToUpper( int c )
{
   if( IsLower( c ) )
   {
      return c - 32;
   }
   return c;
}
char ToLower( int c )
{
   if( IsUpper( c ) )
   {
      return c + 32;
   }
   return c;
}

// show that these can be defined as macros also
#define IsUpperCase(c) (c >= 0 && c <= 127 && _ct[c] & ISUPPER)

/* and a driver to push it all... */
int main()
{
   int ch = 0;
   while( true ) /* infinite loop, uses break to exit */
   {
      cout << "Enter ASCII code for character (0-127), out of range to stop: "
           << flush;
      cin  >> ch;
      if( ch < MIN || ch > MAX )
      {
         break;
      }
      // print 3-character decimal value filled with '0's
      // then hexadecimal in minimum width with leading 0x, then turn off base
      cout << setw(3) << dec << setfill('0') << ch << ' '
           << setw(0) << hex << showbase << ch << noshowbase << endl;

      if( IsAlnum( ch ) )
      {
         cout << (char)ch << " is alphanumeric\n" << flush;
      }
      if( IsAlpha( ch ) )
      {
         cout << (char)ch << " is alphabetic\n" << flush;
      }
      if( IsLower( ch ) )
      {
         cout << (char)ch << " is a lower-case letter\n" << flush;
      }
      if( IsUpper( ch ) )
      {
         cout << (char)ch << " is an upper-case letter\n" << flush;
      }
      // equivalent test using the macro instead
      if( IsUpperCase( ch ) )
      {
         cout << (char)ch << " is an upper-case letter (macro test)\n" << flush;
      }
      if( IsCntrl( ch ) )
      {
         cout << (char)ch << " is a control character\n" << flush;
      }
      if( IsDigit( ch ) )
      {
         cout << (char)ch << " is a digit\n" << flush;
      }
      if( IsGraph( ch ) )
      {
         cout << (char)ch << " is an ASCII graphic character\n" << flush;
      }
      if( IsSpace( ch ) )
      {
         cout << (char)ch << " is a whitespace character\n" << flush;
      }
      if( IsXDigit( ch ) )
      {
         cout << (char)ch << " is a hexadecimal digit\n" << flush;
      }
      cout << "ToUpper( ch ) is " << ToUpper( ch )
           << "\nToLower( ch ) is " << ToLower( ch ) << endl;
   }
   return 0;
}


