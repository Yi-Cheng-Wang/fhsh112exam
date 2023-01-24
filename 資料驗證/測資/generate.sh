#!/bin/bash
num=0
top=20
data[0]="1 99 1"
data[1]="1 100 0"
data[2]="99 99 0"
data[3]="100 99 1"
data[4]="100 100 0"
data[5]="100 9999 1"
data[6]="999 9999 0"
data[7]="1000 9999 1"
data[8]="1000 10000 1"
data[9]="1000 10000 0"
data[10]="1880 10000 1"
data[11]="4500 10000 0"
data[12]="4500 10000 0"
data[13]="5000 10000 1"
data[14]="5000 10000 1"
data[15]="5000 10000 1"
data[16]="5000 10000 0"
data[17]="5000 10000 0"
data[18]="5000 10000 1"
data[19]="5000 10000 1"
while [[ $num -lt $top ]]
do
	printf "%.2d" $num > filename.txt
	read filename < filename.txt
	echo "${data[$num]}" | python3 testcase.py > $filename.in
	cat $filename.in | ./a.out > $filename.out
	num=$(($num + 1))
done
