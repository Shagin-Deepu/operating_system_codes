echo "enter n"
read n
s=0
temp=$n 
while [ $n -gt 0 ]
do 
s=$((n % 10))
n=$((n / 10))
rev="${rev}${s}"
done
echo "$rev" 
if [ "$temp" -eq " $rev" ]
then 
echo "palindrome"
else 
echo "not palindrome"
fi

