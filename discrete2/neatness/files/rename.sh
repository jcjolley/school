for i in `seq 1 255`;
do
  if [ -f neatness$i.out ]; then
    mv neatness$i.out out$i.txt
  fi
done