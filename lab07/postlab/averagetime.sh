#!/bin/bash
read e
quit="quit"
if [ $quit == $e ]
    then
    exit
fi
#Compile program
clang++ -O0 counter.cpp
loop=0
sum=0
#run program 5 times
while [ $loop -lt 5 ]
do
run_time=`./a.out $e | tail -1`
#run time printed
echo $run_time
sum=$((sum+run_time))
loop=$[$loop+1]
done
#prints sum
echo $sum
#print average time
echo $((sum/5))