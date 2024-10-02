# PROGRAM 11 : To print all the prime numbers less than 20....
# Programmer : Haysten D'costa
#!/bin/bash

limit=20
echo "Prime numbers are : "

for ((i=2; i<limit; i++))
 do
    is_prime=1
    for ((j=2; j*j<=i; j++))
     do
        if [ $((i % j)) -eq 0 ]
         then
            is_prime=0
            break
        fi
    done
    if [ $is_prime -eq 1 ]
     then
        echo -n "$i "
    fi
done    
echo