#!/bin/bash

rm output_2/* 2>/dev/null
rm output_2/OTHER/* 2>/dev/null
rm output_2/BATCH/* 2>/dev/null
rm output_2/FIFO/* 2>/dev/null
mkdir output_2/OTHER 2>/dev/null
mkdir output_2/BATCH 2>/dev/null
mkdir output_2/FIFO 2>/dev/null
gcc main_2.c -o main_2 2>/dev/null
echo "Inform the number of processes:"
read number
number=$(echo "$number" | tr -d "[\001-\004]" )
echo "Running tests..."
for sched in OTHER BATCH FIFO
do
	./main_2 $sched $number >> output_2/results.$sched.$number.out
	cont=0
	while [ $cont -lt $number ]
	do
		line_1=$(head -n 1 output_2/results.$sched.$number.out)
		echo $line_1 >> output_2/$sched/results.$sched.$cont.out
		sed -i 1d output_2/results.$sched.$number.out
		line_1=$(head -n 1 output_2/results.$sched.$number.out)
		echo $line_1 >> output_2/$sched/results.$sched.$cont.out
		sed -i 1d output_2/results.$sched.$number.out

		(( cont++ ))
	done

done
echo "Done!"
