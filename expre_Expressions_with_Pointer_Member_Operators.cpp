// expre_Expressions_with_Pointer_Member_Operators.cpp
// compile with: /EHsc
// source:
// https://msdn.microsoft.com/en-us/library/vstudio/k8336763(v=vs.100).aspx
#include <iostream>

using namespace std;

class Testpm
{
public:
    void m_func1()
    {
        cout << "m_func1\n";
    }
    int m_num;
};

// Define derived types pmfn and pmd.
// These types are pointers to members m_func1() and
// m_num, respectively.
void (Testpm::*pmfn)() = &Testpm::m_func1;
int Testpm::*pmd = &Testpm::m_num;

int main()
{
    Testpm ATestpm;
    Testpm *pTestpm = new Testpm;

// Access the member function
    (ATestpm.*pmfn)();
    (pTestpm->*pmfn)();   // Parentheses required since * binds
    // less tightly than the function call.

// Access the member data
    ATestpm.*pmd = 1;
    pTestpm->*pmd = 2;

    cout  << ATestpm.*pmd << endl
          << pTestpm->*pmd << endl;
    delete pTestpm;
}
