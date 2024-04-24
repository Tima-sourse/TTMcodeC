#include <stdarg.h>


double sum_f(int n, ...) 
{   
    double sum = 0.0;
    va_list fun;
    va_start(fun, n);
    for(int i = 0; i < n; i++)
    {
        sum += va_arg(fun, double);    
    }
    va_end(fun);
    return sum;
}

double max_f(int n, ...) 
{   
    double max = 0.0;
    va_list fun;
    va_start(fun, n);
    max = va_arg(fun, double);
    for(int i = 1; i < n; i++)
    {   
        double num = va_arg(fun, double);
        if (num > max)
        {
            max = num;
        }
    }
    va_end(fun);
    return max;
}

double min_f(int n, ...) 
{   
    double min = 0.0;
    va_list fun;
    va_start(fun, n);
    min = va_arg(fun, double);
    for(int i = 1; i < n; i++)
    {
        double num = va_arg(fun, double);
        if (num < min)
        {
            min = num;
        }
    }
    va_end(fun);
    return min;
}

double arith_f(int n, ...)
{
    double arith = 0.0;
    va_list fun;
    va_start(fun, n);
    for (int i = 0; i < n; i++)
    {
       arith += va_arg(fun, double); 
    }
    va_end(fun);
    return (arith/n);
}