//
// exception.cpp
//
// Keith Mehl
// 10/25/11
// Illustrate basic exception handling: try, catch, throw
// Show standard library exception class
//

#include <iostream>
#include <exception>  // for class exception, defined in std namespace
using namespace std;

// From C++.com's discussion of the exception class:
#if 0   // compile only if 0 is true (which cannot happen)
class exception {
public:
  // some lines from the example are omitted here
  virtual const char* what() const throw();
};
#endif
// this class schema is far from complete, but it hits the high points.
// the important method is what(), which you must override in derived classes

//
// the class MyException "publicly extends" the standard library exception class
// the method what()
//    is "virtual" (allows polymorphic behavior)
//    returns a "const char *" so the client can't modify its data
//    the trailing const means it will not change anything in the class
//    will not throw anything itself - throw() with no parameters
// I put the code in the class schema because this
//    is just a "quick-and-dirty" example
//
class MyException : public exception
{
public:
   virtual const char * what() const throw()
   {
      return "This is an exception object";
   }
};

// declare a MyException object, throw it and catch it, printing its message
int main ()
{
   MyException m;
   try
   {
      throw m;
   }
   catch (MyException &myEx)  // note the reference here...
   {
       cout << myEx.what() << endl;
   }
   return 0;
}


