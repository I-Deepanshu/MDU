#!/bin/bash

# Function to print consecutive numbers in reverse order
print_reverse_consecutive_numbers() {
    start=$1
    end=$2

    echo "Consecutive numbers in reverse order from $end to $start:"
    for ((i=end; i>=start; i--))
    do
        echo "$i"
    done
}

# Prompt the user to enter the range
echo "Enter the starting number:"
read start_number
echo "Enter the ending number:"
read end_number

# Call the function to print consecutive numbers in reverse order
print_reverse_consecutive_numbers $start_number $end_number
