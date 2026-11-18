#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <omp.h>

#define N 3600
#define BS 64

double A[N][N], B[N][N], C[N][N];

int main() {

    srand(time(NULL));

    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++){
            A[i][j] = (double)rand()/RAND_MAX;
            B[i][j] = (double)rand()/RAND_MAX;
            C[i][j] = 0.0;
        }

    double start = omp_get_wtime();

    #pragma omp parallel for collapse(2)
    for(int ii=0; ii<N; ii+=BS)       //Modified the loop with loop tiling
      for(int jj=0; jj<N; jj+=BS)
        for(int kk=0; kk<N; kk+=BS)
		for(int i=ii;i<ii+BS;i++)
		  for(int j=jj;j<jj+BS;j++)
		    for(int k=kk;k<kk+BS;k++)
    			C[i][j] += A[i][k] * B[k][j];

    double end = omp_get_wtime();

    printf("Execution time: %f seconds\n", end-start);

    return 0;
}
