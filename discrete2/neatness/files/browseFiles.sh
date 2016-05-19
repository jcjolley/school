#!/bin/bash
for i in `seq 1 255`;
do
  if [ -f neatness$i.out ]; then
    clear
    cat neatness$i.out
    echo "$i"
    sleep 2
  fi
done