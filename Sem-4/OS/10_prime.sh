#!/bin/bash

# Function to check if a number is prime
is_prime() {
    num=$1
    isPrime=true

    if [ $num -eq 0 ] || [ $num -eq 1 ]; then
        isPrime=false
    else
        for ((i=2; i<=num/2; i++))
        do
            if [ $((num % i)) -eq 0 ]; then
                isPrime=false
                break
            fi
        done
    fi

    if $isPrime; then
        echo "$num is a prime number."
    else
        echo "$num is not a prime number."
    fi
}

# Prompt the user to enter a number
echo "Enter a number:"
read number

# Call the function to check if the number is prime
is_prime $number
