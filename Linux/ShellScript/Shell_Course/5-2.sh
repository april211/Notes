#!/bin/bash 

a=120
b=55

res=$( echo "scale=6; $a / $b"  | bc )

echo "The result of \`$a / $b\` is: $res."

