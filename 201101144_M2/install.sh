#!/bin/bash
g++ -w -O3 create_parital_index.cpp porter.c -o searcher 
g++ -w -O3 merge_all_index.cpp -o merger

rm -rf 201101144_split_files
mkdir -p 201101144_split_files
cd 201101144_split_files
split -b 100M --suffix-length=4 $1
cd ..

python quantizing.py "201101144_split_files/"

rm -rf 201101144_indexes
mkdir -p 201101144_indexes
