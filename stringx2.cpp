//
// stringx2.cpp
//
// CSCI 15 Example program
// Keith Mehl, 9/14/2000
//
// Illustrate the use of the ISO/ANSI C++ string class
// Rewrite the C-string example to use C++ string objects
// except, here I assume tokens are ' '-delimited only
//

#include <iostream>
#include <string>  // for C++ string class
#include <cstddef> // for size_t, which will
             // normally be something like #define size_t unsigned long
             // or typedef unsigned long size_t
using namespace std;

int main( void )
{
   // first a few work strings
   string s1 = "Hello, Dolly!\n", s2 = "", s3 = "";
   string data = ""; // for input from the user
   string p1;        // to hold temporary substrings
   size_t i, j;      // indices of ' ' characters in strings (int works, too)

   getline( cin, data ); // there is no cin.getline() for string objects

   cout << "s1 is <" << s1 << ">\ndata is <" << data << ">\n" << flush;

   // find first token -- this doesn't extract it, just locates it
   i = data.find( ' ' ); // get offset of space, end of first token
   
   // string::npos is a public constant in the class string
   // find() returns it when it can't find the character in the string
   // otherwise, find() returns the index of the first occurance of the
   // character in the string (length of the string up to the character)
   if( i == string::npos )
   {
      cout << "Oops, no tokens!\n" << flush;
      return -1;
   }
   
   p1 = data.substr( 0, i ); // get substring from position 0 for length i
   cout << "First token is <" << p1 << '>' << endl;

   // find second token
   j = data.substr( i+1, data.length()-i-1 ).find( ' ' ); // find next space
   if( j == string::npos )
   {
      cout << "Oops, no tokens!\n" << flush;
      return -2;
   }
   s2 = data.substr( i+1, j );  // and extract second token

   cout << "Second token is <" << s2 << '>' << endl;
   s2 = p1;     // make s2 a duplicate of p1's data
   s2 += data;  // attach original data string to s2
   
   cout << "s2 is <" << s2 << ">\n" << flush;

   s3 = s2;
   s3 += s2 += s1;              // cascaded string concatenation
   cout << "s3 is <" << s3
        << ">\ns2 is <" << s2
        << ">\ns1 is <" << s1 << '>' << endl;

   return 0;
}

