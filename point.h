//
// point.h
//
// Keith Mehl
// 10/28/08
// CSCI-15 Example program
// A simple point class
//

#ifndef POINT_H_INCLUDED
#define POINT_H_INCLUDED

#include <iostream>
using std::ostream;

class Point
{
protected:
    double _x, _y;      // x and y values of coordinate pair
public:
    Point();            // default constructor
    Point( double xVal, double yVal );  // normal constructor
    // mutators, set X and Y
    void setAll( double xVal, double yVal );
    // observers
    double getX( void ) const;
    double getY( void ) const;
    friend ostream &operator <<( ostream &out, const Point &p );
    double distance( Point &b ); // return distance between self and b
};

#endif  // POINT_H_INCLUDED

