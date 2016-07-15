//
// p_c_client.cpp
//
// Keith Mehl
// 10/28/08
// CSCI-15 Example program
// Drive the point-circle inheritance example
//

#include <iostream>
using std::cout;
using std::endl;

#include "point.h"
#include "circle.h"

int main()
{
    Point p, q( 3.0, 4.0 );
    Circle c, d( 3.0, 4.0, 2.0 );

    cout << "Points:  " << p << "; " << q << endl
         << "Circles: " << c << "; " << d << endl;

    cout << "Distance between points is  " << p.distance( q ) << endl;
    cout << "Distance between circles is " << c.distance( d ) << endl;
    // cast derived class to base class and print it
    cout << "Printing Circle cast to Point : " << dynamic_cast<Point &>( d )
         << endl;
    // dynamic_cast MUST take a pointer or reference type
    // so to use "thing pointed to by" for the object (via pointer)
    // I use &d, cast that to a Point *, then dereference it to print
    // This is not an example of what you should do!
    // it's just to show it can be done...  so, DON'T DO THIS!
    cout << "Printing *(&Circle cast to Point *) : "
         << *(dynamic_cast<Point *>( &d )) << endl;
    cout << "Area of c: " << c.getArea() << ", of d: " << d.getArea() << endl;
    return 0;
}


