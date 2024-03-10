#include <stdio.h>
#include <malloc.h>
#include <windows.h>
#include "act.c"
#include <stdlib.h>

int main()
{
    SetConsoleOutputCP(CP_UTF8);
    double* a;
    double* b;
    int i, j, n;
    char act;
    printf("Введите порядок матриц: ");
    scanf("%d", &n);
    printf("\n");
    
    a = (double*)malloc(n * n * sizeof(double));
    b = (double*)malloc(n * n * sizeof(double));
    if (a == NULL || b == NULL) 
    {
        printf("Ошибка выделения памяти\n");
        return 0;
    }

    printf("Введите элементы матрицы A построчно:\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%lf", (a + i * n + j));
        }
    printf("--\n");
    }
  
    printf("\nМатрица A:\n");
    for (i = 0; i < n; i++)
    {   
        printf("|");
        for (j = 0; j < n; j++)
        {
            printf(" %5.2lf |", *(a + i * n + j));
        }
    printf("\n");
    }
    
    printf("\nВведите элементы матрицы B построчно:\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%lf", (a + i * n + j));
        }
    printf("--\n");
    }
  
    printf("\nМатрица B:\n");
    for (i = 0; i < n; i++)
    {   
        printf("|");
        for (j = 0; j < n; j++)
        {
            printf(" %5.2lf |", *(a + i * n + j));
        }
    printf("\n");
    }
    
    printf("\nВведите знак операции |+|-|*|:\n");
    scanf("%c", &act);
    double *res;
    switch (act)
    {
        case '+':
            res = sum(n, a, b); 
            printf("Сумма матриц:\n");
            for (i = 0; i < n; i++) 
            {
                for (j = 0; j < n; j++) 
                {
                    printf(" %5.2lf |", *(a + i * n + j));
                }
                printf("\n");
            }
            break;
        case '-':
            res = diff(n, a, b);
            printf("Разность матриц:\n");
            for (i = 0; i < n; i++)
            {
                for (j = 0; j < n; j++)
                {
                    printf(" %5.2lf |", *(a + i * n + j));
                }
                printf("\n");
            }
            break;
        case '*':
            res = mult(n, a, b);
            printf("Произведение матриц:\n");
            for(i = 0; i < n; i++)
            {
                for(j = 0; j < n; j++)
                {
                    printf(" %5.2lf |", *(a + i * n + j));
                }
                printf("\n");
            } 
            break;
        default: 
            printf("Операция введена неправильно\n"); 
            break;
    }

    free(a);
    free(b);
    free(res);

    getchar();
    return 0;
}