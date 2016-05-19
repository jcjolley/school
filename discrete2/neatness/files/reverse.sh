for i in `seq 1 255`;
do
  if [ -f neatness$i.out ]; then
    ../reverse neatness$i.out
  fi
done