//
// point.cpp
//
// Keith Mehl
// 2/21/07
// CSCI-15 Example program - a simple point class
//

#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

class POINT
{
private:
   double x, y;   // coordinates for the point
public:
   POINT();
   POINT( double xx, double yy );
   POINT Translate( double dx, double dy );
   double Distance( POINT p );
   void setAll( double xx, double yy );
   void Print( ostream &out );
};

// default constructor, create point ( 0.0, 0.0 )
POINT::POINT()
{
   x = y = 0.0;
}
// normal constructor, create point ( xx, yy )
POINT::POINT( double xx, double yy )
{
   x = xx;
   y = yy;
}
// create a new point from self, offset by delta-x, delta-y
// and return the new point to the client
POINT POINT::Translate( double dx, double dy )
{
   // you don't need to use this->x or this->y here
   // just x and y will work, since unless otherwise specified,
   // this-> is implied for class data members in object
   // on which the method is invoked.
   // (*this).y is equivalent to this->y
   POINT newPt( this->x + dx, (*this).y + dy );
   return newPt;
}

// get distance from this point (self) to parameter
double POINT::Distance( POINT p )
{
   double dx = this->x - p.x;  // explicitly reference self
   double dy = y - p.y;  // y alone is equivalent to this->y
   return sqrt( ( dx * dx ) + ( dy * dy ) );
}

// manipulator to set point to ( xx, yy )
void POINT::setAll( double xx, double yy )
{
    x = xx;
    y = yy;
    return;
}

// print self in form ( x, y ) -- notice - NO endl or newline!
// output to either a file handle or cout as specified
void POINT::Print( ostream &out )
{
   out << "( " << x << ", " << y << " )" << flush;
}

// now a simple driver for the class
int main()
{
   // point a is specified, b and c are defaulted to ( 0, 0 )
   POINT a( 3.0, 4.0 ), b, c;
   double x, y;
   cout << "Distance from origin to point a is " 
        << a.Distance( b ) << endl;
   cout << "Point a is ";
   a.Print( cout );
   cout << "\nPoint b is ";
   b.Print( cout );
   c = a.Translate( 2.25, -1.5 );
   cout << "\nAfter translation, point c is ";
   c.Print( cout );
   cout << "\nand the distance from c to the origin is "
        << b.Distance( c ) << endl;
   cout << "Enter new x : " << flush;
   cin  >> x;
   cout << "Enter new y : " << flush;
   cin  >> y;
   b.setAll( x, y );
   cout << "Your point is ";
   b.Print( cout );
   cout << " and the distance from a to your point is " 
        << a.Distance( b ) << endl;
   return 0;
}




