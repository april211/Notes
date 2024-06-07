#!/bin/bash 

passwd_foo="123456"

# -t 10

read -p "Do you really want to login right now [Y/N] ? " answer

count=0
max_count=3

case $answer in 
Y | y) while [ $count -lt $max_count ]; do 
            read -p "Enter your password: " -s passwd_input
            if [ $passwd_input = $passwd_foo ]; then 
                 echo "Successfully login to the system!"
                 break
            else
                 count=$[ $count + 1 ]
                 echo "Wrong password! ($count/$max_count)"
            fi
       done;;
N | n) echo "You cancel the login.";;
    *) echo "Illegal input!";;
esac

