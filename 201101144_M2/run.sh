#!/bin/bash
for file in `ls 201101144_split_files`
do
  /home/jayesh/Documents/201101144_M2/searcher "201101144_split_files/$file" 
done

  /home/jayesh/Documents/201101144_M2/merger "./201101144_indexes/"  $2
   
