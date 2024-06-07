#!/bin/bash 

function factorial {
    if [ -z "$1" ]; then
        return 3
    fi

    if (( $1 == 1 )); then 
        echo 1
    else
        local temp=$[ $1 - 1 ]
        local result=$(factorial $temp)
        echo $[ $1 * $result ]
    fi
}

# if (( $# != 1)); then
#     echo "Illegal input! Failed to calculate!"
#     exit 1
# fi

ans=$(factorial $1)
return_code=$?

if (( $return_code == 0 )); then
    echo "The factorial of $1 is: $ans."
else
    echo "Illegal input! Failed to calculate!"
    echo "Return code of factorial function: " $return_code
fi 

