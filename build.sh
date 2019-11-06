#!/bin/bash
if [ ! -d "bin" ]; then
mkdir bin
fi
#cc -g -O -c ./Shared/*.c -o ./bin/Shared.o
cc 	./Chapter$1/$1-$2.c ./Shared/*.c -o ./bin/$1-$2.out
./bin/$1-$2.out
#make chapter=$1 exercise=$2