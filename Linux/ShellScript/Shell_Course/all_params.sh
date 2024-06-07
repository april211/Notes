#!/bin/bash 

# ./all_params.sh 1 2 3 4 5 6 a s d f g h

echo "The command line of this execution: $0"
echo "The basename of this script: $(basename $0)"
echo "# of params: $#."
echo "The 1st param: $1"
echo "The 11th param: ${11}"
echo "The last param: ${!#}"

count=1

for param in "$*"; do
    echo "\$* Parameter #$count = $param"
    count=$[ $count + 1 ]
done

echo

count=1

for param in "$@"; do
    echo "\$@ Parameter #$count = $param"
    count=$[ $count + 1 ]
done

