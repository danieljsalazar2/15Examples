//
// operatorPlus.cpp
//
// Keith Mehl
// October 9, 2010
// CSCI-15 example program
// Introduce an operator method
//

#include <iostream>
using namespace std;

// a very simple implementation of part of an Int class
class Int
{
private:
   int _i;
public:
   Int();
   Int( int i );
   Int add( Int rhs );
   Int operator +( Int rhs ); // operator method
   int getValue();
   void setValue( int i );
};

Int::Int()
{
   _i = 0;
}

Int::Int( int i )
{
   _i = i;
}

Int Int::add( Int rhs )
{
   Int result( _i + rhs._i );
   return result;
}

Int Int::operator +( Int rhs )
{
   Int result( _i + rhs._i );
   return result;
}
int Int::getValue()
{
   return _i;
}

void Int::setValue( int i )
{
   _i = i;
   return;
}

int main()
{
   Int i, j, k, l;
   int x, y;
   cout << "Enter 2 integers : " << flush;
   cin  >> x >> y;
   i.setValue( x );
   j.setValue( y );
   k = i.add( j );
   l = i + j;
   cout << "Sum using add is " << k.getValue() 
        << ", sum using operator + is " << l.getValue() << endl;
   return 0;
}

