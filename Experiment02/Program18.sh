# PROGRAM 18 : To sort given numbers in descending order....
# Programmer : Haysten D'costa
#!/bin/bash
# The shebang specifies that this script should be interpreted by the Bash shell.

echo -n "Enter the array elements : " # Prompt the user to enter array elements.
read -ra array # Read the entered elements into the 'array' array.
size=${#array[@]} # Calculate the size of the array using the '@' special variable.

# Before Sort
echo -n "Before Sort : " # Print a message indicating that the array is being displayed before sorting.
for element in ${array[@]}; do
    echo -n $element ""
done # Iterate over the elements in the array and print each element.

# Bubble Sort
for (( i=0; i<size-1; i++ )); do
    for (( j=0; j<size-i-1; j++ )); do
        if [ ${array[$j]} -lt ${array[$j + 1]} ]; then
            temp=${array[$j]}
            array[$j]=${array[$j+1]}
            array[$j+1]=$temp
        fi
    done
done

# After Sort
echo
echo -n "After Sort  : " # Print a message indicating that the array is being displayed after sorting.
for element in ${array[@]}; do
    echo -n $element ""
done # Iterate over the sorted elements in the array and print each element.
