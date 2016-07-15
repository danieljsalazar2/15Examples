//
// RecursiveQueens.cpp
//
// Keith Mehl
// 2/27/02
// CSCI-15 example program
// Illustrate a backtracking algorithm via recursion
// Solve the 8 queens problem - put 8 queens on a
// chessboard so that none of the queens attach any other queen
//

#include <iostream>
#include <cstdlib>      // for exit()
using namespace std;

// return true if square at position r,c is attacked by any queen on the board
bool IsAttacked( char board[][8], int r, int c )
{
   int i, j;
   // test upper-left diagonal
   for( i = r-1, j = c-1; i >= 0 && j >= 0; i--, j-- )
   {
      if( board[i][j] == 'Q' )
      {
         return true;
      }
   }
   // test upper-right diagonal
   for( i = r-1, j = c+1; i >= 0 && j <= 7; i--, j++ )
   {
      if( board[i][j] == 'Q' )
      {
         return true;
      }
   }
   // test lower-left diagonal
   for( i = r+1, j = c-1; i <= 7 && j >= 0; i++, j-- )
   {
      if( board[i][j] == 'Q' )
      {
         return true;
      }
   }
   // test lower-right diagonal
   for( i = r+1, j = c+1; i <= 7 && j <= 7; i++, j++ )
   {
      if( board[i][j] == 'Q' )
      {
         return true;
      }
   }
   // this row (rank)
   for( i = 0; i < 8; i++ )
   {
      if( board[i][c] == 'Q' )
      {
         return true;
      }
   }
   // this col (file )
   for( j = 0; j < 8; j++ )
   {
      if( board[r][j] == 'Q' )
      {
         return true;
      }
   }
   return false;
}

// print the chessboard in very simple style
void printBoard( char board[][8] )
{
   int i, j;
   for( i = 0; i < 8; i++ )
   {
      for( j = 0; j < 8; j++ )
      {
         cout << ( ( board[i][j] == ' ' ) ? '-' : 'Q') << flush;
      }
      cout << endl;
   }
   cout << endl;
   return;
}

// recursive (backtracking) place queen function
// parameters are board and number of queens placed so far
// loop over squares, but use recursion over queen positions
void AddQueen( char board[][8], int n )
{
   int i,j;
   static int prtCtl = 0;  // used to print positions as we search
                 // static to avoid having to pass it between calls
   for( i = 0; i < 8; i++ )      // for each row
   {
      for( j = 0; j < 8; j++ )   // for each column
      {
         if( !IsAttacked( board, i, j ) )  // if we can put a queen here
         {
            board[i][j] = 'Q';  // place queen
            n++;                // count this queen
            if( n == 8 )        // done?
            {
               cout << "Success! --\n" << endl;
               printBoard( board );
                           // exit() leaves the program as though main()
                           // returns with the code passed into exit()
               exit( 0 );  // don't bother to return if success
            }
            // print every 500th time we get to 7 queens
            // test depends on short-circuit evaluation
            if( n == 7 && ++prtCtl >= 500 )
            {
               prtCtl = 0;
               printBoard( board );
               cout << "~~~~~~~~~~~~~~~~~~~~~" << endl;
            }
            AddQueen( board, n );
            // if AddQueen() comes back, it failed to place the queens on
            // the board, so clear out this queen, reset square, and keep
            // trying to place this call's queen on the rest of the board
            n--;
            board[i][j] = ' ';
         }
      }
   }
   return;
}

int main()
{
   char board[8][8];
   cout << "Start of run" << endl;
   for( int i = 0; i < 8; i++ )  // initialize empty board
   {
      for( int j = 0; j < 8; j++ )
      {
         board[i][j] = ' ';
      }
   }
   AddQueen( board, 0 );  // put the queens down
         // if we get back, that means it didn't work
   cout << "You cannot put 8 queens on the board\n"
        << "so that they don't attack each other!" << endl;
   return 0;
}

