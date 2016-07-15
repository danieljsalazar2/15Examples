//
// circle.h
//
// Keith Mehl
// 10/29/13
// create a circle that "has-a" point (the center) and a radius
//

#ifndef CIRCLE_H_INCLUDED
#define CIRCLE_H_INCLUDED
#include "Point.h"
#include <iostream>
using namespace std;

class Circle
{
friend ostream &operator <<( ostream &out, Circle &c );
friend istream &operator >>( istream &in, Circle &c );
private:
   Point center;
   double radius;
public:
   Circle();
   Circle( double x, double y, double r );
   void SetAll( double x, double y, double r );
   double Area();
   double Circumference();
};

#endif // CIRCLE_H_INCLUDED

