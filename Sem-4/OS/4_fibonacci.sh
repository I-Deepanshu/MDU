#!/bin/bash

# Function to calculate Fibonacci series
fibonacci() {
    n=$1
    a=0
    b=1
    echo "Fibonacci series up to $n terms:"
    for ((i=0; i<n; i++))
    do
        echo -n "$a "
        fn=$((a + b))
        a=$b
        b=$fn
    done
    echo
}

# Prompt the user to enter the number of terms
echo "Enter the number of terms for the Fibonacci series:"
read num_terms

# Call the function to print the Fibonacci series
fibonacci $num_terms
