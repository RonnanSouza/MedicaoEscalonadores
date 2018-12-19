#!/bin/bash

#simulation output format
#fault_counter num_pages num_frames alg clock

#plot input format
#nfaults,nframes,alg
#15000,6,opt


for d in `find output/ -type d`
do
    echo $f
    allsamples="output/`basename $d`.mem.plot"
    echo "Tempo,nForks,Algoritmo" > $allsamples
    cat $d/*out | cut -d" " -f 1,2,3 | sed 's/ /\,/g' >> $allsamples
    Rscript plot.r $allsamples
done
