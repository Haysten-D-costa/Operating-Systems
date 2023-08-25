# PROGRAM 01 : Display greet message using the system time....
# Programmer : Haysten D'costa...
#!/bin/bash

d=`date +"%H"` # following the 24 hour format....

if [ $d -ge 1 -a $d -lt 12 ] 
then
	echo "Good morning Boss !" 
elif [ $d -ge 12 -a $d -lt 16 ]
then
	echo "Good afternoon Boss !"
else
	echo "Good evening Boss !"
fi