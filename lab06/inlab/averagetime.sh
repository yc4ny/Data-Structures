#!/bin/bash
# Ask the user to enter dictionary file name
read dict
# Ask the user for grid file
read grid
# Compile using make 
make
# Run program 5 times and calculate and print out average time
run_time=`./a.out $dict $grid | tail -1`
sum=$run_time
run_time=`./a.out $dict $grid | tail -1`
sum=$((sum+run_time))
run_time=`./a.out $dict $grid | tail -1`
sum=$((sum+run_time))
run_time=`./a.out $dict $grid | tail -1`
sum=$((sum+run_time))
run_time=`./a.out $dict $grid | tail -1`
sum=$((sum+run_time))
echo $((sum/5))