#!/bin/bash 

for path in /home/april211/Shell_Course/*; do
    if [ -e "$path" ]; then
        size_name=$(du -ks $path)                           # KB
        size=$(echo "$size_name" | cut -f 1)
        if [ $size -ge 100 ]; then
            echo "$path"
        fi
    fi
done

