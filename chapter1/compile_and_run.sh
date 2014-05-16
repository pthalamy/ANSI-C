#!/bin/sh

# Compile
for i in `seq 1 $2`; do
    if [ $i != 11 ]; then
	g++ exercise_$1-$i.c -o exercise_$1-$i.exe
	# Make executable
	if [ -c exercise_$1-$i.exe ]; then
	    chmod +x exercise_$1-$i.exe
	fi
    fi
done
