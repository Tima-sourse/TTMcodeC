#include <stdio.h>
#include <windows.h>
#include <malloc.h>

double *matrx1;
double *matrx2;
int n, i, j;

int main()
{
    SetConsoleOutputCP(CP_UTF8);
    matrx1 = (double*)malloc(n*n * sizeof(double));
    matrx2 = (double*)malloc(n*n * sizeof(double));

    printf("\nВведите элементы первой матрицы построчно:\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%lf", (matrx1+i*n+j));
        }
        printf("--\n");
    }

    printf("\nВведите элементы второй матрицы построчно:\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%lf", (matrx1+i*n+j));
        }
        printf("--\n");
    }
    return 0;
}