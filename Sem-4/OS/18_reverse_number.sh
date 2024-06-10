#!/bin/bash

# Function to reverse a number
reverse_number() {
    original_number=$1
    reversed_number=0

    while [ $original_number -gt 0 ]
    do
        remainder=$((original_number % 10))
        reversed_number=$((reversed_number * 10 + remainder))
        original_number=$((original_number / 10))
    done

    echo "Reversed number: $reversed_number"
}

# Prompt the user to enter a number
echo "Enter a number:"
read number

# Call the function to reverse the number
reverse_number $number
