//
// polyTypeid.cpp
// Keith Mehl
// 11/3/09
// CSCI-15 example program
// using typeid with polymorphic class objects
//

#include <iostream>
#include <typeinfo>
using namespace std;

// Absolute minimal class definitions
class CBase
{
    virtual void f() {}
};
class CDerived : public CBase
{
    virtual void f() {}
};

int main ()
{
    CBase* a = new CBase;
    CBase* b = new CDerived;
    cout << "a is: " << typeid(a).name() << '\n';
    cout << "b is: " << typeid(b).name() << '\n';
    cout << "*a is: " << typeid(*a).name() << '\n';
    cout << "*b is: " << typeid(*b).name() << '\n';
    delete a;
    delete b;
    return 0;
}

