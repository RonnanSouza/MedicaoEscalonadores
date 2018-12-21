#!/bin/bash

for d in `find output_SAMPLE/ -type d`
do
    echo $f
    allsamples="output_SAMPLE/`basename $d`.SAMPLE.plot"
    echo "Tempo,Replicação,Algoritmo" > $allsamples
    cat $d/*out | cut -d" " -f 1,2,3 | sed 's/ /\,/g' >> $allsamples
    Rscript plot_SAMPLE.r $allsamples
done
