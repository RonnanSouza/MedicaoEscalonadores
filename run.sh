#/bin/bash

rm output/* 2>/dev/null
mkdir output/ 2>/dev/null
gcc main.c -o main 2>/dev/null
echo "Running tests..."
for sched in OTHER BATCH FIFO
do
	./main $sched >> output/results.$sched.out
done
echo "Done!"
