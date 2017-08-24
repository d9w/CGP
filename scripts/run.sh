#!/bin/sh

HOME=/users/p16043/wilson/cgp
DATA=/tmpdir/$LOGNAME/dennis/data/cgp
PARAMS=$HOME/cgp.par

WORK_DIR=/tmpdir/$LOGNAME/dennis/$SLURM_JOB_ID/$SLURM_TASK_PID
mkdir -p $WORK_DIR

cd $WORK_DIR
cp $PARAMS $WORK_DIR
sed -i "s/global_seed/$SLURM_TASK_PID global_seed/" cgp.par

for file in $DATA/*
do
    cd $WORK_DIR
    EXPER=$(echo $file | rev | cut -d '/' -f 1 | rev | cut -d '.' -f 1)
    mkdir $EXPER
    cp $HOME/bin/cgp $EXPER
done

for file in $DATA/*
do
    EXPER=$(echo $file | rev | cut -d '/' -f 1 | rev | cut -d '.' -f 1)
    cd $WORK_DIR/$expr
    ./cgp $WORK_DIR/cgp.par $file
done
