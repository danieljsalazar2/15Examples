//
// mid1Fall13.cpp
//
// Keith Mehl
// 10/15/13
// CS15 midterm #1 code
// requires command line input and output file names to test q3()
// I added very light notes, not required for the test
//

#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>
using namespace std;

// q1
char *StringRev( char *s )
{
    char *p = s, *q = s, t;
    while( *q )  // find end of s
    {
        q++;
    }
    q--;         // which is one back of the NUL
    while( p < q )
    {
        t = *p;  // swap
        *p = *q;
        *q = t;
        p++;     // advance pointers
        q--;
    }
    return s;
}

// q2
// use array notation means [] for array parameters, not *, and indexing
int StringCmp( char s[], char t[] )
{
    int i;
    for( i = 0; s[i] && s[i] == t[i]; i++ );
    return s[i] - t[i];
}

void q3( int argc, char *argv[] )
{
    ifstream fin;
    ofstream fout;
    char line[1000] = "";  // make it long enough!
    char *p = NULL;
    int tokens = 0, lines = 0;
    if( argc != 3 )
    {
        cout << "Usage: program input-file output-file" << endl;
        return;  // from main(), return an error code here
    }
    fin.open( argv[1] );
    fout.open( argv[2] );
    if( !fin || !fout )
    {
        cout << "Error opening files!" << endl;
        return;
    }
    fin.getline( line, 1000, '\n' );  
                 // test below for eof() isn't required on the exam
    while( strcmp( line, "quit" ) != 0 && !fin.eof() )
    {
        fout << line << ' ' << strlen( line ) << endl;
        lines++;
        p = strtok( line, " ,.\n" );
        while( p != NULL )
        {
            fout << p << endl;
            tokens++;
            p = strtok( NULL, " ,.\n" );
        }
        fin.getline( line, 1000, '\n' );
    }
    fout << lines << " line(s), " << tokens << " token(s)" << endl;
    fin.close();
    fout.close();
    return;
}

// q5
// DON'T seed the random number generator here!
int DieRoll( int n )
{
    return rand() % n + 1;
}

// q6
int test( int &a, int b )
{
   int c = a - b + 3;
   a = b + c;
   b = a + c + 2;
   cout << a << ' ' << b << ' ' << c << '\n';
   return a + b + c;
}
int q6( void )
{
   int a = 1, b = 2, c;
   c = test( a, b );
   cout << "a = " << a << " b = " << b 
        << " c = " << c << '\n';
   b = test( c, a ); 
   cout << "a = " << a << " b = " << b 
        << " c = " << c << '\n';
   return 0;
}

int main( int argc, char *argv[] )
{
    char test[100] = "This is a test of the string reversal function";
    cout << test << endl;
    StringRev( test );
    cout << test << endl;
    cout << "----------------------------------" << endl;
    char cat[20] = "cat", zebra[20] = "zebra";
    cout << "with " << cat << " and " << zebra << endl;
    cout << "StringCmp( cat, zebra ) returns " << StringCmp( cat, zebra ) << endl;
    cout << "StringCmp( zebra, cat ) returns " << StringCmp( zebra, cat ) << endl;
    cout << "StringCmp( zebra, zebra ) returns " << StringCmp( zebra, zebra ) << endl;
    cout << "----------------------------------" << endl;
    q3( argc, argv );
    cout << "----------------------------------" << endl;
    for( int i = 0; i < 5; i++ )
    {
        cout << "A roll of an 8-sided die : " << DieRoll( 8 ) << endl;
    }
    cout << "----------------------------------" << endl;
    q6();
    return 0;
}

