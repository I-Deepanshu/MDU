#include <iostream>
#include <conio.h>
using namespace std;

int main()
{
    int a[5] = {10, 20, 30, 40, 50};
    int *p = a;
    cout << "*p: " << *p << endl;

    p++;
    cout << "p++: " << *p << endl;
    p++;
    cout << "p++: " << *p << endl;
    p--;
    cout << "p--: " << *p << endl;
    p--;
    cout << "p--: " << *p << endl;
    p = p + 2;
    cout << "p = p+2: " << *p << endl;
    p = p - 1;
    cout << "p = p-1: " << *p << endl;

    int *p1 = a;
    p1 = p1 + 3;
    cout << "p1 - p: " << p1 - p << endl;
}