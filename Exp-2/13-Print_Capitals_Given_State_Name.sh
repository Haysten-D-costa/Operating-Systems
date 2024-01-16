#!/bin/bash
#Problem Statement: print capital give state name using switch case
#Name: Valerian Coelho

echo -n "Enter the state name : "
read state

case $state in
    "Goa")
        echo "Capital: Panjim"
        ;;
    "Maharashtra")
        echo "Capital: Mumbai"
        ;;
    "Karnataka")
        echo "Capital: Bangalore"
        ;;
    "Tamil Nadu")
        echo "Capital: Chennai"
        ;;
    "Uttar Pradesh")
        echo "Capital: Lucknow"
        ;;
    "Rajasthan")
        echo "Capital: Jaipur"
        ;;
    *)
        echo "Invalid Input"
        ;;
esac
