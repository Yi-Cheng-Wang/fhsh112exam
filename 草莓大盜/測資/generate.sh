#!/bin/bash
num=0
top=20
while [[ $num -lt $top ]]
do
	printf "%.2d" $num > filename.txt
	read filename < filename.txt
	echo "$num" | python3 testcase.py > $filename.in
	cat $filename.in | ./a.out > $filename.out
	num=$(($num + 1))
done
