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
        includeshared=falsed ;;
    "4-10")
        includeshared=falsed ;;
    "4-11")
        includeshared=falsed ;;
esac
FILE=./Chapter${chapter}/build.sh
if [ -f "$FILE" ] ;then
    echo "found $FILE"
    chmod +x ${FILE}
    ${FILE} ${chapter} ${lesson}
elif [ "$includeshared" = true ] ;
then
    cc ./Chapter${chapter}/${chapter}-${lesson}.c ./Shared/*.c -o ./bin/${chapter}-${lesson}.out
else
    cc ./Chapter${chapter}/${chapter}-${lesson}.c -o ./bin/${chapter}-${lesson}.out
fi
echo "running ./bin/${chapter}-${lesson}.out"
./bin/${chapter}-${lesson}.out
#make chapter=$1 exercise=$2