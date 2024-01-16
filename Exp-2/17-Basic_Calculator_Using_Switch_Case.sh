#!/bin/bash
#Problem Statement: Basic Calculator Using Switch Case
#Valerian Coelho

result=0

echo -n "Enter the 1st number : "
read num1

echo -n "Enter the 2nd number : "
read num2

echo "Enter the operation : "
read operation

case $operation in 
    "+")
        result=`expr $num1 + $num2`
        ;;
    "-")
        result=`expr $num1 - $num2`
        ;;
    "*")
        result=`expr $num1 \* $num2`
        ;;
    "/")
        result=`expr $num1 / $num2`
        ;;
    "%")
        result=`expr $num1 % $num2`
        ;;
    *)
        echo "Invalid Operation"
        ;;
esac

echo "Result : " $result
