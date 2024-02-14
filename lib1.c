#include <stdio.h>
#include <math.h>
#include <conio.h>
#include <windows.h>
void main() 
{ 
    double a, b, c, x, x1, x2, d;
    int end=1;
    SetConsoleOutputCP(CP_UTF8);
    while (end!=0)
    {
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
            
        printf("\nЧтобы закрыть программу введите 0, или любую другую для продолжения\n>>");
        scanf("%d", &end);
        
    }
}
