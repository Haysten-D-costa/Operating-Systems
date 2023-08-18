# (User Defined) Reading user inputs....

echo "Enter first number : " # prompt user to enter a number...
read a # 'read' to read a number from user...
echo "Enter second number : " 
read b

echo Sum : $a+$b = `expr $a + $b`
echo Difference : $a-$b = `expr $a - $b`
echo Product : $a*$b = `expr $a \* $b`
echo Quotient : $a/$b = `expr $a / $b`
echo Remainder : $a%$b = `expr $a % $b`
