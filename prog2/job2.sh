#!/bin/bash

#PBS -l walltime=00:01:00,nodes=5:ppn=2
#PBS -N t2
#PBS -q batch
cd $PBS_P_WORKDIR
mpirun --hostfile $PBS_NODEFILE -np 10 ./summ
