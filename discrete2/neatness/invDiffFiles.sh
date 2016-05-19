#!/bin/bash
for i in `seq 1 255`;
do
  for j in `seq 1 255`;
  do
    if [ -f neatness$j.out ]; then
      if [ -f reversedneatness$i.out ]; then
        if diff -q neatness$j.out invertedneatness$i.out >/dev/null; then
          echo "neatness$j and invertedneatness$i are the same"
        fi
      fi
    fi
  done
done