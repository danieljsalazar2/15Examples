//
// static.cpp
//
// Keith Mehl
// 10/29/2011
// CSCI-15 example program
// Illustrate static class members, using :: to access a static method
//

#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

#define MAX 1000

// example class -- Martians are created and destroyed,
// nMartians could determine how aggressive they are in a game
// idNum is this individual Martian's ID number
// for brevity only, all methods are inline
class Martian
{
private:
   static int nMartians;  // one variable shared by all objects
   int idNum;             // and a local object member variable
public:
   Martian() { idNum = ++nMartians; }    // set idNum to incremented count
   ~Martian() { nMartians--; }           // decrement count
   static int GetCount() { return nMartians; }  // how many Martians?
   int GetID() { return idNum; }         // this Martian's ID number
};

// initialization of the static class variable
//   this CANNOT be done in the class schema
int Martian::nMartians = 0;

int main()
{
   srand( (long)time( NULL ) );
   Martian *martians[MAX] = { NULL };
   int i, j;
   cout << "There are " << Martian::GetCount() << " Martians." << endl;
   for( i = 0; i < MAX; i++ )
   {
      martians[i] = new Martian;
   }
   cout << "There are now " << Martian::GetCount() << " Martians." << endl;
   cout << "The last Martian's value is "  << martians[MAX-1]->GetID() << endl;
   cout << "A randomly chosen ID value is " << martians[rand()%MAX]->GetID() << endl;

   // now delete the Martians, pausing at a random spot to show nMartians
   // the polynomial on rand() called 3 times gives (MUCH)
   // better randomness than just calling rand() alone here
   // try just rand() % MAX here, running it at the DOS CMD shell repeatedly
   // and you'll see how bad a random number generator rand() actually is
   j = ( 2 * rand() * rand() + rand() ) % MAX;
   for( i = MAX-1; i > MAX-j; i-- )
   {
      delete martians[i];
   }
   // access the static method using scope resolution
   cout << "Using :: to get count, there are now " << Martian::GetCount()
        << " Martians." << endl;
   // access the static method using an object
   cout << "Using an object to get count, there are now " << martians[0]->GetCount()
        << " Martians." << endl;
   cout << "martians[0]->GetID() is : " << martians[0]->GetID() << endl;

   // clean out the rest of the martians
   while( i >= 0 )  // i is already set from previous loop
   {
      delete martians[i--];
   }
   cout << "There are now " << Martian::GetCount() << " Martians." << endl;
   return 0;
}


