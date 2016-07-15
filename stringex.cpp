//
// stringex.cpp
//
// Keith Mehl
// 9/14/2000
//
// CSCI 15 Example program
// Illustrate the use of C-strings and the C-string library
//

#include <iostream>
using namespace std;
#include <cstring>      // for the C-string library functions

#define MAX     101     // longest string is 100 bytes, + 1 for NUL ('\0')
#define DELIMS  " .\n"  // tokens terminated by ' ', '.', '\n', '\0'

int main( void )
{
    // a few work arrays to hold the strings...
    char s1[MAX] = "Hello, Dolly!\n", s2[MAX] = "", s3[MAX] = "";
    char data[MAX] = "", tokdata[MAX] = ""; // for input from the user
    char *p1 = NULL, *p2 = NULL;// pointers to chars, for ftn return values

    cin.getline( data, MAX-1, '\n' ); // get a line(where, how big, stop at)
    // save for tokenization (only because
    // strtok() destroys the string passed in)
    strcpy( tokdata, data );

    cout << "s1 is <" << s1 << ">\ndata is <" << data << ">\n" << flush;

    p1 = strtok( tokdata, DELIMS );// given a string, strtok() returns 1st token
    if( p1 == NULL )
    {
        cout << "Oops, no tokens!\n" << flush; // Hopefully, will not happen here...
        return -1;                             // If so, give up with error code
    }
    cout << "First token is <" << p1 << '>' << endl;
    p2 = strtok( NULL, DELIMS );// given NULL, strtok returns next token
    if( p2 == NULL )            // from string given in the last non-NULL call
    {
        cout << "Oops, no tokens!\n" << flush; // Will not happen here...
        return -2;                             // If so, give up with error code
    }
    strcpy( s2, p2 );
    cout << "Second token is <" << s2 << '>' << endl;

    strcpy( s2, p1 );    // make s2 a duplicate of p1's data
    strcat( s2, data );  // attach original data string to s2
    cout << "s2 is <" << s2 << ">\n" << flush;

    strcpy( s3, s2 );
    strcat( s3, strcat( s2, s1 ) );

    cout << "s3 is <" << s3
         << ">\ns2 is <" << s2
         << ">\ns1 is <" << s1 << '>' << endl;

    return 0;
}

