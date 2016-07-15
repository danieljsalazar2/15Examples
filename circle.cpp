//
// circle.cpp
//
// Keith Mehl
// 10/28/08
// CSCI-15 example program
// Illustrate inheritance with a simple circle class
// A Circle "is a" Point with a radius
//

#include <iostream>
#include <cmath>
using std::ostream;
using std::flush;
using std::sqrt;

#include "circle.h"  // this #includes "point.h"

const double Circle::PI = 3.14159265358979323846;

// default constructor
// invokes default Point constructor in the initializer list
Circle::Circle() : Point()
{
    _r = 1.0;
}

// normal constructor
// invokes normal Point constructor in the initializer list
// and also set the radius there -- you can
// initialize variables in the initializer list, too
Circle::Circle( double xVal, double yVal, double rVal ) :
    Point( xVal, yVal ), _r( rVal )
{
    // or, take _r off the initializer list and just set it here: _r = rVal;
}

void Circle::setR( double rVal )
{
    _r = rVal;
}

void Circle::setAll( double xVal, double yVal, double rVal )
{
    // invoke base class setAll() method
    Point::setAll( xVal, yVal );
    // or, you could just assign the values directly
    // _x = xVal;
    // _y = yVal;
    _r = rVal;
}

double Circle::getR( void )
{
    return _r;
}

double Circle::getArea( void )
{
    return PI * _r * _r;
}

// return center-to-center distance between self and b
double Circle::distance( Circle &b )
{
    // dynamic_cast changes referent type of a pointer or reference.  When
    // used with a class type, all types must be in one inheritance chain
    return Point::distance( dynamic_cast<Point &>( b ) );
}

ostream &operator <<( ostream &out, const Circle &c )
{
    out << dynamic_cast<const Point &>( c ) << ", r = " << c._r << flush;
    return out;
}
