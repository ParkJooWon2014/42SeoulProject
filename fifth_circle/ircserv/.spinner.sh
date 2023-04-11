#! /bin/sh

i=1
j=0
max=5000
sp="/-\|"
echo -n "$1 is Ready "
echo -n ' '
while [ $j -lt $max ]
do
    printf "\b${sp:i++%${#sp}:1}"
    j=$(($j+1))
done
printf "\b✅\n"
