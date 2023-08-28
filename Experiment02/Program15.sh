# PROGRAM 15 : Append content to a file provided file name exists and it has write permission....
# Programmer : Haysten D'costa

#!/bin/bash 
# The 'shebang' specifies that this script should be interpreted by the Bash shell....

echo -n "Enter the file name : "
read file

if [ -f "$file" ] # check if the file specified by the user exists in the 'current directory'....
then
    echo -ne "\n$file exist " # print a message indicating that the specified file exists....
    
    if [ -w "$file" ] # check if the specified file has write permission....
    then
        echo -e "and has write permissions\n"
        
        echo -e "Enter Contents to add to file : "        
        read contents
        echo $contents >> $file # Append the contents to the file using 'echo'....
        
        echo -e "\nContents added : "
        cat $file # Display the contents of the file using 'cat'....
    else
        echo -e " but does not have write permissions\n"
    fi
else
    echo "File Doesn't Exist"
fi