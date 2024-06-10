#!/bin/bash

# Prompt the user to enter two numbers
echo "Enter the first number:"
read num1
echo "Enter the second number:"
read num2

# Perform addition
sum=$((num1 + num2))
echo "The sum of $num1 and $num2 is: $sum"

# Perform subtraction
difference=$((num1 - num2))
echo "The difference between $num1 and $num2 is: $difference"

# Perform multiplication
product=$((num1 * num2))
echo "The product of $num1 and $num2 is: $product"

# Perform division
if [ $num2 -eq 0 ]; then
    echo "Error: Division by zero!"
else
    quotient=$((num1 / num2))
    echo "The quotient of $num1 divided by $num2 is: $quotient"
fi