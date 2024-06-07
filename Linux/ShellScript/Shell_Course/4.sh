#!/bin/bash 

iter=1

while IFS='' read -r line
        [ $iter -le 5 ]; do
    echo "$iter: $line"
    iter=$[ $iter + 1 ]
done < log.231116

iter=1

while IFS='' read -r line; do
    echo "$iter: $line"
    iter=$[ $iter + 1 ]
    if [ $iter -gt 5 ]; then
        break
    fi
done < log.231116
