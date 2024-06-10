#!/bin/bash

# Function to check if a string is a palindrome
is_palindrome() {
    string=$1
    reversed_string=$(echo "$string" | rev)

    if [ "$string" == "$reversed_string" ]; then
        echo "$string is a palindrome."
    else
        echo "$string is not a palindrome."
    fi
}

# Prompt the user to enter a string
echo "Enter a string:"
read input_string

# Call the function to check if the string is a palindrome
is_palindrome "$input_string"
