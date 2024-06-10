#!/bin/bash

# Function to calculate simple interest
calculate_simple_interest() {
    principal=$1
    rate=$2
    time=$3

    # Calculate simple interest
    interest=$((principal * rate * time / 100))

    echo "Principal amount: $principal"
    echo "Rate of interest: $rate%"
    echo "Time period: $time years"
    echo "Simple interest: $interest"
}

# Prompt the user to enter principal amount, rate, and time
echo "Enter the principal amount:"
read principal_amount
echo "Enter the rate of interest (in percentage):"
read interest_rate
echo "Enter the time period (in years):"
read time_period

# Call the function to calculate simple interest
calculate_simple_interest $principal_amount $interest_rate $time_period
