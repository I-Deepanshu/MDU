#include <iostream>
using namespace std;

class Base
{
public:
    int a;
    Base(int x)
    {
        a = x;
    }
    void show()
    {
        cout << a << endl;
    }
    void operator+(Base b)
    {
        a = b.a + a;
    }
};

int main()
{
    Base obj(10);
    Base obj2(20);
    obj.show();
    obj + obj2;
    obj.show();
}