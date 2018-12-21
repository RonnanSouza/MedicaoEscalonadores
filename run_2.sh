#/bin/bash

rm output_2/* 2>/dev/null
mkdir output_2/ 2>/dev/null
gcc main_2.c -o main_2 2>/dev/null
echo "Inform the number of processes:"
read number
number=$(echo "$number" | tr -d "[\001-\004]" )
echo "Running tests..."
for sched in OTHER BATCH FIFO
do
	./main_2 $sched $number >> output_2/results.$sched.$number.out
done
echo "Done!"


for sched in OTHER BATCH FIFO
do
	./main $sched >> output/results.$sched.out
done

	for i in 1 2 
	do
		./main $sched >> output/results.$sched.$i.out
	done
echo "Done!"
