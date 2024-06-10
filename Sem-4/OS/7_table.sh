#!/bin/bash

# Function to generate the multiplication table of a number
multiplication_table() {
    num=$1
    echo "Multiplication table of $num:"
    for ((i=1; i<=10; i++))
    do
        result=$((num * i))
        echo "$num x $i = $result"
    done
}

# Prompt the user to enter the number
echo "Enter a number to generate its multiplication table:"
read number

# Call the function to generate the multiplication table
multiplication_table $number
