#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 3600

double A[N][N], B[N][N], C[N][N];

int main() {

    srand(time(NULL));

    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++){
            A[i][j] = (double)rand()/RAND_MAX;
            B[i][j] = (double)rand()/RAND_MAX;
            C[i][j] = 0.0;
        }

    clock_t start = clock();

    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
            for(int k=0;k<N;k++)
                C[i][j] += A[i][k] * B[k][j];

    clock_t end = clock();

    double time = (double)(end-start)/CLOCKS_PER_SEC;
    printf("Execution time: %f seconds\n", time);

    return 0;
}
