#/bin/bash

rm output/results.txt 2>/dev/null
mkdir output/ 2>/dev/null
gcc main.c -o main 2>/dev/null
echo "Running tests..."
for sched in OTHER FIFO BATCH 
do
	./main $sched >> output/results.txt
done
echo "Done!"
