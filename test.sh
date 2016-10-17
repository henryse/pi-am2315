#!/usr/bin/env bash

make clean
make

for i in `seq 1 100`;
do
    echo Attempt: ${i}

    ./pi-am2315

    rc=$?

    echo Result: ${rc}

    if [[ ${rc} != 0 ]];
    then
        exit ${rc};
    fi
done