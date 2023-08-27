# PROGRAM 17 : Write a shell script to prompt user to enter 2 numbers and perform various arithmetic operations using switch statement....
# Programmer : Haysten D'costa
#!/bin/bash

echo "Enter two numbers : "
read num1
read num2

echo -n "Enter the operator : "
read operator

case "$operator" in
    "+") 
        echo "Result : $(($num1 + $num2))"
        ;;
    "-") 
        echo "Result : $(($num1 - $num2))"
        ;;
    "*") 
        echo "Result : $(($num1 * $num2))"
        ;;
    "/") 
        echo "Result : $(($num1 / $num2))"
        ;;
    "%") 
        echo "Result : $(($num1 % $num2))"
        ;;
    *) 
        echo "Invalid operator !"
esac