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
includeshared=true
case "${chapter}-${lesson}" in
    "4-8")
        includeshared=false
        ;;
    "4-10")
        includeshared=false
        ;;
esac
if [ "$includeshared" = true ] ;
then
    cc ./Chapter${chapter}/${chapter}-${lesson}.c ./Shared/*.c -o ./bin/${chapter}-${lesson}.out
else
    cc ./Chapter${chapter}/${chapter}-${lesson}.c -o ./bin/${chapter}-${lesson}.out
fi
./bin/${chapter}-${lesson}.out
#make chapter=$1 exercise=$2