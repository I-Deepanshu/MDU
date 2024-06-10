#include <iostream>
using namespace std;
void inputTwoValues(int &a, int &b)
{
    cout << "Enter 2 values: ";
    cin >> a >> b;
}

int main()
{
    cout << "Single catch block:";
    int a, b;
    inputTwoValues(a, b);
    try
    {
        if (b == 0)
        {
            throw b;
        }
        else
        {
            cout << "\nNo Exception occurred!\n";
            cout << a / b;
        }
    }
    catch (int)
    {
        cout << "\nCannot divide by 0";
    }

    cout << "\n\nSingle catch block for all exceptions";
    inputTwoValues(a, b);
    try
    {
        if (b == 0)
        {
            throw b;
        }
        else
        {
            cout << "\nNo Exception occurred!\n";
            cout << a / b;
        }
    }
    catch (...)
    {
        cout << "\nCannot divide by 0";
    }

    return 0;
}