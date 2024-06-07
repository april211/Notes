#!/bin/bash 

pwfile=$1

if [ -f $pwfile ] ; then                # 检查 pwfile 是否存在并是一个文件
    if [ -r $pwfile ] ; then            # 检查 pwfile 是否存在并可读
        more $pwfile 
    else 
        echo "用户没有对文件 $pwfile 的读权限！" 
    fi 
else 
    echo "文件 $pwfile 不存在！" 
fi

