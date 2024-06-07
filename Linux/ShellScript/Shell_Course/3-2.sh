#!/bin/bash 

for (( a=1, b=8; a <= 8; a++, b-- )); do
    if (( a == 4)) || ((a == 5)); then
        continue
    fi
    echo "$a - $b = $[ $a - $b ]"
done

IFS=$'\n'