#!/bin/bash
#Problem Statement: Sort Elements in descending Order
#Name: Valerian Coelho

echo -n "Enter the array elements : "
read -ra array
size=${#array[@]}

#Before Sort
echo -n "Before Sort : "
for element in ${array[@]}; do
    echo -n $element ""
done

# Bubble Sort
for((i=0; i<size-1; i++)); do
    for((j=0; j<size-i-1; j++)); do
        if [ ${array[$j]} -lt ${array[$j + 1]} ]; then
            temp=${array[$j]}
            array[$j]=${array[$j+1]}
            array[$j+1]=$temp
        fi
    done
done

#After Sort
echo -e "\nAfter Sort : "
for element in ${array[@]}; do
    echo -n $element ""
done
