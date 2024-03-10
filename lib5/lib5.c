#include <stdio.h>
#include <malloc.h>

int main()
{
    double* a;
    int i, j, n;
    printf("Введите порядок матрицы - ");
    scanf("%d", &n);
    
    a = (double*)malloc(n * n * sizeof(double));
  
    printf("Введите элементы матрицы построчно:\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%lf", (a + i * n + j));
        }
    printf("--\n");
    }
  
    printf("\nМатрица:\n");
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
