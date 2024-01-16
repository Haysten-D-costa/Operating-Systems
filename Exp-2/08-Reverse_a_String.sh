#!/bin/bash
#Problem Statement: Reverse a String
#Valerian Coelho


echo -n "Enter a string : "
read string
len=${#string}	

for ((i=$len-1; i>=0; i--))
do
    reverse="$reverse${string:$i:1}"
done
echo "$reverse"
