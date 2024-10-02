#!/bin/bash

limit=10
echo -n "Enter a number : "
read n

for (( i=1; i<=limit; i++))
do
    echo "$n x $i = `expr $n \* $i`"
done