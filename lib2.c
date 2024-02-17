#include <stdio.h>
#include <math.h>
#include <windows.h>
#include <conio.h>
void main()
{
    SetConsoleOutputCP(CP_UTF8);
    int m = 3, n = 2, i, j, k;
    int mat2[n][n], square[n][n];
    double mat1[m][m], sum1 = 0, sum2 = 0;

    printf("Найти диагонали матрицы 3х3:\n");
    printf("Введите элементы матрицы построчно:\n");
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < m; j++)
        {
            scanf("%lf", &mat1[i][j]);
        }
        printf("--\n");
    }

    printf("\nМатрица 3х3:\n");
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < m; j++)
        {
            printf("%lf ", mat1[i][j]);
        }
        printf("\n");
    }

    printf("\n");
    for (i = 0; i < m; i++)
    {
        sum1 += mat1[i][i];
    }
    printf("Сумма главной диагонали - %lf", sum1);

    printf("\n");
    for (i = 0; i < m; i++)
    {
        sum2 += mat1[i][m-1-i];
    }
    printf("Сумма побочной диагонали - %lf", sum2);

    printf("\n\n###\n\nНайти квадрат матрицы 2х2:");
    printf("\nВведите элементы матрицы построчно:\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &mat2[i][j]);
        }
        printf("--\n");
    }

    printf("\nМатрица 2х2:\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("%d ", mat2[i][j]);
        }
        printf("\n");
    }

    printf("\nКвадрат матрицы:\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            square[i][j] = 0;
            for (k = 0; k < n; k++)
            {
                square[i][j] += mat2[i][k] * mat2[k][j];
            }
            printf("%d ", square[i][j]);
        }
        printf("\n");
    }
    _getch();
}