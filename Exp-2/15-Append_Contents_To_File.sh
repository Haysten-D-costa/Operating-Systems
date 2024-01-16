#!/bin/bash
#Problem Statement: Append Contents to a file
#Valerian Coelho

echo -n "Enter the file name : "
read file

if [ -f "$file" ]; then  
    echo -n "$file exist "
    if [ -w "$file" ];then
        echo " and has write permissions"
        
        echo "Enter Contents to add to the file :-"
        read contents
        echo $contents >> $file
        
        echo $file " Contents :-"
        cat $file
    else
        echo " but does not have write permissions"
    fi
else
    echo "File Doesn't Exist"
fi  
