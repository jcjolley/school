#!/bin/bash
for i in `seq 1 255`;
do
  neatness $i > neatness$i.out
done