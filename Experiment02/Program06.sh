# PROGRAM 06 : To print the largest of 3 numbers entered by the user....
# Programmer : Haysten D'costa
#!/bin/bash

echo -n "Enter first number  : "; read num1 # reading 3 numbers....
echo -n "Enter second number : "; read num2
echo -n "Enter third number  : "; read num3

if [ $num1 -eq $num2 -a $num2 -eq $num3 ]; then  # if all numbers are equal, exit....
	echo "All three numbers are equal...."
	exit
fi

if [ $num1 -gt $num2 ]; then # compare num1 and num2....
	if [ $num1 -gt $num3 ]; then # compare num1 and num3....
		echo "First number is GREATEST !"
	else
		echo "Second number is GREATEST !"
	fi
else
	if [ $num2 -gt $num3 ]; then # compare num2 and num3....
		echo "Second number is GREATEST !"
	else
		echo "Third number is GREATEST !"
	fi
fi
