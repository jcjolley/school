#!/bin/bash

function numberTest {
	for i in `seq 4000`;
	do
		echo $i
	done
	echo "quit"
}
TEST1="$(numberTest | RomanNumerals.out | grep "Input: invalid" | wc -l)"

if [ ${TEST1} -eq 4000 ]; then 
	echo "NumberTest: PASSED"
else
	echo "NumberTest: FAILED"
fi	



TEST2="$(grep -oP [IVXLCDMQUT]+ RomanNumerals.txt | perl -ne 'print lc' | RomanNumerals.out | grep "Input: valid" | wc -l)"

if [ ${TEST2} -eq 3999 ]; then 
	echo "Lowercase Test: PASSED"
else
	echo "Lowercase Test: FAILED"
fi

TEST3="$(grep -oP [IVXLCDMQUT]+ RomanNumerals.txt | perl -MList::Util=shuffle -F'' -lane 'print shuffle @F' | cut -d\ -f1-)"

echo ${TEST3}
