# PROGRAM 02 : Find the factorial of a given number....
# Programmer : Haysten D'costa
#!/bin/bash

fact=1
echo "Enter a number : " # prompt user to enter a number....
read num # reading input from user....

for(( i=num; i>0; i-- )) # while num > 0, keep reducing and multiply & store in fact....
do
	fact=`expr $fact \* $i`
done

echo "Factorial is : " $fact # displaying the factorial....