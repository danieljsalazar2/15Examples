//
// point.cpp
//
// Keith Mehl
// 10/28/08
// CSCI-15 Example program
// A simple point class
//

#include <iostream>
#include <cmath>
using std::ostream;
using std::flush;
using std::sqrt;

#include "point.h"

// default constructor
Point::Point()
{
    _x = _y = 0.0;
}

// normal constructor
Point::Point( double xVal, double yVal )
{
    setAll( xVal, yVal );
}

// manipulator - set x and y
void Point::setAll( double xVal, double yVal )
{
    _x = xVal;
    _y = yVal;
    return;
}

// observers - get value of x and y
double Point::getX( void ) const
{
    return _x;
}

double Point::getY( void ) const
{
    return _y;
}

// return distance between self and b
double Point::distance( Point &b )
{
    return sqrt( (_x - b._x) * (_x - b._x) +
                 (_y - b._y) * (_y - b._y) );
}

// observer - print in format ( x, y )
ostream &operator <<( ostream &out, const Point &p )
{
    out << "( " << p._x << ", " << p._y << " )" << flush;
    return out;
}
