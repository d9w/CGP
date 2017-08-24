#!/bin/sh

HOME=/users/p16043/wilson/CGP
DATA=/tmpdir/$LOGNAME/data/CGP
PARAMS=$HOME/cgp.par

WORK_DIR=/tmpdir/$LOGNAME/dennis/$SLURM_JOB_ID/$SLURM_TASK_PID
mkdir -p $WORK_DIR

cd $WORK_DIR
cp $PARAMS $WORK_DIR
sed -i "s/.*global_seed/$SLURM_TASK_PID global_seed/" cgp.par

for file in $DATA/*
do
    EXPER=$(echo $file | rev | cut -d '/' -f 1 | rev | cut -d '.' -f 1)
    mkdir $WORK_DIR/$EXPER
    cp $HOME/bin/cgp $WORK_DIR/$EXPER/cgp
done

for file in $DATA/*
do
    EXPER=$(echo $file | rev | cut -d '/' -f 1 | rev | cut -d '.' -f 1)
    cd $WORK_DIR/$EXPER
    ./cgp $WORK_DIR/cgp.par $file
done
