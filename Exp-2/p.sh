#!/bin/bash
row=4
# for (( i=1; i<=row; i++)); do
#     for (( j=1; j<=row-i+1; j++ )); do 
#         echo -n "* "
#     done
#     echo
# done

# for (( i=1; i<=row; i++ )); do
#     for (( j=0+i; j<=row; j++ )); do
#         echo -n "$j "
#     done
#     echo
# done

for (( i=1; i<=row; i++ )); do
    for (( j=1; j<=i; j++ )); do
        echo -n "$i "
    done
    echo
done




# * * * * * 
# * * * * 
# * * * 
# * * 
# * 

# 1 2 3 4 
# 2 3 4 
# 3 4 
# 4 

# 1 
# 2 2 
# 3 3 3 
# 4 4 4 4 