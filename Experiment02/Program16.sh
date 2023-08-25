# PROGRAM 17 : Generate the series : 1, 3, 2, 4, 3, 5, 4, 6....
# Programmer : Haysten D'costa
#!/bin/bash

term=1
echo -n "Enter no. of terms in series : "; read n
echo "Series is : "
for (( i=1; i<=n; i++ ))
do
    echo -n $term" "
    if [ `expr $i % 2` -ne 0 ]
    then
        term=`expr $term + 2`
    else 
        term=`expr $term - 1`
    fi
done