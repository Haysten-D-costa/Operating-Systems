# PROGRAM 15 : Append content to a file provided file name exists and it has write permission....
# Programmer : Haysten D'costa

#!/bin/bash
# The shebang specifies that this script should be interpreted by the Bash shell.

echo -n "Enter the file name : " # Display a prompt to the user without a newline, asking them to enter a file name.
read file # Read the user's input and store it in the 'file' variable.

if [ -f "$file" ] # Check if the file specified by the user exists in the current directory.
then
    echo
    echo -n "$file exist " # Print a message indicating that the specified file exists.
    
    if [ -w "$file" ] # Check if the specified file has write permission.
    then
        echo "and has write permissions" # Print a message indicating that the file has write permissions.
        
        echo # Print an empty line for formatting.
        echo "Enter Contents to add to file : " # Prompt the user to enter the contents to be added to the file.
        read contents # Read the entered contents and store them in the 'contents' variable.
        echo $contents >> $file # Append the contents to the file using 'echo'.
        
        echo # Print an empty line for formatting.
        echo "Contents added : " # Print a message indicating that the contents have been added.
        cat $file # Display the contents of the file using 'cat'.
    else
        echo " but does not have write permissions" # Print a message indicating that the file does not have write permissions.
    fi
else
    echo "File Doesn't Exist" # Print a message indicating that the specified file doesn't exist.
fi
