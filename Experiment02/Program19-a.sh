# PROGRAM 19(a) : To display the following pattern....
# Programmer : Haysten D'costa
#!/bin/bash

rows=5
for (( i=1; i<=rows; i++ )); do
    for (( j=1; j<=rows-i+1; j++ )); do
       echo -n "* "
    done
    echo
done