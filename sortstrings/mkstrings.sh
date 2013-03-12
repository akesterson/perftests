#!/bin/bash

function writecpp()
{
    idx=0
    echo "const char *stringlist[] = {" > stringlist.h
    for string in ${strings[*]}
    do
	if [ $idx -ne 0 ]; then
	    echo "," >> stringlist.h
	fi
	echo -n "        \"$string\"" >> stringlist.h
	idx=$((idx + 1))
    done
    echo "};" >> stringlist.h
    echo "#define STRINGLISTSIZE $idx" >> stringlist.h
    return 0
}

function writepython()
{
    idx=0
    echo "stringlist = [" > stringlist.py
    for string in ${strings[*]}
    do
	if [ $idx -ne 0 ]; then
	    echo "," >> stringlist.py
	fi
	echo -n "        \"$string\"" >> stringlist.py
	idx=$((idx + 1))
    done
    echo "]" >> stringlist.py
    return 0
}

function writejs()
{
    idx=0
    echo "var stringlist = [" > stringlist.js
    for string in ${strings[*]}
    do
	if [ $idx -ne 0 ]; then
	    echo "," >> stringlist.js
	fi
	echo -n "        \"$string\"" >> stringlist.js
	idx=$((idx + 1))
    done
    echo "];" >> stringlist.js
    echo "module.exports.stringlist = stringlist;" >> stringlist.js
    return 0
}

function writebash()
{
    idx=0
    echo "declare -a stringlist" > stringlist.sh
    for string in ${strings[*]}
    do
	echo "stringlist[$idx]=\"$string\"" >> stringlist.sh
	idx=$((idx + 1))
    done
    return 0
}

declare -a strings
size=${1:-1000}
stringsize=${2:-2}

for i in $(seq 1 $size)
do
    curstring=""
    for j in $(seq 1 $stringsize)
    do
	rstr=$(echo $RANDOM)
	curstring="${curstring}${rstr:0:1}"
    done
    strings[$i]="$curstring"
done

writecpp
writepython
writebash
writejs