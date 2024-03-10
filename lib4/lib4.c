#include <stdio.h>
#include <windows.h>
#include "fun.h"

double a, b, c, P, S, p;

int main()
{
    SetConsoleOutputCP(CP_UTF8);
    
    printf("Введите длины сторон черех пробел: \n");
    scanf("%lf %lf %lf", &a , &b , &c);
    
    if ((a + b > c) && (a + c > b) && (b + c > a))
    { 
        P = math1(a,b,c);
        printf("Периметр треугольника - %lf", P);

        printf("\n");

        S = math2(a,b,c);
        printf("Площадь треугольника - %lf", S);
    }
    else 
    {
        printf("Треугольник не существует");
    }
    return 0;
}