#!/bin/bash

# Function to print all numbers in a decade
print_decade_numbers() {
    decade=$1

    start=$((decade * 10))
    end=$((start + 9))

    echo "Numbers in the decade $decade:"
    for ((i=start; i<=end; i++))
    do
        echo "$i"
    done
}

# Prompt the user to enter the decade
echo "Enter the decade (e.g., 2020 for the decade 2020-2029):"
read decade_number

# Call the function to print all numbers in the decade
print_decade_numbers $decade_number
