#!/bin/bash
#Problem Statement: Display the Number Table
#Name: Valerian Coelho

echo "Enter the value of n :-"
read n

for((i=1; i<=10; i++))
do
    echo $n \* $i = `expr $n \* $i`
done