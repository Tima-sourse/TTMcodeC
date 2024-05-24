#include <stdio.h>

int print_normal(int n);
int print_rev(int n);

int main()
{   
    int n;
    printf("Введите N - ");
    scanf("%d", &n);
    printf("Число в нормальном порядке - ");
    print_normal(n);
    printf("\nЧисло в обратном порядке - ");
    print_rev(n);
    return 0;
}

int print_normal(int n)
{
    if (n == 0)
    {
        return 0;
    }
    else
    {
        int m = n % 10;
        print_normal(n/10);
        printf("%d ", m);
    }
    return 0;
}

int print_rev(int n)
{
    if (n == 0)
    {
        return 0;
    }
    else
    {
        int m = n % 10;
        printf("%d ", m);
        print_rev(n/10);
    }
    return 0;
}