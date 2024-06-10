#!/bin/bash

# Function to find the largest among three numbers
find_largest() {
    num1=$1
    num2=$2
    num3=$3

    if [ $num1 -gt $num2 ] && [ $num1 -gt $num3 ]; then
        largest=$num1
    elif [ $num2 -gt $num1 ] && [ $num2 -gt $num3 ]; then
        largest=$num2
    else
        largest=$num3
    fi

    echo "The largest among $num1, $num2, and $num3 is: $largest"
}

# Prompt the user to enter three numbers
echo "Enter three numbers:"
read num1
read num2
read num3

# Call the function to find the largest
find_largest $num1 $num2 $num3