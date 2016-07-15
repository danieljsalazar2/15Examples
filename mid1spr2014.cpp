// mid1spr2014.cpp
//
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
using namespace std;

// question 1
char *StrCopy1( char s[], char t[] )
{
    int i = 0;
    while( s[i] = t[i] )
    {
        i++;
    }
    return s;
}

char *StrCopy2( char *s, char *t )
{
    int i = 0;
    while( *(s +i) = *(t + i) )
    {
        i++;
    }
    return s;
}

char *StrCopy3( char *s, char *t )
{
    char *p = s;
    while( *s++ = *t++ );
    return p;
}

// question 3
int DieRoll( int nSides )
{
    return rand() % nSides + 1;
}

// question 4
int mainQ4( int argc, char *argv[] )
{
    int rolls, sides, rule, i;
    ofstream fout;
    if( argc != 5 )
    {
        cout << "Usage: program nRolls nSides seed outputfile" << endl;
        return -1;
    }
    rolls = atoi( argv[1] );
    sides = atoi( argv[2] );
    rule = atol( argv[3] );
    fout.open( argv[4] );
    if( !fout )
    {
        cout << "Error opening file " << argv[4] << endl;
        return -2;
    }
    if( rule > 0 )
    {
        srand( rule );
    }
    else if( rule < 0 )
    {
        srand( time( NULL ) );
    }
    for( i = 0; i < rolls; i++ )
    {
        fout << DieRoll( sides ) << endl;
    }
    fout.close();
    return 0;
}

// question 5
int test( int &a, int b )
{
   int c = a - b + 3;
   a += b + c;
   b = a + c + 2;
   cout << a << ' ' << b << ' ' << c << '\n';
   return a + b + c;
}

int main5( void )
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
    char str1[100] = "", str2[100] = "Hello, Dolly!";
    StrCopy1( str1, str2 );
    cout << "StrCopy1 " << str1 << endl;
    StrCopy2( str1, str2 );
    cout << "StrCopy2 " << str1 << endl;
    StrCopy3( str1, str2 );
    cout << "StrCopy3 " << str1 << endl;
    cout << "\n----------------------------------\n" << flush;
    mainQ4( argc, argv );
    cout << "\n----------------------------------\n" << flush;
    main5();
    return 0;
}

