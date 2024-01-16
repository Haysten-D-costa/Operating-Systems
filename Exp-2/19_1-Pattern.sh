#!/bin/bash
#Program Statement: Patterns
#Valerian Coelho

echo 'Enter the value of n : '
read n

for((i=4; i>0; i--))
do
    for((j=1; j<=i; j++))
    do
        printf '*'
    done
    printf '\n'
done
