#!/bin/bash
if [ ! -d "bin" ]; then
mkdir bin
fi
#cc -g -O -c ./Shared/*.c -o ./bin/Shared.o
chapter=$1
lesson=$2
if [ -z "$lesson" ]
then
    search=".c"
    replace=""
    chapter="${1//$search/$replace}"
    IFS='-'
    read -ra splitted <<< "$chapter"
    chapter="${splitted[0]}"
    lesson="${splitted[1]}"
fi
cc ./Chapter${chapter}/${chapter}-${lesson}.c ./Shared/*.c -o ./bin/${chapter}-${lesson}.out
./bin/${chapter}-${lesson}.out
#make chapter=$1 exercise=$2