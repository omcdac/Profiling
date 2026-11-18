#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include "nbody.h"
#include "io.h"

#define N 6000
#define STEPS 1000
#define OUTPUT_FREQ 50

int main()
{
    Body *bodies = malloc(sizeof(Body)*N);

    initialize_bodies(bodies,N);

    double start = omp_get_wtime();

    for(int step=0;step<STEPS;step++)
    {
        compute_forces(bodies,N,0.01);
        update_positions(bodies,N,0.01);

        if(step % OUTPUT_FREQ == 0)
            save_positions(bodies,N,step);
    }

    double end = omp_get_wtime();

    printf("Simulation time: %f seconds\n", end-start);

    free(bodies);

    return 0;
}
