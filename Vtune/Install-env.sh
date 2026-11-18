#!/bin/bash

#Python Env
pip install gprof2dot
pip3 install numpy matplotlib

#Spack Env
git clone https://github.com/spack/spack.git

source spack/share/spack/setup-env.sh

spack install intel-oneapi-compilers@2021.2.0
spack install intel-oneapi-mpi@2021.2.0
spack install intel-oneapi-vtune@2022.0.0
spack install intel-oneapi-advisor@2022.0.0
