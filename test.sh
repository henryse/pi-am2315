#!/usr/bin/env bash

make clean
make

for i in {1..1000}
do
    ./pi-am2315
done