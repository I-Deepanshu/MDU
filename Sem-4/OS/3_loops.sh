#!/bin/bash

# Loop using for loop to print numbers from 1 to 5
echo "Printing numbers from 1 to 5 using a for loop:"
for ((i=1; i<=5; i++))
do
    echo "$i"
done

# Loop using while loop to print numbers from 1 to 5
echo "Printing numbers from 1 to 5 using a while loop:"
j=1
while [ $j -le 5 ]
do
    echo "$j"
    j=$((j + 1))
done

# Loop using until loop to print numbers from 1 to 5
echo "Printing numbers from 1 to 5 using an until loop:"
k=1
until [ $k -gt 5 ]
do
    echo "$k"
    k=$((k + 1))
done
