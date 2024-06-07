#!/bin/bash 

for (( i = 1; i <= 6; i++)); do
    echo "Outer loop: i == $i."
    for (( j = 1; j <= 6; j++)); do
        echo "Inner loop: j == $j."
        if (( j == 3 )); then
            echo ""                 # print a blank line
            break 2
        fi
    done
done >> output.iter

