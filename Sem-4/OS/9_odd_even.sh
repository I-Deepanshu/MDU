#!/bin/bash

# Function to determine if a number is odd or even
odd_or_even() {
    num=$1

    if [ $((num % 2)) -eq 0 ]; then
        echo "$num is even."
    else
        echo "$num is odd."
    fi
}

# Prompt the user to enter a number
echo "Enter a number:"
read number

# Call the function to determine if the number is odd or even
odd_or_even $number
