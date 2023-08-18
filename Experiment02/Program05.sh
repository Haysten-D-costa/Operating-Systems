# PROGRAM 05 : To display square of first 20 numbers....
# Programmer : Haysten D'costa
#!/bin/bash

limit=20
echo "Displaying squares of first "$limit" numbers : "
for(( i=0; i<=limit; i++ ))
do
	echo "Square("$i") : " `expr $i \* $i`
done