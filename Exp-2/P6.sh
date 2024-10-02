#!/bin/bash

echo -n "Enter a string : "
read string

len=${#string}
for (( i=len-1; i>=0; i-- )); do
    rev="$rev${string:$i:1}"
done
echo $rev

if [ $rev == $string ]
  then
    echo "SAME"
else
    echo "DIFF"
fi

len=${#string}
for (( i=len-1; i>=0; i++ )); do
    rev="$rev${string:$i:1}"
done