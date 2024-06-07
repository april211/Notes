#!/bin/bash 

a=120
b=55
c=1600
d=80

res=$(bc << EOF
scale = 9
var1 = $a + $d
var2 = var1 / $b
sqrt($c) * var2 + 1
EOF
)

echo "The result is: $res."

