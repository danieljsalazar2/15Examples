//
// Mid2fall13.cpp
// Keith Mehl
// 12/5/13
// CSCI-15 code solutions for the second midterm
//
#include <iostream>
#include <cmath>
using namespace std;

// question 3
// return type of long is OK, but this is the "most" appropriate return type
unsigned long iFib( unsigned int n )
{
   unsigned long t = n, b1 = 1, b2 = 0;
   while ( n > 1 )
   {
      t = b1 + b2;
      b2 = b1;
      b1 = t;
      n--;
   }
   return t;
}

unsigned long rFib( unsigned int n )
{
   if ( n <= 1 )
   {
      return n;
   }
   return rFib( n -1 ) + rFib( n - 2 );
}
// just some code so you can try this...
void q3()
{
   unsigned long itf, ref;
   unsigned int n;
   cout << "Enter a value for n : " << flush;
   cin  >> n;
   itf = iFib( n );
   ref = rFib( n );
   cout << "Iterative Fib(n) = " << itf << ", recursive Fib(n) = " << ref << endl;
   return;
}

// question 4
// C library abs() takes and returns an int, so isn't the best to use here
// fabs() takes and returns doubles, and will work with floats
// Or, you can test x - y < 0 and change the sign yourself, then test < 10^-9
// you could have a constant 1e-9, too
bool Equals( double x, double y )
{
   return fabs( x - y ) < 1e-9;
}

// question 5
class POINT
{
private:
   // coordinates
   double x, y;
public:
   // write these methods or functions:
   void setAll( double xx, double yy );
   // return the distance between two POINTs: sqrt(delta-x^2 + delta-y^2)
   double distance( POINT &b ); // non-ref is O.K. here
   // calculate and return the slope between two POINTS (?x/?y)
   double slope( POINT &b );
   // print a POINT to an ostream in this form: ( x, y )
   friend ostream &operator <<( ostream &out, const POINT &p );
   // the following methods are here only to make this compile
   // you could assume these existed for the test...
   double getX( void )
   {
      return x;
   }
   double getY( void )
   {
      return y;
   }
};

double POINT::distance( POINT &b )
{
   return sqrt( ( (x - b.x) * (x - b.x) ) + ( (y - b.y) * (y - b.y) ) );
}

// you could have a constant for 1e10, too
double POINT::slope( POINT &b )
{
   return Equals( x, b.x ) ? 1e10 : ( y - b.y ) / ( x - b.x );
}

void POINT::setAll( double xx, double yy )
{
   x = xx;
   y = yy;
   return;
}

ostream &operator <<( ostream &out, const POINT &p )
{
   out << "( " << p.x << ", " << p.y << " )" << flush;
   return out;
}

// question 6
class Quadrilateral
{
protected:  // not private - you want Rectangle to see these
   POINT a, b, c, d;
   virtual void validate();
public:
   friend ostream &operator <<( ostream &out, Quadrilateral &q );
   virtual double Perimeter( void );
};

void Quadrilateral::validate()
{
   if ( a.getX() > b.getX() || b.getY() > c.getY() ||
         c.getX() < d.getX() || d.getY() < a.getY() )
   {
      cout << "Not a valid Quadrilateral\n" << flush;
      a.setAll( 1.0, 1.0 );  // or any values not a rectangle
      b.setAll( 3.0, 1.0 );
      c.setAll( 4.5, 3.5 );
      d.setAll( 1.25, 2.5 );
   }
   return;
}

ostream &operator <<( ostream &out, Quadrilateral &q )
{
   out << "I'm a Quadrilateral " << endl
   << q.a << ' ' << q.b << ' ' << q.c << ' ' << q.d << flush;
   return out;
}

double Quadrilateral::Perimeter( void )
{
   return a.distance( b ) + b.distance( c ) +
          c.distance( d ) + d.distance( a );
}

class Rectangle : public Quadrilateral
{
protected:
   virtual void validate();
public:
   virtual double Perimeter( void );
   friend ostream &operator <<( ostream &out, Rectangle &r );
};

void Rectangle::validate()
{
   Quadrilateral::validate();  // first validate points in correct order
   double ab, bc, cd, da;      // holds slopes for each side
   ab = a.slope( b );
   bc = b.slope( c );
   cd = c.slope( d );
   da = d.slope( a );
   // per the assignment, you may assume ab parallel to X-axis
   // or, take the product of adjacent slopes and check Equals() to -1.0
   if ( !( Equals( ab, 0.0 ) && Equals( cd, 0.0 ) &&
           Equals( bc, 1e10 ) && Equals( da, 1e10 ) ) )
   {
      cout << "Not a legal rectangle\n" << flush;
      a.setAll( 1.0, 1.0 );
      b.setAll( 5.0, 1.0 );
      c.setAll( 5.0, 3.0 );
      d.setAll( 1.0, 3.0 );
   }
   return;
}

double Rectangle::Perimeter( void )
{
   return 2.0 * ( a.distance( b ) + b.distance( c ) );;
}

ostream &operator <<( ostream &out, Rectangle &r )
{
   out << "I'm a Rectangle\n";
   // cast to invoke Quadrilateral's friend operator << function
   out << dynamic_cast< Quadrilateral &>(r);
   return out;
}

int main()
{
   q3();
   return 0;
}

