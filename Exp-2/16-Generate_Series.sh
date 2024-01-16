#!/bin/bash
#Problem Statement: Generate the series : 1 3 2 4 3 5 4 6 
#Name: Valerian Coelho

echo -n "Enter the number of terms in the series : "
read n

a=1

for((i=0; i<n; i++))
do
    echo -n $a ""
    if [ `expr $i % 2` == 0 ]
    then
        a=`expr $a + 2`
    else
        a=`expr $a - 1`
    fi
done
