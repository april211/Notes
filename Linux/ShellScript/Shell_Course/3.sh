#!/bin/bash 

dir="/home/april211/Shell_Course/*"

for path in $dir; do
    if [ -e "$path" ]; then
        size_name=$(du -ks "$path")          # KB
        size=$(echo "$size_name" | cut -f 1)
        if [ $size -ge 100 ]; then
            echo "$path"
        fi
    fi
done

