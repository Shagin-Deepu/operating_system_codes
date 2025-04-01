echo "enter no"
read a
i=2
flag=0
while [ $i -le $(expr $a / 2) ]
do
	if [ $(expr $a % $i) -eq 0 ]
	then
		flag=1
		break
	fi
	i=`expr $i +1`
done
if [ $flag -eq 1 ]
then
	echo "the number is not prime"
else
	echo "the number is prime"
fi
