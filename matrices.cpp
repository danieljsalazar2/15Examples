//
// matrices.cpp
//
// Keith Mehl 10/30/2000
// CSCI-15 Example program -- Illustrate multi-dimensional arrays and
// ragged arrays.  2-dimensional arrays are often called matrices.
// Also, introduce pointers and the relationship between pointers
// and arrays.
//

#include <iostream>
#include <iomanip>
using namespace std;

int main( void )
{
   int i, j;   // loop control variables
               // example matrices below...
   // first a 2-d array, an array of 1-d arrays, initialized
   int matrix[3][4] = { { 1, 2, 3, 4 }, { 5, 6, 7, 8 }, { 9, 10, 11, 12 } };
   // now three 1-d arrays, initialized
   int m1[4] = { 4, 3, 2, 1 }, m2[4] = { 8, 7, 6, 5 }, m3[4] = { 12, 11, 10, 9 };
   // now a ragged array - an array of pointers to ints
   // any pointer may be indexed
   // (whether or not it actually points to an array - be careful!)
   // the name of a 1-d array itself is of type "const pointer to element type",
   // so the initialization of the array's three int * elements works
   int *tricks[3] = { m2, m3, m1 }; // shuffled so aren't consecutive in RAM
   int *mPtr; // and a work pointer

   // first, print the 2 arrays using normal indexing
   cout << "matrix is:" << endl;
   for( i = 0; i < 3; i++ )     // for each row
   {
      for( j = 0; j < 4; j++ )  // for each column
      {
         cout << setw(6) << matrix[i][j] << flush;
      }
      cout << endl;
   }
   cout << "tricks is:\n" << flush;
   for( i = 0; i < 3; i++ )     // for each row
   {
      for( j = 0; j < 4; j++ )  // for each "column" (ragged array)
      {
         cout << setw(6) << tricks[i][j] << flush;
      }
      cout << endl;
   }
   // Illustrate that the 2-d matrix MUST be contiguous in memory
   // Note: I CANNOT do this with the tricks ragged array!
   // Adding 1 to a pointer adds the size of an element, not just 1
   //
   // NOTE! ---------------------------------------------------------
   // DO NOT EVER DO THIS with a normal 2-d array!
   // ALWAYS treat a 2-d array as a 2-d array!
   // This is for illustration purposes ONLY!
   // ---------------------------------------------------------------
   //
   cout << "using a direct pointer into 2-d matrix :\n" << flush;
   mPtr = &matrix[0][0];       // get base of matrix
   while( mPtr < (&matrix[0][0]) + 12 ) // +12 is plus 12 elements
   {
      // The right-hand-side unary operators have higher
      // precedence than the left-hand-side unary operators.
      // Thus, the expression *mPtr++ saves the pointer mPtr's
      // value, points mPtr at the next int, then dereferences the old
      // value of mPtr to get the integer it points to for printing.
      cout << setw(6) << *mPtr++;
   }
   // Illustrate how the actual indexing math is done
   cout << "\nusing pointer math in matrix\n" << flush;
   mPtr = &matrix[0][0];       // get base of matrix
         // why can't I just put mPtr = matrix here instead of & and [0][0]?
   for( i = 0; i < 3; i++ )    // for each row
   {
      for( j = 0; j < 4; j++ ) // for each column
      {
         // this is the actual math the compiler does for indexing
         // base + (rows to skip * row length) + columns to skip
         cout << setw(6) << *(mPtr + 4 * i + j) << flush;
      }
      cout << endl;
   }
   // Illustrate that the 2-d array is just an array of 1-d arrays.
   //
   // NOTE! ---------------------------------------------------------
   // DON'T DO THIS! EVER! ALWAYS treat a 2-d array as a 2-d array!
   // ---------------------------------------------------------------
   //
   cout << "Treating matrix as a 1-d array\n" << flush;
   for( i = 0; i < 12; i++ )
   {     // select the 0th row, then i-th column to get to the elements
      cout << setw(6) << matrix[0][i] << flush;
   }
   cout << endl;
   return 0;
}

