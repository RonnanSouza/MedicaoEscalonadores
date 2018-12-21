#!/bin/bash

for d in `find output_2/OTHER/ -type d`
do
    echo $f
    allsamples="output_2/`basename $d`.data.plot"
    echo "Tempo_Total,Tempo_Inicial_Final,Total_Processos,Numero_Processo,Id_Processo,Algoritmo" > $allsamples
    cat $d/*out | cut -d" " -f 1,2,3,4,5,6 | sed 's/ /\,/g' >> $allsamples
    Rscript plot_2.r $allsamples
done

for d in `find output_2/BATCH/ -type d`
do
    echo $f
    allsamples="output_2/`basename $d`.data.plot"
    echo "Tempo_Total,Tempo_Inicial_Final,Total_Processos,Numero_Processo,Id_Processo,Algoritmo" > $allsamples
    cat $d/*out | cut -d" " -f 1,2,3,4,5,6 | sed 's/ /\,/g' >> $allsamples
    Rscript plot_2.r $allsamples
done

for d in `find output_2/FIFO/ -type d`
do
    echo $f
    allsamples="output_2/`basename $d`.data.plot"
    echo "Tempo_Total,Tempo_Inicial_Final,Total_Processos,Numero_Processo,Id_Processo,Algoritmo" > $allsamples
    cat $d/*out | cut -d" " -f 1,2,3,4,5,6 | sed 's/ /\,/g' >> $allsamples
    Rscript plot_2.r $allsamples
done
