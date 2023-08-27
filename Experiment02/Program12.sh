# PROGRAM 12 : To check if the entered string is palindromic or not....
# Programmer : Haysten D'costa
#!/bin/bash

echo -n "Enter a string : "
read string

len=${#string} # gives the length of the string....
for (( i=$len-1; i>=0; i-- )); do # from last to first char, store in reverse....
    reverse="$reverse${string:$i:1}"
done

if [ $reverse == $string ]; then
    echo "String is a palindrome"
else 
    echo "String not a palindrome"
fi