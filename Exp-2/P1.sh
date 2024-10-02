#!/bin/bash

time=`date +"%H"`;

if [ $time -le 12 ]
then
    echo "Good Morning"
elif [ $time -le 4 ]
then
    echo "Good Afternoon"
else 
    echo "Good Evening"
fi