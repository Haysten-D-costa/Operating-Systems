# PROGRAM 09 : To check whether entered number is even or odd....
# Programmer : Haysten D'costa
#!/bin/bash

echo "Enter a number : "
read num

remainder=`expr $num % 2` # computing remainder....
if [ $remainder -eq 0 ] # if remainder is equal to 0, then even else odd....
then
    echo "Number is even !"
else
    echo "Number is odd !"
fi