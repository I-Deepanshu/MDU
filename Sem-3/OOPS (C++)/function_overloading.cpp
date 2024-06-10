
#include <iostream>

using namespace std;

class Calculator
{
public:
    // Function to add two integers
    int add(int a, int b)
    {
        return a + b;
    }

    // Function to add three integers
    int add(int a, int b, int c)
    {
        return a + b + c;
    }
};

int main()
{
    Calculator calc;
    int x = 5, y = 10, z = 15;

    // Call the first add function
    cout << "Sum of " << x << " and " << y << " is " << calc.add(x, y) << endl;

    // Call the second add function
    cout << "Sum of " << x << ", " << y << " and " << z << " is " << calc.add(x, y, z) << endl;

    return 0;
}
