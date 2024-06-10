#include <iostream>
#include <conio.h>
using namespace std;

int main()
{
    int a = 1234;
    int *p = &a;
    cout << "A: " << a << endl;
    cout << "Address of A: " << p << endl;
    cout << "Value of A: " << *p << endl;
    cout << "Address of P: " << &p << endl;
    
    return 0;
}