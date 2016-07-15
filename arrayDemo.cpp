//
// arrayDemo.cpp
//
// Keith Mehl
// 10/6/2011
// CSCI-15 example program
// Show that with an array a[], a[i] is equivalent to i[a]
//
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
   int a[5] = { 5, 3, 1, 2, 4 }, i;
   for( i = 0; i < 5; i++ )
   {
      cout << setw(3) << a[i];  // *(a+i)
   }
   cout << endl;
   for( i = 0; i < 5; i++ )
   {
      cout << setw(3) << i[a];  // *(i+a)
   }
   cout << endl;
   return 0;
}

