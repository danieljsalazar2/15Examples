//
// testMyArray.cpp
//
// Keith Mehl
// 10/18/09
// a simple test driver for MyArray class
//

#include <iostream>
#include <cstdlib>
#include "MyArray.h"
using namespace std;

void printArray( MyArray &a )
{
    int i, ct = 0;
    for( i = 0; i < a.getSize(); i++ )
    {
        cout << a[i];
        if( ++ct == 10 )
        {
            ct = 0;
            cout << endl;
        }
        else
        {
            cout << '\t' << flush;
        }
    }
    if( ct != 0 )
    {
        cout << endl;
    }
    return;
}

// provoke move constructor or assignment
MyArray createByArray( MyArray &ma )
{
    cout << "In createByArray()" << endl;
    MyArray a( ma );
    a[0] = 1;   // prevent optimizer from optimizing out the local variable
    cout << "Past creating in ByArray, returning" << endl;
    return a;
}
MyArray createOne( int n )
{
    cout << "In createOne()" << endl;
    MyArray a( n );
    cout << "Past creating automatic local MyArray, returning" << endl;
    return a;
}

int main()
{
    MyArray a1;       // invokes default constructor
    MyArray a2( 30 ); // invokes normal constructor
    MyArray a3 = 50;  // also invokes normal constructor
    MyArray a4(a3);   // invokes copy constructor

    cout << "Creating from return value of function" << endl;
    MyArray a5( createByArray( a2 ) );
    cout << "Printing after createByArray()" << endl;
    printArray( a5 );
    cout << "Assigning from return value of function" << endl;
    MyArray a6;
    a6 = createOne( 6 );
    cout << "Printing after createOne()" << endl;
    printArray( a5 );
    MyArray a7 = MyArray(5);
    system( "pause" );
    a2.At( 5 ) = 10;
    a2.At( 15 ) = 20;
    a2.At( 25 ) = 30;
    a2[12] = 35;
    a2[17] = a2[12] + 5;

    printArray( a1 );
    cout << "\n--------------------" << endl;
    printArray( a2 );
    cout << "\n--------------------" << endl;
    printArray( a3 );
    cout << "\n-------------------- print 3 chosen values" << endl;
    cout << a2.At(5) << ' ' << a2.At( 15 )
         << ' ' << a2.At( 25 ) << endl;
    a2.At(8) = a2.At(5) + a2[25];
    a2.At(18) = a2.At(15);
    a2[28] = a2.At(25);
    cout << "\n-------------------- now assigning a2 = a3" << endl;
    a3 = a2;
    printArray( a2 );
    cout << "\n--------------------" << endl;
    printArray( a3 );
    cout << "\n--------------------" << endl;
    a2 = a1;
    printArray( a2 );
    cout << "\n--------------------" << endl;
    printArray( a4 );
    return 0;
}

