#!/bin/bash

if [ $# -eq 0 ]
    then
        echo "Need argument"
        exit 1
fi

if [ -f "src/day$1.cpp" ]
    then
        echo "File already exists"
        exit 2
fi

cp template/day0.cpp src/day$1.cpp
cp template/day0.h src/day$1.h

sed -i -e "s/0/$1/g" src/day$1.cpp
sed -i -e "s/0/$1/g" src/day$1.h