//
// testCircle.cpp
//
// Keith Mehl
// 10/29/13
// test the Circle class and, by aggregation, the Point class
//

#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

#include "circle.h"

int main()
{
   ifstream fin( "..\\..\\..\\circles.txt" );
   ofstream fout( "..\\..\\..\\circleOut.txt" );
   if( !fin || !fout )
   {
      cout << "Error opening files!" << endl;
      exit( -1 );
   }
   Circle c1, c2( 2.5, 3.25, 4.0 );
   cout << c1 << "--" << c2 << endl;
   cout << "c1 area = " << c1.Area() << ", circumference = "
        << c1.Circumference() << endl;
   cout << "c2 area = " << c2.Area() << ", circumference = "
        << c2.Circumference() << endl;

   fin >> c1;
   while( fin )
   {
      fout << "c1 area = " << c1.Area() << ", circumference = "
           << c1.Circumference() << endl;
      fin >> c1;
   }
   fin.close();
   fout.close();
   return 0;
}

