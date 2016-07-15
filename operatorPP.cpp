//
// operatorPP.cpp
//
// Keith Mehl
// 11/9/09
// CSCI-15 Example program
// Illustrate operator ++, operator +, and type coercion operators
// on a simple Int class
//

#include <iostream>
using namespace std;

class Int
{
private:
    int _i;
public:
    Int( int = 0 );            // constructor
    Int add( Int rhs );
    Int operator +( Int rhs ); // operator method
    int getValue();
    void setValue( int i );
    Int operator++();          // pre-increment operator
    Int operator++( int );     // post-increment operator
    operator int();            // type coercion operator
};

Int::Int( int i )             // constructor
{
    _i = i;
}
Int Int::add( Int rhs )
{
    Int result( _i + rhs._i );
    return result;
}

// two ways to write this
Int Int::operator +( Int rhs )
{
    // Int result( _i + rhs._i );
    // return result;
    return add( rhs );
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
Int Int::operator++()         // pre-increment
{
    ++_i;
    return *this;
}

Int Int::operator++( int i )  // post-increment
{
    Int t;
    t._i = _i;
    _i++;
    return t;
}

// notice this has NO return type - it's implicit from the operation
Int::operator int()           // implicit cast (coercion) operator
{
    return _i;
}

int main()
{
    Int a(3), b;
    Int i, j, k, l = 5;
    int x, y;
    cout << "a = " << a.getValue() << " b = " << b.getValue() << endl;
    cout << "b = ++a\n";
    b = ++a;
    cout << "a = " << a.getValue() << " b = " << b.getValue() << endl;
    cout << "b = a++\n";
    b = a++;
    cout << "a = " << a.getValue() << " b = " << b.getValue() << endl;
    cout << "\nEnter 2 integers : " << flush;
    cin  >> x >> y;
    cout << x << ' ' << y << endl;
    i.setValue( x );
    j.setValue( y );
    k = i.add( j );
    l = i + j;
    cout << "Sum using add is " << k.getValue()
         << "\nsum using operator + is " << l.getValue()
         << "\nCoerced to an int, sum is " << l << endl;
    return 0;
}

