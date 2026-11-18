#ifndef NBODY_H
#define NBODY_H

typedef struct
{
    double x,y,z;
    double vx,vy,vz;
    double mass;
} Body;

void initialize_bodies(Body *bodies, int N);
void compute_forces(Body *bodies, int N, double dt);
void update_positions(Body *bodies, int N, double dt);

#endif
