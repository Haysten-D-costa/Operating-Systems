# PROGRAM 07 : To reverse a number....
# Programmer : Haysten D'costa
#!/bin/bash

echo -n "Enter a number : "
read num

echo # 'echo' is used to print a new line....
echo -n "Reversed number is : " # 'printf' can be used to display content without a new line....
while [ $num -gt 0 ] # while number greater than 0, remove and display the last digit....
do
    remainder=`expr $num % 10`
    num=`expr $num / 10`
    printf $remainder
done
echo # to display a new line...