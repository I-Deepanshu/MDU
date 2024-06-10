#!/bin/bash

# Function to check if a character is a vowel
is_vowel() {
    char=$1
    vowels="aeiouAEIOU"

    if [[ $vowels == *"$char"* ]]; then
        echo "$char is a vowel."
    else
        echo "$char is not a vowel."
    fi
}

# Prompt the user to enter a character
echo "Enter a character:"
read character

# Call the function to check if the character is a vowel
is_vowel $character
