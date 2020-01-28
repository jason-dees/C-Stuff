#!/bin/bash
chapter=7
SHARED="./Shared/stack.c"
echo "including: ${SHARED}"
case "${1}-${2}" in
    "7-1")
        echo "building ./Chapter${1}/${1}-${2}.c to ./bin/${1}-${2}-upper.out"
        cc ./Chapter${1}/${1}-${2}.c ${SHARED} -o ./bin/${1}-${2}-upper.out
        echo "building ./Chapter${1}/${1}-${2}.c to ./bin/${1}-${2}-lower.out"
        cc ./Chapter${1}/${1}-${2}.c ${SHARED} -o ./bin/${1}-${2}-lower.out
        break;
esac
echo "building ./Chapter${1}/${1}-${2}.c to ./bin/${1}-${2}.out"
cc ./Chapter${1}/${1}-${2}.c ${SHARED} -o ./bin/${1}-${2}.out