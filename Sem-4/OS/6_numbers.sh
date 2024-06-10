#!/bin/bash

# Function to count up to a specified number
count_up_to() {
    end=$1
    echo "Counting up to $end:"
    for ((i=1; i<=end; i++))
    do
        echo "$i"
    done
}

# Prompt the user to enter the number
echo "Enter a number to count up to:"
read number

# Call the function to count up to the specified number
count_up_to $number
