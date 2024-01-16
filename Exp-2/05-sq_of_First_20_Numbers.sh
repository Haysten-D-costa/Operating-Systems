#!/bin/bash
#Problem Statement: square of first 20 numbers
#Valerian Coelho

for((i=1; i<=20; i++))
do
    echo $i\*$i = `expr $i \* $i`
done
