#!/bin/bash
chapter=5
SHARED="./Chapter${1}/readlines.c ./Shared/getch.c"
echo "including: ${SHARED}"
cc ./Chapter${1}/${1}-${2}.c ${SHARED} -o ./bin/${1}-${2}.out