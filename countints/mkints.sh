#!/bin/bash

declare -A STATES

function writecpp()
{
    idx=0
    echo "int intlist[] = {" > intlist.h
    for int in ${ints[*]}
    do
	if [ $idx -ne 0 ]; then
	    echo "," >> intlist.h
	fi
	echo -n "        $int" >> intlist.h
	idx=$((idx + 1))
    done
    echo "};" >> intlist.h
    echo "#define INTLISTSIZE $idx" >> intlist.h
    return 0
}

function writepython()
{
    idx=0
    echo "intlist = [" > intlist.py
    for int in ${ints[*]}
    do
	if [ $idx -ne 0 ]; then
	    echo "," >> intlist.py
	fi
	echo -n "        $int" >> intlist.py
	idx=$((idx + 1))
    done
    echo "]" >> intlist.py
    return 0
}

function writejs()
{
    idx=0
    echo "var intlist = [" > intlist.js
    for int in ${ints[*]}
    do
	if [ $idx -ne 0 ]; then
	    echo "," >> intlist.js
	fi
	echo -n "        $int" >> intlist.js
	idx=$((idx + 1))
    done
    echo "];" >> intlist.js
    echo "module.exports.intlist = intlist;" >> intlist.js
    return 0
}

function writebash()
{
    idx=0
    echo "declare -a intlist" > intlist.sh
    for int in ${ints[*]}
    do
	echo "intlist[$idx]=$int" >> intlist.sh
	idx=$((idx + 1))
    done
    return 0
}

declare -a ints
size=${1:-1000}
intsize=${2:-2}

for i in $(seq 1 $size)
do
    curint=""
    for j in $(seq 1 $intsize)
    do
	rstr=$(echo $RANDOM)
	curint="${curint}${rstr:0:1}"
    done
    ints[$i]="$curint"
done

writecpp
writepython
writebash
writejs