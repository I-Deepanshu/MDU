#include <iostream>
#include <conio.h>
using namespace std;

class Base
{
public:
    int a, b, c;
    Base(int x, int y, int z)
    {
        a = x;
        b = y;
        c = z;
    }

    void display()
    {
        cout << "A: " << a << endl;
        cout << "B: " << b << endl;
        cout << "C: " << c << endl;
    }
};

int main()
{
    Base obj(10, 20, 30);
    obj.display();

    Base *ptr(&obj);
    ptr->display();
}