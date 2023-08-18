# PROGRAM 10 : Check whether given year is leap year or not...
# Programmer : Haysten D'costa
#!/bin/bash

year=`date +%Y` # gives the current year....

if [ `expr $year % 4` -eq 0 ] # if year is divisible by 4, leap year else not a leap year....
then
    echo "$year is a leap year."
else
    echo "$year is not a leap year."
fi
