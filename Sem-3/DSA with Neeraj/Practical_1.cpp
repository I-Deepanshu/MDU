/*
Program to perform operations on an array
Author: Neeraj
Date: October 10, 2023
*/

#include <iostream>
using namespace std;

int main()
{
    // Delcalre array 
    int arr[5];
    int i, sum = 0, max = 0, min = 0;

    // Input array elements
    cout << "Enter array elements: ";
    for (i = 0; i < 5; i++)
    {
        cin >> arr[i]; 
    }

    // Display array elements
    cout << "Array elements are: ";
    for (i = 0; i < 5; i++)
    {
        cout << arr[i] << " ";
    }

    // perform deletion in array
    int pos;
    cout << "\nEnter position to delete element: ";
    cin >> pos;
    for (i = pos - 1; i < 5; i++)
    {
        arr[i] = arr[i + 1];
    }

    //  Display array elements after deletion
    cout << "Array elements after deletion are: ";
    for (i = 0; i < 4; i++)
    {
        cout << arr[i] << " "; 
    }

    return 0;
}
