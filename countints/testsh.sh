#!/bin/bash

source intlist.sh

declare -A intcounts

start=$(date +%s%N | cut -b1-13)
for i in $(seq 1 ${#intlist[@]})
do
    if [[ ${intcounts[$i]} ]]; then
	intcounts[$i] = $((intcounts[$i] + 1 ))
    else
	intcounts[$i]=1
    fi
done
end=$(date +%s%N | cut -b1-13)
echo "Over ${#intlist[@]} elements : $(expr $end - $start) milliseconds"