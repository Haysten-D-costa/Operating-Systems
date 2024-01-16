#!/bin/bash
#Problem Statement: Reverse a number
#Name: Valerian Coelho

echo "Enter a number : "
read n

rev=0

while [ $n -ne 0 ]
do
    d=`expr $n % 10`
    rev=`expr $rev \* 10 + $d`
    n=`expr $n / 10`
done

echo "Reversed Number :" $rev
