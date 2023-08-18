# PROGRAM 06 : To print the largest of 3 numbers entered by the user....
# Programmer : Haysten D'costa
#!/bin/bash

echo "Enter first number  : "; read num1 # reading 3 numbers....
echo "Enter second number : "; read num2
echo "Enter third number  : "; read num3

if [ $num1 -eq $num2 -a $num2 -eq $num3 ] # if all numbers are equal, exit....
then 
	echo "All three numbers are equal...."
	exit
fi

if [ $num1 -gt $num2 ] # compare num1 and num2....
then
	if [ $num1 -gt $num3 ] # compare num1 and num3....
	then
		echo "First number is GREATEST !"
	else
		echo "Second number is GREATEST !"
	fi
else
	if [ $num2 -gt $num3 ] # compare num2 and num3....
	then
		echo "Second number is GREATEST !"
	else
		echo "Third number is GREATEST !"
	fi
fi
