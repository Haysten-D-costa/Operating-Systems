#!/bin/bash
#Problem Statement: Calculate the factorial of a number
#Name: Valerian Coelho

echo "Enter the value of n :- "
read n
fact=1
i=1

while [ $i -le $n ]
do
    fact=`expr $fact \* $i`
    i=`expr $i + 1`
done

echo "Factorial :" $fact