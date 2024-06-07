#!/bin/bash 

# ./getopt.sh -v -w test1 -xz test2 test3 test4

echo "$@"

getopt -q vw:xz "$@"

echo "$@"

set -- $(getopt -q vw:xz "$@")    # 使用 set 改变命令行参数的值
echo "$@"

while [ -n "$1" ]; do
    case "$1" in
    -v) echo "Found the -v option";;
    -w) param="$2"
        echo "Found the -w option, with parameter value $param"
        shift;;                   # 参数列表左移，丢弃该参数
    -x) echo "Found the -x option";;
    --) shift 
        break;;                   # -- 后面是固定的参数，而不是选项
     *) echo "$1 is not an option";;
     esac
    shift
done

count=1
for param in "$@"; do 
    echo "Parameter #$count: $param"
    count=$[ $count + 1 ]
done

