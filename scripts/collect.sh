#!/bin/sh

JOB_ID=$1 # script argument
HOME=/users/p16043/wilson/cgp
DATA=/tmpdir/$LOGNAME/dennis/data/cgp
WORK_DIR=/tmpdir/wilson/dennis/$JOB_ID
RESULTS_DIR=$HOME/results/$JOB_ID

mkdir -p $RESULTS_DIR

for file in $DATA/*
do
    i=0
    for proc in $WORK_DIR/*
    do
        EXPER=$(echo $file | rev | cut -d '/' -f 1 | rev | cut -d '.' -f 1)
        mkdir -p $RESULTS_DIR/$EXPER
        for prg in $proc/$EXPER/*prg
        do
            cp $prg $RESULTS_DIR/$EXPER/$i.log
            echo $i $EXPER
            let i=i+1
        done
    done
done
