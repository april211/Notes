#!/bin/bash 
# 按照日期创建指定目录的日志

ymd=$(date +%y%m%d) 
flist=$(ls /usr/bin -1lh)
echo "$flist" > log.$ymd            # 加双引号保留换行

fname="zip"
cat log.$ymd | grep $fname

lc=$(echo "$flist" | grep "$fname" | wc -l)

echo -ne "Number of files have $fname in their names: $lc.\n"
exit 0

