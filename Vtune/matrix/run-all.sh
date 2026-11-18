#!/bin/bash

source /home/apps/spack/share/spack/setup-env.sh

spack load intel-oneapi-vtune@2024.1.0
spack load intel-oneapi-advisor@2024.1.0

ulimit -n 65535

#1: Base Run

gcc -O0 -g 1.mm-base.c -o mm-base

(time vtune -collect hotspots -result-dir vtune1-mm-base ./mm-base) 2>&1 | tee -a out1.base

#: Compiler Optimization

gcc -O2 -g 1.mm-base.c -o mm-base-opt

(time vtune -collect hotspots -result-dir vtune1-mm-opt ./mm-base-opt) 2>&1 | tee -a out1.compiler-opt

#2: OpenMP Parallelization

gcc -O2 -g -fopenmp 2.mm-openmp.c -o mm-openmp

export OMP_NUM_THREADS=4
export OMP_PROC_BIND=true
export OMP_PLACES=cores

(time vtune -collect hotspots -knob sampling-mode=hw -result-dir vtune2-mm-openmp ./mm-openmp) 2>&1 | tee -a out2.omp

#3: Cache Optimized Version (Loop Blocking)

(time vtune -collect memory-access -result-dir vtune3-mm-openmp-mem-Old ./mm-openmp) 2>&1 | tee -a out3.omp-mem

gcc -O2 -g -fopenmp 3.mm-openmp-cacheOpt.c -o mm-openmp-mem

(time vtune -collect memory-access -result-dir vtune3-mm-openmp-mem-Opt ./mm-openmp-mem) 2>&1 | tee -a out3.omp-mem-opt

#4: Vector Version

gcc -O3 -g -march=native -fopenmp 4.mm-openmp-cache-vector.c -o mm-openmp-mem-vect

(time vtune -collect uarch-exploration -result-dir vtune4-vector-opt ./mm-openmp-mem-vect) 2>&1  | tee -a out4.vector-opt




