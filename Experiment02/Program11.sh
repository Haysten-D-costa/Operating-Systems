# PROGRAM 11 : To print all the prime numbers less than 20....
# Programmer : Haysten D'costa
#!/bin/bash

limit=20
echo "Prime numbers are : "

for(( i=1; i<=limit; i++ ))
do
    for(( j=2; j<=i; j++ ))
    do
        if [ ` expr $i % $j` -ne 0 ]
        then
            echo $i
        fi
    done
done    