#include <stdio.h>
#include "io.h"

void save_positions(Body *bodies, int N, int step)
{
    char filename[100];
    sprintf(filename,"frame_%04d.dat",step);

    FILE *f = fopen(filename,"w");

    for(int i=0;i<N;i++)
        fprintf(f,"%lf %lf %lf\n",
                bodies[i].x,
                bodies[i].y,
                bodies[i].z);

    fclose(f);
}
