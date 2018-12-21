#/bin/bash

rm output_1/* 2>/dev/null
mkdir output_1/ 2>/dev/null
gcc main_1.c -o main_1 2>/dev/null
echo "Inform the number of processes:"
read number
number=$(echo "$number" | tr -d "[\001-\004]" )
echo "Running tests..."
for sched in OTHER BATCH FIFO
do
	./main_1 $sched $number >> output_1/results.$sched.$number.out
done
echo "Finishing execution of tests, with successfully!!!"
echo "Data structuring..."
for d in `find output_1/ -type d`
do
    echo $f
    allsamples="output_1/`basename $d`.data.out"
    echo "Tempo_Total,Tempo_Inicial,Tempo_Final,Total_Processos,Numero_Processo,Id_Processo,Algoritmo" > $allsamples
    cat $d/*out | cut -d" " -f 1,2,3,4,5,6,7 | sed 's/ /\,/g' >> $allsamples
done
echo "Done!!!"
