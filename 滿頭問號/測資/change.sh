#!/bin/bash

echo "start!"
num=0
top=100
while [[ $num -lt $top ]]
do
	printf "%.2d" $num > filename.txt
        read filename < filename.txt
	echo $filename.out
        cat $filename.out | python3 change.py > $filename.out
        num=$(($num + 1))
done

