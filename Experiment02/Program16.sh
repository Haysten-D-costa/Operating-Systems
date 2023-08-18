# PROGRAM 17 : Generate the series : 1, 3, 2, 4, 3, 5, 4, 6....
# Programmer : Haysten D'costa
#!/bin/bash

term_o=1
term_e=3

echo "Enter no. of terms in series : "; read n
echo "Series is : "
for(( i=1; i<=n; i++ ))
do
    if [ `expr $i % 2` -ne 0 ]
    then
        printf $term_o" "
        term_o=`expr $term_o + 1`
    else 
        printf $term_e" "
        term_e=`expr $term_e + 1`
    fi
done