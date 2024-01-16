#!/bin/bash
#Program Statement: Patterns
#Valerian Coelho

echo 'Enter the value of n : '
read n

for((i=4; i>0; i--))
do
    for((j=$n-$i+1; j<=n; j++))
    do
        printf $j
    done
    printf '\n'
done
