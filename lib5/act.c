#include <malloc.h>

double* sum(int n, double* a, double* b)
{
    double* sum = (double*)malloc(n * n * sizeof(double));
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            *(sum + i * n + j) = *(a + i * n + j) + *(b + i * n + j);
        }
    }
    return sum;
}

double* diff(int n, double* a, double* b)
{
    double* diff = (double*)malloc(n * n * sizeof(double));
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            *(diff + i * n + j) = *(a + i * n + j) - *(b + i * n + j);
        }
    }
    return diff;
}
double* mult(int n, double *a, double *b)
{
    double *mult = (double *)malloc(n * n * sizeof(double));
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            
            for(int k = 0; k < n; k++)
            {
                *(mult + i * n + j) += (*(a + i * n + j)) * (*(b + i * n + j));
            }
        }
    }
    return mult;
}