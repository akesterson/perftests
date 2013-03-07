#!/bin/bash

source stringlist.sh

declare -A stringcounts

start=$(date +%s%N | cut -b1-13)
for i in $(seq 1 ${#stringlist[@]})
do
    if [[ ${stringcounts[$i]} ]]; then
	stringcounts[$i] = $((stringcounts[$i] + 1 ))
    else
	stringcounts[$i]=1
    fi
done
end=$(date +%s%N | cut -b1-13)
echo "Over ${#stringlist[@]} elements : $(expr $end - $start) milliseconds"