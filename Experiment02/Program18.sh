# PROGRAM 18 : To sort given numbers in descending order....
# Programmer : Haysten D'costa
#!/bin/bash

echo -n "Enter the array elements : " # Read the entered elements into the array....
read -ra array

size=${#array[@]} # Calculate the size of the array using '#' and '@'....

# Before Sort
echo -n "Before Sorting array : "
for item in ${array[@]}; do # Iterate over the elements in the array and print each element....
    echo -n "$item "
done

# Bubble Sort
for (( i=0; i<size-1; i++ )); do
    for (( j=0; j<size-1-i; j++ )); do
        if [ ${array[$j]} -lt ${array[$j + 1]} ]
        then
            temp=${array[$j]}
            array[$j]=${array[$j+1]}
            array[$j+1]=$temp
        fi
    done
done

# After Sort
echo
echo -n "After Sorting array : "
for item in ${array[@]}; do
    echo -n "$item "
done