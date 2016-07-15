//
// array_pointer.cpp
//
// Keith Mehl
// 8/26/13
// CSCI-15 example program
// Illustrate some features of arrays and pointers -- the pairs of functions
// sort1() and swap1(), and sort2() and swap2() are functionally identical
// (there is a tiny difference between them, but it doesn't affect this)
//

#include <iostream>
#include <iomanip>
using namespace std;
#include <cstdlib> // for system()

// swap() using references
void swap1( int &a, int &b )
{
   int t = a;
   a = b;
   b = t;
   return;
}

// very simple sort (ripple sort)
void sort1( int a[], int n )
{
   int i, j;
   cout << "In sort1(), array size is " << sizeof(a) << endl;
   for( i = 0; i < n-1; i++ )
   {
      for( j = i+1; j < n; j++ )
      {
         if( a[i] > a[j] )
         {
            swap1( a[i], a[j] );
         }
      }
   }
   return;
}

// swap() using pointers
void swap2( int *a, int *b )
{
   int t = *a;
   *a = *b;
   *b = t;
   return;
}

// same sort, using pointers
void sort2( int *a, int n )
{
   int i, j;
   cout << "In sort2(), array size is " << sizeof(a) << endl;
   for( i = 0; i < n-1; i++ )
   {
      for( j = i+1; j < n; j++ )
      {
         // notice the compiler handles the sizes of the elements for you
         // the () are needed because * has higher precedence than +
         // also you can just index off the pointer like with an array
         if( *(a+i) > a[j] )
         {
             // a pointer (the base a) + an offset i (an int) yields a pointer
             // or you can take the address of the element a[i]
            swap2( a+i, &a[j] );
         }
      }
   }
   return;
}

// simple print routine, assumes n > 1
void printIt( int a[], int n )
{
   int i;
   cout << a[0];
   for( i = 1; i < n; i++ )
   {
      cout << setw(4) << a[i];
   }
   cout << endl;
   return;
}

int main()
{
   // two identical data arrays
   int a1[10] = { 5, 1, 2, 9, 0, 3, 8, 7, 4, 6 },
       a2[]   = { 5, 1, 2, 9, 0, 3, 8, 7, 4, 6 };
   cout << "In main(), a1 size is " << sizeof(a1) << endl
        << "           a2 size is " << sizeof(a2) << endl;
   printIt( a1, 10 );
   sort1( a1, 10 );
   printIt( a1, 10 );
   cout << "-------------------------------------" << endl;
   printIt( a2, 10 );
   sort2( a2, 10 );
   printIt( a2, 10 );
   return 0;
}

