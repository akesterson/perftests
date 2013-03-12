#!/bin/bash

source stringlist.sh

start=$(date +%s%N | cut -b1-13)
stringlist=( $(echo ${stringlist[*]}) )
end=$(date +%s%N | cut -b1-13)
echo "Over ${#stringlist[@]} elements : $(expr $end - $start) milliseconds"