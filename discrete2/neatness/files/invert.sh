for i in `seq 1 255`;
do
  if [ -f neatness$i.out ]; then
    ../invert neatness$i.out
  fi
done