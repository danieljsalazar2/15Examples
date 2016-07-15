//
// args.cpp
//
// Keith Mehl 1/28/07
// CSCI-15 Example program
// Illustrate argc (count of strings on the command line)
// and argv (vector of pointers to each token on the command line)
// command-line arguments; and more on pointers
//

#include <iostream>
using std::cin;      // name only those labels in namespace std we're using
using std::cout;
using std::endl;
using std::flush;

// argc -- number of tokens on the command line, counting the program name
// argv -- array of pointers to C-strings holding tokens on the command line
// argv is a "ragged array" - an array of pointer to arrays, not a 2-d array
int main( int argc, char *argv[] )
{
    int i;
    for( i = 0; i < argc; i++ )
    {
        // given a pointer to a char,
        // cout << treats it as a C-string and prints characters up to the NUL
        cout << "argv[" << i << "] is " << argv[i] << endl;
    }
    cout << "The addresses of the arguments are" << endl;
    for( i = 0; i < argc; i++ )
    {
        // given a pointer to void (a "void pointer"),
        // cout << treats it as a generic pointer & prints hexadecimal address
        cout << "Address of argv[" << i << "] is " << (void *)argv[i] << endl;
    }
    cout << "The address of the argument vector itself is" << endl;
    cout << (void *)argv << endl;
    // (*argv) is "the thing pointed to by argv" - a pointer to a char
    // (void *) casts that to a "pointer to void"
    // i.e. a pointer to a data type about which we can know nothing
    cout << "The address of the zeroth argument in the argument vector is"
         << endl << (void *)(*argv) << endl;
    return 0;
}

