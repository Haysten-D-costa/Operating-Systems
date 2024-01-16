#!/bin/bash
#Program Statement: Check if Number is even or odd
#Valerian Coelho

echo 'Enter a number : '
read num

if [ `expr $num % 2` == 0 ]
then 
    echo 'The Number is even'
else
    echo 'The Number is odd'
fi
