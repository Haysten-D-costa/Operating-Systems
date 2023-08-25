# PROGRAM 19(c) : To display the following pattern....
# Programmer : Haysten D'costa
#!/bin/bash

n=4
for (( i=1; i<=n; i++ )); do
    for (( j=1; j<=i; j++ )); do
        echo -n $i" "
    done
    echo
done