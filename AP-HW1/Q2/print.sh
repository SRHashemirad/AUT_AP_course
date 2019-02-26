#!/bin/sh
filename="dict.txt"
while read -r line; do
echo "$line"
done < "$filename"
