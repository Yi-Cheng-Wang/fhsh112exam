#!/bin/bash
num=0
top=20
data[0]="1 2 1"
data[1]=""
data[2]=""
data[3]=""
data[4]=""
data[5]=""
data[6]=""
data[7]=""
data[8]=""
data[9]=""
data[10]=""
data[11]=""
data[12]=""
data[13]=""
data[14]=""
data[15]=""
data[16]=""
data[17]=""
data[18]=""
data[19]=""
while [[ $num -lt $top ]]
do
	printf "%.2d" $num > filename.txt
	read filename < filename.txt
	echo "${data[$num]}" | python3 testcase.py > $filename.in
	cat $filename.in | ./a.out > $filename.out
	num=$(($num + 1))
done
