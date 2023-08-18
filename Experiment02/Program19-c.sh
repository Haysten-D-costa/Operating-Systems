# PROGRAM 19(c) : To display the following pattern....
#                 1
#                 2 2
#                 3 3 3
#                 4 4 4 4
# Programmer : Haysten D'costa
#!/bin/bash

n=4
for(( i=1; i<=n; i++ )); do
    for(( j=1; j<=i; j++ )); do
        printf $i" "
    done
    echo
done