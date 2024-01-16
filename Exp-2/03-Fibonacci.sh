#!/bin/bash
#Problem Statement: Generate the fibonacci series
#Name: Valerian Coelho

echo "Enter the number of terms : "
read n
a=1
b=1
c=2

echo "Fibonacci Sequence :-"
for((i=1; i<=n; i++))
do
    echo $a
    c=`expr $a + $b`
    a=`expr $b`
    b=`expr $c`
done