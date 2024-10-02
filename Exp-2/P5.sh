#!/bin/bash

echo -n "Enter a number : "
read num

rev=0
rem=0
while [ $num -gt 0 ]
 do
    rem=`expr $num % 10`
    rev=`expr $rev \* 10 + $rem`
    num=`expr $num / 10`
done
echo $rev