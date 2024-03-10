#include <malloc.h>

double** sum(int n, double **a, double **b)
{
    double **sum = (double **)malloc(n * sizeof(double));
    for(int i = 0; i < n; i++)
    {
        sum[i] = (double *)malloc(n*sizeof(double));
    }
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            sum[i][j] = a[i][j] + b[i][j];
        }
    }
    return sum;
}

double** diff(int n, double **a, double **b)
{
    double **diff = (double **)malloc(n * sizeof(double));
    for(int i = 0; i < n; i++)
    {
        diff[i] = (double *)malloc(n*sizeof(double));
    }
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            diff[i][j] = a[i][j] - b[i][j];
        }
    }
    return diff;
}
double** mult(int n, double **a, double **b)
{
    double **mult = (double **)malloc(n * sizeof(double));
    for(int i = 0; i < n; i++)
    {
        mult[i] = (double *)malloc(n*sizeof(double));
    }
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            mult[i][j] = 0;
            for(int k = 0; k < n; k++)
            {
                mult[i][j] += a[i][k] * b[k][j];
            }
        }
    }
    return mult;
}