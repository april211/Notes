#!/bin/bash 

USER_foo="testing"

case $USER_foo in 
april211 | wilson)
    echo "Welcome, $USER_foo! Enjoy your visit!";;
testing)
    echo "This is a special account for testing.";;
*)
    echo "Sorry, you are not allowed here... ";;
esac

