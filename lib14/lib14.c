#include <stdio.h>
#include <setjmp.h>

int fibon(int n);
int sum_fibon(int n);

jmp_buf env;

int main()
{   
    int res, n;
    printf("Кол-во суммируемых чисел - ");
    scanf("%d", &n);

    if (n == 0)
    {
        res = 0;
    }
    else 
    {
        res = sum_fibon(n);
    }
    printf("\nСумма %d числе ряда равна - %d", n, res);
}

int fibon(int n)
{
    if (n < 1)
    {
        return 0;
    }
    else if (n == 1)
    {
        return 1;
    }
    else
    {
        return fibon(n - 1) + fibon(n - 2);
    }
}

int sum_fibon(int n)
{
    int i, sum=0, f = setjmp(env);
    if (f == 0)
    {
        for (i = 1; i <= n; i++)
        {
            sum = sum + fibon(i);
        }
        longjmp(env, sum);
    }
    return f;
}