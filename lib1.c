#include <stdio.h>
#include <math.h>
#include <windows.h>
#include <conio.h>

void main() 
{ 
    double a, b, c, x, x1, x2, d;
    SetConsoleOutputCP(CP_UTF8);
    printf("Введите a: ");
    scanf("%lf", &a);
    printf("\nВведите b: ");
    scanf("%lf", &b);
    printf("\nвведите c: ");
    scanf("%lf", &c);

    d = pow(b,2) - 4*a*c;

    if (d < 0) 
        {printf("\nD < 0\nкоренй нет");}
    if (d > 0) 
        {x1=((-b+sqrt(d))/(2*a));
        x2=((-b-sqrt(d))/(2*a));
        printf("\nD > 0\nx1 = %lf x2 = %lf", x1,x2);}
    if (d == 0) 
        {x=((-b)/(2*a));
        printf("\nD=0\nx = %lf",x);}
    _getch();
}