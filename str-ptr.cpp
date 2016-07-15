//
// str-ptr.cpp
//
// Keith Mehl
// Feb. 13, 2008
// CSCI-15 example program
// Illustrate some of the equivalences and differences between
// arrays and pointers, using C-strings
//

#include <cstring>
#include <iostream>
using namespace std;
// illustrate array parameter passing with * and []
void foo( char *p, char a[] )
{
   cout << "p is " << p << flush;
   cout << "a is " << a << flush;
   cout << "p points to " << (void *)p << endl;
   cout << "a points to " << (void *)a << endl;
   cout << "sizeof(p) is " << sizeof(p) << endl;
   cout << "sizeof(a) is " << sizeof(a) << endl;
   return;
}

int main()
{
   // array of 100 characters
   char str[100] = "Hello\n";
   // pointer to constant C-string
   char *pstr = "Hello\n";

   // display some interesting details about str and pstr...
   cout << "The string str is " << str << flush;
   cout << "Size of str is " << sizeof(str) << endl;
   cout << "String length of str is " << strlen( str ) << endl;

   // notice that you can directly dereference the array
   //  - its name actually IS a const pointer to a char
   cout << "Size of (*str) is " << sizeof(*str) << endl;
   cout << "(*str) is " << *str << endl << endl;

   cout << "The string pstr is " << pstr << flush;
   cout << "Size of pstr is " << sizeof(pstr) << endl;
   cout << "String length of pstr is " << strlen( pstr ) << endl;
   cout << "Size of (*pstr) is " << sizeof(*pstr) << endl;
   cout << "(*pstr) is " << *pstr << endl << endl;

   // display where the variables "live" in RAM
   cout << "The address in RAM of str is : " << (void *)str << endl;
   cout << "The address in RAM of pstr itself is : " << (void *)&pstr << endl;
   cout << "The address in RAM of *pstr is : " << (void *)pstr << endl << endl;

   // call foo() with str and then with pstr
   cout << "Calling foo( str, str ); " << endl;
   foo( str, str );
   cout << "Calling foo( pstr, pstr ); " << endl;
   foo( pstr, pstr );

   // modify a character in the array
   str[2] = 'X';
   cout << "\nThe string str is now : " << str << flush;

   // make the pointer pstr point to a different string
   pstr = "Goodbye!\n";
   cout << "The string pstr is now : " << pstr << flush;

   // copy a different C-string into str
   strcpy( str, "Goodbye!\n" );
   cout << "The string str is now : " << str << flush;

   // This compiles but will trap.
#if 0 // conditional compilation: compile if 0 is true (which can't happen)
   pstr[2] = 'X';
   cout << "The string pstr is now : " << pstr << flush;
#endif
   // This compiles but will trap.
#if 0
   strcpy( pstr, "oops" );
   cout << "The string pstr is now : " << pstr << flush;
#endif
   // This will not compile.
#if 0
   str = "Goodbye!";
   cout << "The string str is now : " << str << flush;
#endif
   return 0;
}

