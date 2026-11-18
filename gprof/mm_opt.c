#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 2000

double A[N][N];
double B[N][N];
double C[N][N];

/* Generate matrices */
void generate_data()
{
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            A[i][j] = rand()%100;
            B[i][j] = rand()%100;
        }
    }
}

/* Normalize matrix */
void normalize_matrix(double M[N][N])
{
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            M[i][j] = M[i][j] / 100.0;
        }
    }
}

/* Heavy computation: matrix multiplication (naive) */
void matrix_multiply()
{
    for(int i=0;i<N;i++)
    {
        for(int k=0;k<N;k++)
        {
            double temp = A[i][k];

            for(int j=0;j<N;j++)
            {
                C[i][j] += temp * B[k][j];
            }
        }
    }
}

/* Compute statistics */
double compute_statistics()
{
    double sum = 0;

    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            sum += C[i][j];
        }
    }

    return sum/(N*N);
}

int main()
{
    clock_t start,end;

    start = clock();

    generate_data();

    normalize_matrix(A);
    normalize_matrix(B);

    matrix_multiply();

    double avg = compute_statistics();

    printf("Average value: %f\n",avg);

    end = clock();

    printf("Execution time: %f seconds\n",
           ((double)(end-start))/CLOCKS_PER_SEC);

    return 0;
}
