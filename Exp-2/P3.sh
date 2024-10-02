#!/bin/bash

echo -n "Enter no. of terms : "
read n
first=0
second=1
for (( i=0; i<n; i++ ))
do
    echo -n "$first "
    next=`expr $first + $second`
    first=$second
    second=$next
done
