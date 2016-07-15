//
// fibonacci.cpp
//
// Keith Mehl
// 11/5/13
// CSCI-15 example program
// Simple iterative and recursive functions for Fibonacci numbers
// Ignores overflow - will produce garbage for large enough n
//

#include <iostream>
using namespace std;

// iterative fibonacci
long ifib( int n )
{
    long t = n, b1 = 1, b2 = 0;
    int i = 2;
    while( i <= n )
    {
        t = b1 + b2;
        b2 = b1;
        b1 = t;
        i++;
    }
    return t;
}

// recursiove fibonacci
long rfib( int n )
{
    if( n < 2 )
    {
        return n;
    }
    return rfib( n-1 ) + rfib( n-2 );
}

int main()
{
    int n;
    long fi, fr;
    cout << "Enter n, <= 0 to quit : " << flush;
    cin  >> n;
    while( n > 0 )
    {
        fi = ifib( n );
        cout << "n " << n << " ifib() returned " << fi << flush;
        fr = rfib( n );
        cout << " rfib() returned " << fr << endl;
        cout << "Enter n, <= 0 to quit : " << flush;
        cin  >> n;
    }
    return 0;
}

