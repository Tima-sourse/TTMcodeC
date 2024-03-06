#include <stdio.h>
#include <windows.h>

void main()
{
    SetConsoleOutputCP(CP_UTF8);
    int m, n = 2, i, j, k, end=1, go=0;
    double sum1 = 0, sum2 = 0;

    while (end!=0)
    {
        printf("Что нужно найти: 1-диагонали | 2-квадрат\n>> ");
        scanf("%d", &go);
        if (go == 1)
        {
            printf("Найти диагонали матрицы\n");
            printf("Какого порядка матрица - ");
            scanf("%d", &m);
            double mat1[m][m];
            
            printf("Введите элементы матрицы построчно:\n");
            for (i = 0; i < m; i++)
            {
                for (j = 0; j < m; j++)
                {
                    scanf("%lf", &mat1[i][j]);
                }
                printf("--\n");
            }

            printf("\nМатрица:\n");
            for (i = 0; i < m; i++)
            {   
                printf("|");
                for (j = 0; j < m; j++)
                {
                    printf(" %10.3lf |", mat1[i][j]);
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
        }

        if (go==2)
        {
            printf("Найти квадрат матрицы\n");
            printf("Какого порядка матрица - ");
            scanf("%d", &n);
            int mat2[n][n], square[n][n];
            printf("\nВведите элементы матрицы построчно:\n");
            for (i = 0; i < n; i++)
            {
                for (j = 0; j < n; j++)
                {
                    scanf("%d", &mat2[i][j]);
                }
                printf("--\n");
            }

            printf("\nМатрица:\n");
            for (i = 0; i < n; i++)
            {   
                printf("|");
                for (j = 0; j < n; j++)
                {
                    printf(" %10.d |", mat2[i][j]);
                }
                printf("\n");
            }

            printf("\nКвадрат матрицы:\n");
            for (i = 0; i < n; i++)
            {   
                printf("|");
                for (j = 0; j < n; j++)
                {
                    square[i][j] = 0;
                    for (k = 0; k < n; k++)
                    {
                        square[i][j] += mat2[i][k] * mat2[k][j];
                    }
                    printf(" %10.d |", square[i][j]);
                }
                printf("\n");
            }
        }
        printf("\n\nЧТобы сделать: 0-закрыть программу | любое другая цифра-повторить\n>> ");
        scanf("%d", &end);
    }
}