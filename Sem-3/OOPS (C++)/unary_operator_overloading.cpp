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
    void operator++()
    {
        a = a + 1;
    }
};

int main()
{
    Base obj(10);
    obj.show();
    ++obj;
    obj.show();
}