#!/bin/bash
for i in `seq 1 255`;
do
  for j in `seq 1 255`;
  do
    if [[ "$i" != "$j" ]]; then
      if [ -f neatness$i.out ]; then
        if [ -f neatness$j.out ]; then
          if diff -q neatness$i.out neatness$j.out >/dev/null; then
            echo "neatness$i.out and neatness$j.out are the same."
            rm neatness$j.out
          fi
        fi
      fi
    fi
  done
done