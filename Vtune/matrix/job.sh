#!/bin/bash

#SBATCH --job-name=profiling
#SBATCH --output=job.out
#SBATCH --error=job.err
#SBATCH --partition=cpu
#SBATCH --nodes=1
#SBATCH --ntasks-per-node=10
#SBATCH --time=01:00:00

# Working Dir and Environment Setup
cd $SLURM_SUBMIT_DIR

source /home/apps/spack/share/spack/setup-env.sh
spack load intel-oneapi-vtune@2024.1.0
spack load intel-oneapi-advisor@2024.1.0

# Set OpenMP threads
export OMP_NUM_THREADS=4
export OMP_PROC_BIND=true
export OMP_PLACES=cores


# Run the application
(time vtune -collect memory-access -result-dir vtune3-mm-openmp-mem-Old ./mm-openmp) 2>&1 | tee -a out3.omp-mem
