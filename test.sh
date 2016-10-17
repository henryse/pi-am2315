#!/usr/bin/env bash

make clean
make

for i in {1..1000}
do
    echo ${i}
    ./pi-am2315
done