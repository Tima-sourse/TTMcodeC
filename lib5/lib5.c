#include <stdio.h>
#include <malloc.h>
#include <windows.h>
#include "act.c"

int main() 
{
    SetConsoleOutputCP(CP_UTF8);
    int n, i, j;
    char act;
    printf("Введите порядок матриц: ");
    scanf("%d", &n);
    
    double **a = (double **)malloc(n * sizeof(double));
    double **b = (double **)malloc(n * sizeof(double));
    for(int i = 0; i < n; i++)
    {
        a[i] = (double *)malloc(n*sizeof(double));
        b[i] = (double *)malloc(n*sizeof(double));
    }
    if (a == NULL || b == NULL)
    {
        printf("Ошибка выделения памяти\n");
        return 1;
    }
    printf("\nВведите элементы матрицы A:\n");
    for (i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf(" %lf", &a[i][j]);
        }
        printf("--\n");
    }
    getchar();

    printf("\nВведите элементы матрицы B:\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf(" %lf", &b[i][j]);
        }
        printf("--\n");
    }    
    getchar();

    printf("\nЭлементы массива A:\n");
    for (i = 0; i < n; i++)
    {   
        printf("|");
        for (j = 0; j < n; j++)
        {
            printf(" %5.lf |", a[i][j]);
        } 
        printf("\n");
    } 
    
    printf("\nЭлементы массива B:\n");
    for (i = 0; i < n; i++)
    {
        printf("|");
        for (j = 0; j < n; j++)
        {
            printf(" %5.lf |", b[i][j]);
        } 
        printf("\n");
    } 
    printf("\nВведите знак операции: ");
    scanf("%c", &act);
    double **res;
    switch (act)
    {
        case '+': 
            res = sum(n, a, b); 
            printf("\nСумма матриц:\n");
            for(int i = 0; i < n; i++)
            {
                printf("|");
                for(int j = 0; j < n; j++)
                {
                    printf(" %5.lf |", res[i][j]);
                }
                printf("\n");
            }
            break;

        case '-':
            res = diff(n, a, b);
            printf("\nРазность матриц:\n");
            for(int i = 0; i < n; i++)
            {
                printf("|");
                for(int j = 0; j < n; j++)
                {
                    printf(" %5.lf |", res[i][j]);
                }
                printf("\n");
            }
            break;
        case '*':

            res = mult(n, a, b);
            printf("\nПроизведение матриц:\n");
            for(int i = 0; i < n; i++)
            {   
                printf("|");
                for(int j = 0; j < n; j++)
                {
                    printf(" %5.lf |", res[i][j]);
                }
                printf("\n");
            } break;

        default: 
            printf("Неверный знак действия\n"); 
            break;
        }

    for (i = 0; i < n; i++)
    {
        free(a[i]); 
        free(b[i]); 
        free(res[i]);
    }
    free(a); 
    free(b); 
    free(res);
    
    getchar(); getchar();
    
    return 0;
}