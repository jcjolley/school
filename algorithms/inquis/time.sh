#!/bin/bash

BUBBLE_TABLE="Bubble Sort: |"
SELECT_TABLE="Select Sort: |"
for i in `seq 1 3`;
do
		  N=$(bc <<< 10^$i)
		  RUNS=1000		  
		  
		  #TEMP=$(/usr/bin/time ./bubble $N $RUNS 2>&1) 
		  TEMP=$(sh -c "/usr/bin/time ./bubble $N $RUNS" 2>&1) 
		  TIME=$(echo "$TEMP" | awk -v RS="" {'print $2'})
		  CRIT_OPS=$(echo "$TEMP" | awk -v RS="" {'print $1'})
		  BUBBLE_TABLE="$BUBBLE_TABLE OPS:$CRIT_OPS TIME:$TIME | "
		  
		  TEMP=$(/usr/bin/time ./selection $N $RUNS 2>&1)
		  TIME=$(echo "$TEMP" | awk -v RS="" {'print $2'})
		  CRIT_OPS=$(echo "$TEMP" | awk -v RS="" {'print $1'})
		  SELECT_TABLE="$SELECT_TABLE OPS:$CRIT_OPS TIME:$TIME | "
		 
		  RUNS=$(bc <<< $RUNS/1.5)
done 

printf "%s\n%s" "$BUBBLE_TABLE" "$SELECT_TABLE"
