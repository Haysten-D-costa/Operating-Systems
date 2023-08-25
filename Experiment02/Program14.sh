# PROGRAM 14 : Write shell script to generate following series : 20, 22, 18, 20, 16, 18, 14, 16....
# Programmer : Haysten D'costa
#!/bin/bash

i=1
num=20
echo -n "Enter the no. of terms : " # reading the no. of terms in series....
read n
while [ $i -le `expr $n` ]
do
    printf $num" " # displaying the term....
    if [ `expr $i % 2` -ne 0 ]
    then
        num=`expr $num + 2`
    else
        num=`expr $num - 4`
    fi
    i=`expr $i + 1` # to increment i....
done
echo

: ' # OR

term_e=22
term_o=20
for(( i=1; i<=n; i++ ))
do
    if [ `expr $i % 2` -ne 0 ]
    then
        printf $term_o" "
        term_o=`expr $term_o - 2`
    else
        printf $term_e" "
        term_e=`expr $term_e - 2`
    fi
done
'