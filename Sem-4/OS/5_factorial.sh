#!/bin/bash

# Function to calculate factorial
factorial() {
    num=$1
    fact=1
    for ((i=1; i<=num; i++))
    do
        fact=$((fact * i))
    done
    echo "The factorial of $num is: $fact"
}

# Prompt the user to enter the number
echo "Enter a number to calculate its factorial:"
read number

# Call the function to calculate factorial
factorial $number
