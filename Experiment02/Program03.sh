# PROGRAM 03 : Generate the fibonacci series for the number of terms entered by the user....
# Programmer : Haysten D'costa
#!/bin/bash

first_t=0  # 1st term....
second_t=1 # 2nd term....
echo "Enter number of terms : " # prompt user to enter no of terms in series....
read num # reading input from user....

echo "Fibonacii series is : "
for(( i=0; i<num; i++ ))
do
	echo $first_t # first display the 1st term....
	next_t=`expr $first_t + $second_t` # then compute the next term....
	first_t=$second_t # swap (to generete the new 1st and 2nd terms)....
	second_t=$next_t
done