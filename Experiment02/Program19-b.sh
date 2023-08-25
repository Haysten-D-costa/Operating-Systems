# PROGRAM 19(b) : To display the following pattern....
# Programmer : Haysten D'costa
#!/bin/bash

n=4
for (( i=0; i<n; i++ )); do
    for (( j=i+1; j<=n; j++ )); do
        echo -n $j" " 
    done
    echo
done