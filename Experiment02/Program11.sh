# PROGRAM 11 : To print all the prime numbers less than 20....
# Programmer : Haysten D'costa
#!/bin/bash

limit=20
echo "Prime numbers are : "

for (( i=2; i<limit; i++ ))
do
    is_prime=1
    for (( j=2; j<i; j++ ))
    do
        if [ `expr $i % $j` -eq 0 ]; then # if 'i' is divisible by any-number, => 'i' not prime....
            is_prime=0
        fi
    done
    if [ $is_prime ]
    then
        echo -n "$i "
    fi
done    
echo