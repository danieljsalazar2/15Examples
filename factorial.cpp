//
// factorial.cpp
//
// Keith Mehl
// 11/5/13
// CSCI-15 example program - illustrate a simple recursive function
// both versions ignore overflow - will return garbage on large enough n
// in this program 13! gives overflow (garbage result)
//

#include <iostream>
using namespace std;

// iterative factorial
long ifact( int n )
{
    long t = n;
    while( --n > 1 )
    {
        t *= n;
    }
    return t;
}

// recursive factorial
long rfact( int n )
{
    if( n <= 1 )
    {
        return 1;
    }
    return n * rfact( n-1 );
}

int main()
{
    int n;
    long fi, fr;
    cout << "Enter value, <= 0 to exit : " << flush;
    cin  >> n;
    while( n > 0 )
    {
        fi = ifact( n );
        fr = rfact( n );
        cout << "n " << n << " ifact() returned " << fi
             << "\nrfact() returned " << fr << endl;
        cout << "Enter value, <= 0 to exit : " << flush;
        cin  >> n;
    }
    return 0;
}

