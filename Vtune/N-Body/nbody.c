#include <math.h>
#include <stdlib.h>
#include <omp.h>
#include "nbody.h"

#define SOFTENING 1e-9

void initialize_bodies(Body *bodies, int N)
{
    for(int i=0;i<N;i++)
    {
        bodies[i].x = drand48()*100;
        bodies[i].y = drand48()*100;
        bodies[i].z = drand48()*100;

        bodies[i].vx = 0.0;
        bodies[i].vy = 0.0;
        bodies[i].vz = 0.0;

        bodies[i].mass = 1.0;
    }
}

void compute_forces(Body *bodies, int N, double dt)
{
    for(int i=0;i<N;i++)
    {
        double fx=0.0;
        double fy=0.0;
        double fz=0.0;

        for(int j=0;j<N;j++)
        {
            if(i==j) continue;

            double dx = bodies[j].x - bodies[i].x;
            double dy = bodies[j].y - bodies[i].y;
            double dz = bodies[j].z - bodies[i].z;

            double distSqr = dx*dx + dy*dy + dz*dz + SOFTENING;
            double invDist = 1.0/sqrt(distSqr);
            double invDist3 = invDist*invDist*invDist;

            double F = bodies[j].mass * invDist3;

            fx += dx*F;
            fy += dy*F;
            fz += dz*F;
        }

        bodies[i].vx += dt*fx;
        bodies[i].vy += dt*fy;
        bodies[i].vz += dt*fz;
    }
}

void update_positions(Body *bodies, int N, double dt)
{
#pragma omp parallel for
    for(int i=0;i<N;i++)
    {
        bodies[i].x += bodies[i].vx*dt;
        bodies[i].y += bodies[i].vy*dt;
        bodies[i].z += bodies[i].vz*dt;
    }
}
