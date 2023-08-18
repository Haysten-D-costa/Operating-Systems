# PROGRAM 19(b) : To display the following pattern....
#                 1 2 3 4
#                 2 3 4
#                 3 4
#                 4 
# Programmer : Haysten D'costa
#!/bin/bash

n=4
for(( i=0; i<n; i++ )); do
    for(( j=i+1; j<=n; j++ )); do
        printf $j" " 
    done
    echo
done