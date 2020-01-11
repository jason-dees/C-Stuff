#!/bin/bash
chapter=6
SHARED="./Shared/getch.c"
echo "including: ${SHARED}"
echo "building ./Chapter${1}/${1}-${2}.c to ./bin/${1}-${2}.out"
cc ./Chapter${1}/${1}-${2}.c ${SHARED} -o ./bin/${1}-${2}.out