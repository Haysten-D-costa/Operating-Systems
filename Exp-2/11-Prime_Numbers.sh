#!/bin/bash
#Problem Statement: Display Prime Numbers less than 20
#Name: Valerian Coelho

echo "Enter the value of n : "
read n

echo "Prime Numbers :-"
for((i=2; i<n; i++))
do
    is_prime=1
    for((j=2; j<i; j++))
    do
        if [ `expr $i % $j` == 0 ]
        then
            is_prime=0
        fi
    done
    if [ $is_prime == 1 ]
    then
        echo $i
    fi
done
