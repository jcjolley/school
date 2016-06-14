#!/bin/bash

BUBBLE_TABLE="Bubble Sort: |"
SELECT_TABLE="Select Sort: |"

#Run it more times on the smaller inputs to get a better average
POW=$(bc <<< "$1 - 1")
RUNS=$(bc <<< "10^$POW")

for i in `seq 1 $1`;
do
    #Input ranges from 10 - 1,000,000 
    N=$(bc <<< "10^$i")

    #Time the bubble run and add the results to the bubble table
    TEMP=$(/usr/bin/time ./bubble $N $RUNS 2>&1) 
    TIME=$(echo "$TEMP" | awk -v RS="" {'print $2'})
    CRIT_OPS=$(echo "$TEMP" | awk -v RS="" {'print $1'})
    BUBBLE_TABLE="$BUBBLE_TABLE OPS:$CRIT_OPS TIME:$TIME RUNS:$RUNS | "

    #Time the select run and add the results to the select table
    TEMP=$(/usr/bin/time ./selection $N $RUNS 2>&1)
    TIME=$(echo "$TEMP" | awk -v RS="" {'print $2'})
    CRIT_OPS=$(echo "$TEMP" | awk -v RS="" {'print $1'})
    SELECT_TABLE="$SELECT_TABLE OPS:$CRIT_OPS TIME:$TIME RUNS:$RUNS | "

    #This prevents us from running less than once for the big ones.
    if [ $RUNS -gt 1 ]
    then
	RUNS=$(bc <<< "$RUNS/10")
    fi
done 

printf "%s\n%s" "$BUBBLE_TABLE" "$SELECT_TABLE"
