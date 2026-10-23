#!/bin/bash

for s in "$@"
do
    rev=$(echo "$s" | rev)

    if [ "$s" = "$rev" ]; then
        echo "$s - палиндром"
    else
        echo "$s - не палиндром"
    fi
done
