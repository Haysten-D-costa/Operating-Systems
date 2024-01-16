#!/bin/bash
#Problem Statement: Check Palindrome
#Valerian Coelho


echo -n "Enter a string : "
read string

len=${#string}	

for ((i=$len-1; i>=0; i--))
do
    reverse="$reverse${string:$i:1}"
done

if [ $reverse == $string ];then
    echo "It is palindrome"
else
    echo "It is not palindrome"
fi
