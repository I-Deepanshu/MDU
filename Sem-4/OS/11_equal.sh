#!/bin/bash

# Function to check if two numbers are equal
are_equal() {
    num1=$1
    num2=$2

    if [ $num1 -eq $num2 ]; then
        echo "The numbers $num1 and $num2 are equal."
    else
        echo "The numbers $num1 and $num2 are not equal."
    fi
}

# Prompt the user to enter two numbers
echo "Enter the first number:"
read number1
echo "Enter the second number:"
read number2

# Call the function to check if the numbers are equal
are_equal $number1 $number2
