#!/bin/bash

# Function to print consecutive numbers within a range
print_consecutive_numbers() {
    start=$1
    end=$2

    echo "Consecutive numbers from $start to $end:"
    for ((i=start; i<=end; i++))
    do
        echo "$i"
    done
}

# Prompt the user to enter the range
echo "Enter the starting number:"
read start_number
echo "Enter the ending number:"
read end_number

# Call the function to print consecutive numbers
print_consecutive_numbers $start_number $end_number
