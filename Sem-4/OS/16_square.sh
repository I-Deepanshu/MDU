#!/bin/bash

# Function to calculate the square of a number
calculate_square() {
    num=$1
    square=$((num * num))
    echo "The square of $num is: $square"
}

# Prompt the user to enter a number
echo "Enter a number:"
read number

# Call the function to calculate the square
calculate_square $number
