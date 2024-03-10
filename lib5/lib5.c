#include <stdio.h>
#include <malloc.h>

int main()
{
    double* a;
    double* b;
    int i, j, n;
    printf("Введите порядок матриц: ");
    scanf("%d", &n);
    printf("\n");
    
    a = (double*)malloc(n * n * sizeof(double));
    b = (double*)malloc(n * n * sizeof(double));
    
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
    
    free(a);
    getchar();  getchar();
    return 0;
}
