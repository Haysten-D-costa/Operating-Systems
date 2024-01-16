#!/bin/bash
#Problem Statement: Generate the series : 20 22 18 20 16 18 14 
#Name: Valerian Coelho

echo -n "Enter the number of terms in the series : "
read n

a=20

for((i=0; i<n; i++))
do
    echo -n $a ""
    if [ `expr $i % 2` == 0 ]
    then
        a=`expr $a + 2`
    else
        a=`expr $a - 4`
    fi
done
