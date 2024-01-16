#!/bin/bash
#Problem Statement: Greet Message
#Valerian Coelho

time=`date +"%H"`

if [ $time -le 12 ];then
    echo "Good Morning"
elif [ $time -le 16 ];then
    echo "Good Afternoon"
else
    echo "Good Evening"
fi
