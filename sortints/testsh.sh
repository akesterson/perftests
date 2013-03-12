#!/bin/bash

source intlist.sh

start=$(date +%s%N | cut -b1-13)
intlist=( $(echo ${intlist[*]} | sort -n) )
end=$(date +%s%N | cut -b1-13)
echo "Over ${#intlist[@]} elements : $(expr $end - $start) milliseconds"