#include "stdio.h"  // for printf
#include "stdlib.h" // for number conversion
#include "time.h"   // for time
#include "math.h" // for pow
int matmul(double **A, double **B, double ***C, int n)
{
	int i,j,k;
	for (i=0; i<n; i=i+1)
	{
		for (j=0; j<n; j=j+1)
		{
			(*C)[i][j] = 0.0;
			for (k=0; k<n; k=k+1)
			{
				(*C)[i][j] += A[i][k] * B[k][j]; 
			}
		}
	}
	return 0;
}

int init(double ***A, int n)
{
	int i;
	*A = (double **)malloc(n*sizeof(double*));
	for (i=0; i<n; i++)
	{
		(*A)[i] = (double *)malloc(n*sizeof(double));
	}
	return 0;
}

int fill(double ***A, double ***B, int n)
{
	int i,j;
	for (i=0; i<n; i++)
	{
		for (j=0; j<n; j++)
		{
			(*A)[i][j] = (rand() % (int)pow(10,4))/pow(10,4);
			(*B)[i][j] = (rand() % (int)pow(10,4))/pow(10,4);
		}
	}
	return 0;
}

int disp(double **A, int n)
{
	int i, j;
	printf("\n");
	for (i=0; i<n; i++)
	{
		for (j=0; j<n; j++)
		{
			printf("%f ", A[i][j]);
		}
		printf("\n");
	}
	return 0;
}

int main(int argc, char *argv[])
{
	int i, n;
	double **A, **B, **C;
	clock_t t;
	srand(time(NULL));
	n = atoi(argv[1]);
	// filling matrices
	t = clock();
	init(&A, n);
	init(&B, n);
	init(&C, n);
	fill(&A, &B, n);
	t = clock() - t;
	printf("time: %f\n", ((double)t)/CLOCKS_PER_SEC);
	// product 
	t = clock();
	matmul(A, B, &C, n);
	t = clock() - t;
	printf("time: %f\n", ((double)t)/CLOCKS_PER_SEC);
	// disp(A,n);
	// disp(B,n);
	// disp(C,n);
	return 0;
}
