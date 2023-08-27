# PROGRAM 13 : Using switch case, print the capitals given the state name....
# Programmer : Haysten D'costa
#!/bin/bash

echo -n "Enter a state : "
read state

case "$state" in
    "Goa") 
        echo "Panaji"
        ;;
    "Uttar Pradesh") 
        echo "Lucknow"
        ;;
    "Haryana") 
        echo "Chandigarh"
        ;;
    "Andhra Pradesh") 
        echo "Amaravati"
        ;;
    "Rajasthan") 
        echo "Jaipur"
        ;;
    "Tamil Nadu") 
        echo "Chennai"
        ;;
    *) 
        echo "State not valid !"
esac